#include<iostream>

//Overloading: �Լ��̸��� ���ƾ��Ѵ�(�̺κ��� overriding�� ����)
//�Լ��� �������� ���Ƶ� �ǰ� �޶� �ȴ�.
//�Ű������� ������ ���Ƶ� �ǰ�, �޶� �ȴ�.
//�㳪 �Ű������� ������ ���� ���, �ڷ����� �޶�� overloading�� ������ �����Ѵ�.

void average(int a, int b) {
	int avg = 0;
	avg = (a + b) / 2;
	std::cout << "The average of integers " << a << " and " << b << " is " << avg << ".\n";
}

//�� �Լ��� overload�� �Լ�
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