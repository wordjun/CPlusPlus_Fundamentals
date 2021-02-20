#include<iostream>
using namespace std;

int Adder(const int& num1, const int& num2) {
	return num1 + num2;
}

int main() {
	const int a = 20;
	//int& ref = num;//상수화된 변수는 어떠한 경로를 통해서라도 값의변경을 허용해선 안된다.
	const int& ref1 = a;//ref를 통한 값의 변경이 불가능하다는 const 선언을 통해 상수화에 대한 문제점은 발생하지 않는다.
	//또, const 참조자는 다음과 같이 상수도 참조가 가능함.
	const int& ref2 = 50;//변수만 참조가 가능하다고 했었는데, const선언에 의해 만들어진 변수를 가리켜 '상수화된 변수'라고 한다. 본래 상수가 아니라 변수를 상수화시킨것으로 정의하기 때문.

	int n = 20 + 30;//20과 30처럼, 프로그램상에서 표현되는 숫자를 가리켜 literal또는 literal constant라고 부른다.
	//이들은 임시적으로 존재하는 값이며, 다음 행으로 넘어가면 존재하지 않는 상수다.
	//산술연산을 위해선 20과 30 모두 메모리공간에 저장되어야 한다. 그러나 저장됐다고 해서 재참조가 가능한 값은 아니다.
	//const int& ref=30;
	//위 선언문은 숫자 30이 메모리공간에 계속 남아있을 때나 성립이 가능한 문장이다. 따라서 C++에선 위 문장이 성립할수 있도록 const참조자를 이용해
	//상수를 참조할때 임시변수란 것을 만든다. 그리고 이 장소에 상수 30을 저장하고선 참조자가 이 임시변수를 참조하게끔 한다.

	//const참조자의 상수참조를 통해 다음과 같은 형태의 함수호출이 가능하다.
	cout << Adder(3, 4) << '\n';


	//문제 02-2
	const int num = 12;
	//포인터 변수를 선언하여 위 변수를 가리키게 한다
	const int* ptr = &num;
	//위 포인터변수를 참조하는 참조자 선언
	const int* (&ref3) = ptr;
	//이렇게 선언된 포인터변수 및 참조자를 이용하여 num에 저장된 값을 출력
	cout << *ref3 << '\n';//값 사용시엔* 로 접근.
	

	const int& ref4 = *ptr;
	cout << ref4 << '\n';
	return 0;
}