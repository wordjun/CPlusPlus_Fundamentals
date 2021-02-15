#include<iostream>
using namespace std;

struct _tagStudent {
	int stdId;
	int English;
	int Mathematics;
	int Science;
};

int main() {
	//�Ϲ� ����-�Ϲ����� ���� ����
	//������: (�ٸ� ������)�޸��ּҸ� ����
	//��� ����Ÿ���� ������Ÿ���� ������ �� ����.
	//x86���� ���� �� 4byte, x64�� ���� �� 8byte�� ����
	//�����ʹ� ������ �ƹ��ϵ� �� �� ����.

	int num = 100;
	/*
	������ ������ ���� �� �տ� ��(*)�� �ٿ��ش�.
	���� �տ� ampersand(&)�� ���̸� �ش� ������ �޸��ּҰ� �ȴ�
	p�� num������ �޸� �ּҸ� ������ ���� �ȴ�.(&num)
	���� p�� �̿��� num�� ���� ������ �� �ְ� �ȴ�.
	*/
	int* p = &num;

	/*cout << sizeof(int*) << '\n';
	cout << sizeof(char*) << '\n';
	cout << sizeof(double) << '\n';*/

	
	

	cout << *p << '\n';
	cout << p << '\n';
	cout << &p << '\n';

	//������: �����ͺ��� �տ� *�� �ٿ� ���
	*p = 1234;
	cout << num << '\n';
	cout << &num << '\n';
	cout << "============" << '\n';
	/*
	�����Ϳ� �迭�� ����: �迭���� ������.
	*/
	int arr[10] = {
		1, 2, 3, 
		4, 5, 6, 
		7, 8, 9};
	
	
	int* pB = arr;
	cout << arr << '\n';//�迭�� ��ü(arr)�� �޸𸮿����� �迭�� ù �޸� �ּҰ� �ȴ�
	cout << pB << '\n';//�����ͺ��� pB�� �迭 arr�� ù��° �޸��ּҰ��� ���´�
	cout << &arr[0] << '\n';//arr�� ù��° �޸� �ּҰ�

	cout << &pB[2] << '\n';//�����ͺ��� pB�� ����° �޸��ּҰ�
	cout << pB + 2 << '\n';//�����ͺ��� pB�� +2������ �� ��

	cout << *(pB + 2) << '\n';//(pB+2)��� �޸��ּҿ� ����ִ� ���� ������(*)
	cout << *pB + 3 << '\n';

	//���������� const�Ӽ��� ���´�
	const char *pStr = "Test String";
	cout << pStr << '\n';
	cout << (int*)pStr << '\n';

	pStr = "abcd";
	cout << pStr << '\n';
	cout << (int*)pStr << '\n';

	pStr = "abcd";//���� ���ڿ� ��� �� ���������� �迭�� ��� �޸� ������ ����,
	cout << pStr << '\n';
	cout << (int*)pStr << '\n';

	pStr = "abcdefgh";//�ٸ� ���ڿ� ��� �� ���������� �迭�� ��� �޸� ������ �޶�����
	//abcd�� ���� �ٸ� ���ڿ��̹Ƿ� �ٸ� �޸𸮰����� �Ҵ��(�� ���ڿ����� ����ּҰ� ����)
	cout << pStr << '\n';
	cout << (int*)pStr << '\n';

	pStr = "Test String";
	cout << pStr << '\n';
	cout << (int*)pStr << '\n';

	char str[8] = "abcdefg";
	cout << str << '\n';
	cout << &str << '\n';
	cout << (int*)str << '\n';
	cout << (int*)&str[0] << '\n';


	//�������� ������ �����Ͻÿ�.
	//�����ʹ� �ٸ� ������ �޸��ּҰ��� ���� �ǰ�,
	//�ش� �޸��ּҸ� �˰� �ֱ� ������ �׿� �����Ͽ� ���� manipulate�� �� �ִ�.
	_tagStudent tStudent = {};
	tStudent.English = 100;
	cout << tStudent.English << '\n';

	_tagStudent* pStd = &tStudent;

	//������ �켱���������� .�� ���� �ν�
	//�޸��ּ�.�� �߸��� ���� -> *pStd�� ��ȣ�� ������ �Ŀ� .�� �̿��� ������� ����
	pStd->English = 50;
	cout << pStd->English << '\n';
	cout << (*pStd).English << '\n';
	cout << &pStd->English << '\n';
	//����ü �����ʹ� ��������� ���� ���� �����Ѵ�.

	//void pointer: no type.
	//int *pStd2 = &tStudent;
	//void�� ������Ÿ���� Ȱ���� �� �ְ� ��
	//�� ��� Ÿ���� �޸� �ּҵ� ��� ���尡�� (void*)
	void* pStd2 = &tStudent.English;
	//��, ������ �Ұ�, �޸��ּҸ� ���尡��
	cout << pStd2 << '\n';
	//cout << *pStd2 << '\n';
	//�������� �Ұ����ϱ⶧����(*pStd2 ���Ұ�) Ÿ������ȯ�� ���� ���� �����Ѵ�
	int* pConvert = (int*)pStd2;
	*pConvert = 1000001;
	//Ȥ�� ������ ���� ���氡��
	*((int*)pStd2) = 101;
	cout << tStudent.English << '\n';

	int a1= 1111;
	int a2 = 2222;
	int* p = &a2;
	//��������Ÿ: *�� 2�� ����.
	//�Ϲ� �����ͺ���: �Ϲ� ������ �޸𸮺����� �����ϴ� ����
	//����������: �������� ������. �� �����ͺ����� �޸��ּҸ� �����ϴ� ������
	int** pp = &p;
	*p = 1234;
	cout << a2 << '\n';
	cout << &a2 << '\n';
	cout << *p << '\n';//*�� �ٿ� �������ϸ� �ش� �����Ͱ� ����Ű�� �ִ� �޸��ּ��� ����� ��/
	cout << p << '\n';
	cout << &p << '\n';
	cout << **pp << '\n';//���������� ���� **�� ���� �������ϰ� �Ǹ� ����Ű�� ����� ��
	cout << *pp << '\n';
	cout << pp << '\n';
	cout << &pp << '\n';
	return 0;
}