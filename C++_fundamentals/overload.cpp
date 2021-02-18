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

//��ȯ���� �Լ�ȣ�� �� ȣ��Ǵ� �Լ��� �����ϴ� ������ �� �� ����.
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

	//�Լ�ȣ�� �� ���޵Ǵ� ����(�Ű�����)�� ���� ȣ���ϰ��� �ϴ� �Լ��� ������ �����ϹǷ�
	//�Ű������� ��������(�ڷ���)�� �ٸ��ٸ� ������ �̸��� �Լ����Ǹ� ����Ѵ�. �̸� �Լ� �����ε�(����)�̶� ��.
	//��, �Լ� �����ε��� ���ؼ� �ݵ�� �Ű������� ������ �޶�� �Ѵ�.
	//�Ű������� �ڷ����� �޶�� ���������� �ڷ����� ���� ȣ���� �Լ��� ������ ����������.
	//�Ű������� ������ �޶� ���޵Ǵ� ������ ������ ���� ȣ���� �Լ� ������ �����Ѱ�.
	//��, �Ű������� �ڷ��� �Ǵ� ������ �ٸ��� ��� ������ �����ؾ� �����ε��� �����ϴ�.

	//C++�� ȣ���� �Լ��� ã���� �Լ��� �̸��� �Ű������� ������ ���ÿ� Ȱ����.
	//�̿� ���� C���� �Լ��� �̸��� �̿��Ͽ� ȣ������ ã�⶧���� �Լ��̸��� �ߺ��� ������� �ʴ°��̴�.
	
	myFunc();
	myFunc('A');
	myFunc(3, 7);
	int n1 = 20, n2 = 30;
	swap(&n1, &n2);
	std::cout << n1 << ' ' << n2 << '\n';
	return 0;
}