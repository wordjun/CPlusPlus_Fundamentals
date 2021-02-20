#include<iostream>
using namespace std;

int& refRetFuncOne(int& ref) {
	ref++;
	return ref;
	//여기서 ref는 지역변수와 동일한 성격을 가짐(refRetFuncOne이 리턴하면, 참조자 ref는 소멸됨)
}

int refRetFuncTwo(int& ref) {
	ref++;
	return ref;
}

int& refRetFuncThree(int n) {
	int num = 10;//지역변수 num에 저장된 값을 반환하지 않고 num을 참조형태로 반환하고 있다(함수리턴형이 참조형)
	num += n;
	return num;
}

int main() {
	//case 1: 함수의 리턴값을 참조자에 저장
	int num1 = 1;
	int& num2 = refRetFuncOne(num1);
	num1++;
	num2 += 101;
	cout << num1 << ' ' << num2 << '\n';
	//참조형으로 반환된 값을 참조자(num2)에 저장하면, 참조의 관계가 하나 더 추가됨
	//즉 다음과 동일하게 된다
	/*
	int num1 = 1;
	int &ref = num1;//인자 전달과정에서 일어남
	int &num2 = ref;//함수의 반환과 반환값의 저장에서 일어남

	따라서 num1과 num2는 같은 변수임을 알 수 있다(num2가 num1을 참조)
	*/

	//case 2: 함수의 리턴값을 일반 int형 변수에 저장
	int num3 = 5;
	int num4 = refRetFuncOne(num3);//여기서 참조형으로 반환되지만 이렇듯 참조자가 아닌 일반변수를 선언해서 반환값을 저장할 수 있다
	
	num3++;
	num4 += 101;
	cout << num3 << ' ' << num4 << '\n';
	//num3와 num4는 별개의 변수임을 알 수 있다

	//반환형이 참조자인 경우, 그 리턴값을 무엇으로 저장하느냐(일반변수 or 참조자)에 따라 그 결과에 차이가 있다

	int num5 = 20;
	int num6 = refRetFuncTwo(num5);

	num5++;
	num6 += 101;
	cout << num5 << ' ' << num6 << '\n';

	//refRetFuncOne은 리턴형이 참조자라서 그 리턴값을 일반변수 혹은 참조자에 저장할 수 있는 반면,
	//refRetFuncTwo은 리턴형이 기본자료형이라 그 리턴값은 상수이므로 반드시 변수에 저장해야 한다
	//따라서 int &num6 = refRetFuncTwo(num5)와 같은 선언문은 실행이 불가하다


	int& ref = refRetFuncThree(20);//지역변수num에 ref라는 또다른 이름이 붙게 됨
	//함수가 리턴되면 정작 지역변수 num은 소멸이 되므로, 위 함수처럼 지역변수를 참조형으로 반환하는 일이 있어선 안된다(없어진 지역변수에 대한 참조값은 찌꺼기다)

}