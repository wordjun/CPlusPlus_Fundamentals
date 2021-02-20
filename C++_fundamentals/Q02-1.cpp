#include<iostream>
using namespace std;

void addOne(int& num) {
	num++;
}

void changeSign(int& num) {
	num *= -1;
}

void swapPointer(int*(& ref1), int*(& ref2)) {//포인터변수의 참조자를 매개변수로 선언
	//int temp = *ref1;//값 사용시엔 *로 접근.
	//*ref1 = *ref2;
	//*ref2 = temp;

	//답안
	int* temp = ref1;
	ref1 = ref2;
	ref2 = temp;
}

void func(int& ref1, int& ref2) {
	ref1++;
	ref2 += 2;
}

int main() {
	int val = 0;
	cout << val << '\n';
	addOne(val);
	cout << val << '\n';
	changeSign(val);
	cout << val << '\n';

	int n1 = 5, n2 = 10;
	int* ptr1 = &n1, * ptr2 = &n2;
	cout << *ptr1 << ' ' << *ptr2 << '\n';
	cout << ptr1 << ' ' << ptr2 << '\n';
	swapPointer(ptr1, ptr2);//인자로 포인터의 주소값을 전달
	//int *(&ref1) = ptr1, *(&ref2) = ptr2
	cout << *ptr1 << ' ' << *ptr2 << '\n';


	int a = 5, b = 7;
	func(a, b);//int &ref1 = a, &ref2 = b
	//func함수의 ref1은 a를 참조하고, ref2는 b를 참조한다
	cout << a << ' ' << b << '\n';
}