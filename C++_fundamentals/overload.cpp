#include<iostream>

//Overloading: 함수이름이 같아야한다(이부분은 overriding과 동일)
//함수의 리턴형이 같아도 되고 달라도 된다.
//매개변수의 개수가 같아도 되고, 달라도 된다.
//허나 매개변수의 개수가 같을 경우, 자료형이 달라야 overloading의 조건을 만족한다.

void average(int a, int b) {
	int avg = 0;
	avg = (a + b) / 2;
	std::cout << "The average of integers " << a << " and " << b << " is " << avg << ".\n";
}

//위 함수를 overload한 함수
void average(float a, float b) {
	float avg = 0;
	avg = (a + b) / 2;
	std::cout << "The average of floats " << a << " and " << b << " is " << avg << ".\n";
}

//반환형은 함수호출 시 호출되는 함수를 구분하는 기준이 될 수 없다.
//"cannot overload functions distinguished by return type alone."
//void myFunc(int n) {
//
//}
//
//int myFunc(int n) {
//
//}

void myFunc(void) {
	std::cout << "myFunc(void) called.\n";
}

void myFunc(char c) {
	std::cout << "myFunc(char c) called.\n";
}

void myFunc(int a, int b) {
	std::cout << "myFunc(int a, int b) called.\n";
}

void swap(int *n1, int *n2) {
	int temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

int main() {
	average(10, 20);
	average(22.1f, 45.7f);

	//함수호출 시 전달되는 인자(매개변수)를 통해 호출하고자 하는 함수의 구분이 가능하므로
	//매개변수의 선언형태(자료형)가 다르다면 동일한 이름의 함수정의를 허용한다. 이를 함수 오버로딩(과적)이라 함.
	//단, 함수 오버로딩을 위해선 반드시 매개변수의 선언이 달라야 한다.
	//매개변수의 자료형이 달라야 전달인자의 자료형을 통해 호출할 함수의 구분이 가능해진다.
	//매개변수의 개수가 달라도 전달되는 인자의 개수를 통해 호출할 함수 구분이 가능한것.
	//즉, 매개변수의 자료형 또는 개수가 다르다 라는 조건을 만족해야 오버로딩이 가능하다.

	//C++은 호출할 함수를 찾을때 함수의 이름과 매개변수의 선언을 동시에 활용함.
	//이에 비해 C언어는 함수의 이름만 이용하여 호출대상을 찾기때문에 함수이름의 중복을 허용하지 않는것이다.
	
	myFunc();
	myFunc('A');
	myFunc(3, 7);
	int n1 = 20, n2 = 30;
	swap(&n1, &n2);
	std::cout << n1 << ' ' << n2 << '\n';
	return 0;
}