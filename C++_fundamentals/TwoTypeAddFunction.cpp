#include<iostream>
using namespace std;

template<typename T>
T Add(T num1, T num2) {
	cout << "T Add(T num1, T num2)\n";
	return num1 + num2;
}

int Add(int num1, int num2) {
	cout << "Add(int num1, int num2)\n";
	return num1 + num2;
}

double Add(double num1, double num2) {
	cout << "Add(double num1, double num2)\n";
	return num1 + num2;
}

int main() {
	cout << Add(5, 7)<<'\n';//�Ϲ��Լ��� ���ǵǾ� �����Ƿ� �Ϲ��Լ� ȣ��
	cout << Add(3.7, 7.5) << '\n';
	cout << Add<int>(5, 7) << '\n';//<>�� ���� ���ø��Լ��� ȣ���� ���
	cout << Add < double>(4.2, 1.1) << '\n';
}	
