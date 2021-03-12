#include<iostream>
using namespace std;

template <typename T>
T Add(T num1, T num2) {//대상 자료형이 정해져있지 않고, 함수 사용시 컴파일러가 결정한다
	return num1 + num2;
}

int main() {
	cout << Add<int>(15, 20) << '\n';//<>안의 int는 T를 int로 치환하여 만들어진 Add함수를 호출한다는 뜻
	//컴파일러는 위 문장을 보고나서 Add함수의 모든 'T'들을 int로 바꾸어 함수를 하나 생성한다.
	//(단, 한 번 생성된 함수는 그 다음엔 이미 만들어진 함수를 호출할뿐, 새로 만들지 않는다.(함수는 자료형 당 하나씩만)
	//그리고 인자로 15, 20을 넘겨 함수를 호출한다.
	cout << Add<double>(21.4, 31.9) << '\n';
}
