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

int main() {
	average(10, 20);
	average(22.1f, 45.7f);
	return 0;
}