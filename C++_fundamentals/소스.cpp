#include<iostream>
using namespace std;

int change_val(int* p) {
	*p = 3;
	return 0;
}

void change_val2(int& p) {
	p = 1;
}

int& function(int& a) {
	a = 5;
	return a;
}

int main() {
	//int number = 5;

	//cout << number << endl;
	//change_val(&number);
	//cout << number << '\n';


	////���۷���
	//int a = 3;
	//int& another_a = a;//a�� ������ another_a �ּҰ���
	////another_a�� a�� �����ڴ�. 
	////��, another_a�� a�� �Ǵٸ� �̸��̶�� �����Ϸ����� �˷��ִ� ��
	////���� another_a�� � �۾��� �����ϵ� ��ǻ� a�� ������ �۾��� �ϴ°Ͱ� ��������
	////��, ���۷����� ���� �� �ݵ�� ������ �������� ����ؾ���.
	////int &another_a;���� ���Ǵ� �Ұ�����. ���۷����� �� �� ������ �Ǹ� ����� �ٸ� ���� ������ �� �� ����
	//another_a = 5;
	//cout << "a: " << a << '\n';
	//cout << "another_a: " << another_a << '\n';

	//int a1 = 10;
	//int& another_a1 = a1;//another_a1�� a�� ������
	//int b = 3;
	//another_a1 = b;//another_a1�� ���� ������ a1�� ���� ������ �ϴ°Ͱ� ������. ���� a1 = b;�� ���� ȿ���� ��

	//int a = 10;
	//int* p = &a;//�����ʹ� �޸� �󿡼� 8����Ʈ������ ������.
	//int b = 3;
	//p = &b;//p�� a�� ������ b�� ����Ŵ

	//int& another_a = a;//another_A�� ���̴� �ڸ��� ��� a�� �ٲ�ġ���ϸ� �ǹǷ� �����Ҵ��� �ʿ����.

	//int a = 6;
	//cout << a << '\n';
	//change_val2(a);//p�� ���ǵǴ� ������ change_val2�� ȣ���� ���̹Ƿ� ��ǻ� int& p = a�� ����ȴٰ� ������ �� �ִ�.
	//cout << a << '\n';

	//int x;
	//int& y = x;//y�� x�� �Ǵٸ� ����
	//int& z = y;//z�� y�� �Ǵٸ� ����, �� x�� �Ǵٸ� ����
	//x = 1;
	//cout << x<<" " << y << " " << z << '\n';
	//y = 2;
	//cout << x << " " << y << " " << z << '\n';
	//z = 3;
	//cout << x << " " << y << " " << z << '\n';

	//int& ref = 4;//����� ��ü�� ���ͷ��̱⶧���� ���� �ٲ� �� ����
	//const int& ref = 4;//��� �����ڷ� ����� ���ͷ� ��������.
	//cout << ref << '\n';


	////�迭�� ���۷���
	//int arr[3] = { 1, 2, 3 };
	//int(&ref)[3] = arr;//ref�� arr�� �����ϵ��� ��

	//ref[0] = 2;
	//ref[1] = 4;
	//ref[2] = 0;
	////ref[0]���� ref[2]�� ���� arr[0]���� arr[2]�� ���۷����� �ȴ�

	//cout << arr[0] << " " << arr[1] << " " << arr[2] << '\n';

	int b = 2;
	int c = function(b);//�̽������� �Լ� function�� ���� a�� main�� b�� �����ϰ� �ְ� ��
	//���� function�� ������ �����ڴ� ���� ����ִ� ������ b�� ��� ������
	//�ᱹ c�� ������ b���� 5�� �����ϴ� �Ͱ� ������ ������ ��
	cout << c << '\n';
}