#include<iostream>
using namespace std;

void addOne(int& num) {
	num++;
}

void changeSign(int& num) {
	num *= -1;
}

void swapPointer(int*(& ref1), int*(& ref2)) {//�����ͺ����� �����ڸ� �Ű������� ����
	//int temp = *ref1;//�� ���ÿ� *�� ����.
	//*ref1 = *ref2;
	//*ref2 = temp;

	//���
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
	swapPointer(ptr1, ptr2);//���ڷ� �������� �ּҰ��� ����
	//int *(&ref1) = ptr1, *(&ref2) = ptr2
	cout << *ptr1 << ' ' << *ptr2 << '\n';


	int a = 5, b = 7;
	func(a, b);//int &ref1 = a, &ref2 = b
	//func�Լ��� ref1�� a�� �����ϰ�, ref2�� b�� �����Ѵ�
	cout << a << ' ' << b << '\n';
}