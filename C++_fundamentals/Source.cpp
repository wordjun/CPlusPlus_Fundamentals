#include<iostream>
using namespace std;

int main() {
	//���� num�� ���ȭ
	const int num = 10;

	//������ ptr1�� �̿��� val1�� ���� ������ �� ����
	int val1 = 10, val2 = 20, val3 = 30;
	const int* ptr1 = &val1;
	ptr1 = &val2;
	//*ptr1 = 15;//"you cant assign to a variable that is const
	cout << *ptr1 << '\n';

	//������ ptr2�� ���ȭ��
	int* const ptr2 = &val2;
	//ptr2 = &val1;//"you cant assign to a variable that is const
	*ptr2 = 25;//�����͸� ���� �� ������ ����
	cout << *ptr2 << '\n';

	//������ ptr3�� ���ȭ������, ptr3�� �̿��� val3�� ���� �����Ҽ� ����
	const int* const ptr3 = &val3;
	//��� �Ұ���
	//ptr3 = &val1;
	//*ptr3 = 35;
}