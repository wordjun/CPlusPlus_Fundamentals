#include<iostream>
using namespace std;

int& refRetFuncOne(int& ref) {
	ref++;
	return ref;
	//���⼭ ref�� ���������� ������ ������ ����(refRetFuncOne�� �����ϸ�, ������ ref�� �Ҹ��)
}

int refRetFuncTwo(int& ref) {
	ref++;
	return ref;
}

int& refRetFuncThree(int n) {
	int num = 10;//�������� num�� ����� ���� ��ȯ���� �ʰ� num�� �������·� ��ȯ�ϰ� �ִ�(�Լ��������� ������)
	num += n;
	return num;
}

int main() {
	//case 1: �Լ��� ���ϰ��� �����ڿ� ����
	int num1 = 1;
	int& num2 = refRetFuncOne(num1);
	num1++;
	num2 += 101;
	cout << num1 << ' ' << num2 << '\n';
	//���������� ��ȯ�� ���� ������(num2)�� �����ϸ�, ������ ���谡 �ϳ� �� �߰���
	//�� ������ �����ϰ� �ȴ�
	/*
	int num1 = 1;
	int &ref = num1;//���� ���ް������� �Ͼ
	int &num2 = ref;//�Լ��� ��ȯ�� ��ȯ���� ���忡�� �Ͼ

	���� num1�� num2�� ���� �������� �� �� �ִ�(num2�� num1�� ����)
	*/

	//case 2: �Լ��� ���ϰ��� �Ϲ� int�� ������ ����
	int num3 = 5;
	int num4 = refRetFuncOne(num3);//���⼭ ���������� ��ȯ������ �̷��� �����ڰ� �ƴ� �Ϲݺ����� �����ؼ� ��ȯ���� ������ �� �ִ�
	
	num3++;
	num4 += 101;
	cout << num3 << ' ' << num4 << '\n';
	//num3�� num4�� ������ �������� �� �� �ִ�

	//��ȯ���� �������� ���, �� ���ϰ��� �������� �����ϴ���(�Ϲݺ��� or ������)�� ���� �� ����� ���̰� �ִ�

	int num5 = 20;
	int num6 = refRetFuncTwo(num5);

	num5++;
	num6 += 101;
	cout << num5 << ' ' << num6 << '\n';

	//refRetFuncOne�� �������� �����ڶ� �� ���ϰ��� �Ϲݺ��� Ȥ�� �����ڿ� ������ �� �ִ� �ݸ�,
	//refRetFuncTwo�� �������� �⺻�ڷ����̶� �� ���ϰ��� ����̹Ƿ� �ݵ�� ������ �����ؾ� �Ѵ�
	//���� int &num6 = refRetFuncTwo(num5)�� ���� ������ ������ �Ұ��ϴ�


	int& ref = refRetFuncThree(20);//��������num�� ref��� �Ǵٸ� �̸��� �ٰ� ��
	//�Լ��� ���ϵǸ� ���� �������� num�� �Ҹ��� �ǹǷ�, �� �Լ�ó�� ���������� ���������� ��ȯ�ϴ� ���� �־ �ȵȴ�(������ ���������� ���� �������� ����)

}