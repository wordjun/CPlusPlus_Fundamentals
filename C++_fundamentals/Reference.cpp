#include<iostream>
using namespace std;

//2���� ������ ���ڷ� �䱸.
//���� call-by-value ����� �Լ��̴�
//�׷��� call-by-value�� ���·� ���ǵ� �Լ� ���ο��� �Լ� �ܺο� ����� ������
//������ �Ұ�����.
int Adder(int n1, int n2) {
	return n1 + n2;
}

void swap(int n1, int n2) {
	int temp = n1;
	n1 = n2;
	n2 = temp;
}

//call-by-reference: 2���� �ּҰ��� ���ڷ� ����.
//�� �ּҰ��� �����ϴ� ������ ����� ���� ���� �����Ѵ�.
void swap(int* n1, int* n2) {
	int temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

void swapByRef(int& ref1, int& ref2) {
	int temp = ref1;//������ ref1�� main�Լ����� val1�� ����Ű�� �ֱ� ������ ref1�� val1�� ���� �����ϴ�
	ref1 = ref2;
	ref2 = temp;
}

//�����ڸ� �̿��� call-by-reference
	//c++������ �ּ��� �Լ��� ������ Ȯ���ؾ� ��. ���� ������ ����� �Լ����Ǹ� ���� ���ƾ� ��
	//const�� ����Ͽ� �̸� ������� �غ�����
void happyFunc(const int& ref) {
	//�ڵ�м��������� �Լ��� ȣ�⹮�常 ���� �Լ��� Ư���� ������� �Ǵ��� �� �־�� ��
	//�㳪 �������� ��� �Լ��� ������ Ȯ���ؾ� �ϰ�, �����ڰ� �Ű������� ���� ���ִٸ� �Լ��� ��ü���� ��������� Ȯ���ؾ� ��(�����ڸ� ���� �� ���� ����Ȯ��)
	//���� ������ �Ű����� �տ� const�� �ٿ��ָ� �ش� �Լ� ������ ������ ref�� �̿��� �������� �ʰڴٴ� �ǹ̸� �ο��Ѵ�.
	//ref = 20;

	//�Լ� ������ �����ڸ� ���� ���� ������ �������� ���� ��� �����ڸ� const�� �����Ͽ� �Լ��� ������ ���� �������� �̷����������� ����Ѵ�.
}

int main() {
	//�����ڴ� �ڽ��� �����ϴ� ������ ����� �� �ִ� �� �ϳ��� �̸�
	int num1 = 1020;
	int& num2 = num1;

	num2 = 3047;
	cout << "VAL: " << num1 << '\n';
	cout << "REF: " << num2 << '\n';

	//�ּ� ���� �����ϴ�
	cout << "VAL: " << &num1 << '\n';
	cout << "REF: " << &num2 << '\n';

	//�����ڴ� ������ ������θ� ������ �����ϴ�. ������ ������ �ϳ� �ٿ��ִ� ���̴�.
	//�׷��� ����� ���ÿ� ������ ������ �����ϵ��� �ؾ��Ѵ�
	//�������� ������ ������ ������ �����ڸ� ������ε� ������ ������ �����ϴ�.
	int n1 = 2759;
	int& n2 = n1;
	int& n3 = n1;

	int num = 12;
	int* ptr = &num;
	int** dptr = &ptr;
	cout << "num: " << num << ", &num: " << &num << '\n';
	cout << "*ptr: " << *ptr <<", ptr: "<<ptr<< ", &ptr: " << &ptr << '\n';
	cout << "**dptr: " << **dptr << ", *dptr: " << *dptr << ", dptr: " << dptr <<", &dptr: "<<&dptr<<'\n';

	int& ref = num;
	int* (&pref) = ptr;//������ ���� ptr�� �������̹Ƿ� ���� num�� ����� ���� ��µ�
	int** (&dpref) = dptr;//������ ���� dptr�� �������̹Ƿ� ���� num�� ����� ���� ��µ�.

	cout << ref << '\n';
	cout << *pref << '\n';
	cout << "pref: " << pref << ", &pref: " << &pref << '\n';
	cout << **dpref << '\n';
	cout << "*dpref: " << *dpref << ", dpref: " << dpref << ", &dpref: "<< &dpref<<'\n';

	//call by value & vall by reference
	int a = 1, b = 2;
	swap(a, b);//call by value
	cout << a << ' ' << b << '\n';
	swap(&a, &b);//call by reference
	cout << a << ' ' << b << '\n';


	int val1 = 10, val2 = 20;
	cout << val1 << ' ' << val2 << '\n';
	swapByRef(val1, val2);//�Ű������� �����ڰ� ��������� �� ���ڷ� ������ ����� �� ������ ������ �ȴ�
	cout << val1 << ' ' << val2 << '\n';

	
	int z = 24;
	happyFunc(z);
	cout << z << '\n';
	return 0;
}