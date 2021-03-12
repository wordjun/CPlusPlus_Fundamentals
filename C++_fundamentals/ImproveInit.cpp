#include<iostream>
using namespace std;

class AAA {
private:
	int num;
public:
	AAA(int n = 0)
		:num(n) {
		cout << "AAA(int n = 0)\n";
	}
	AAA(const AAA& ref)
		:num(ref.num) {
		cout << "AAA(const AAA& ref)\n";
	}
	AAA& operator=(const AAA& ref) {
		num = ref.num;
		cout << "operator=(const AAA& ref)\n";
		return *this;
	}
};

class BBB {
private:
	AAA mem;
public:
	BBB(const AAA& ref)
		:mem(ref) {//��� �̴ϼȶ�����
		//AAAŬ������ ��������ڰ� ȣ���
		//�̴ϼȶ����� ���� ����� ���ÿ� �ʱ�ȭ�� �̷����� ���·� ���̳ʸ� �ڵ尡 ������.
		//AAA mem=ref
		//�Ʒ����� �ణ�� ������� ��밡��
	}
};

class CCC {
private:
	AAA mem;
public:
	CCC(const AAA& ref) {
		mem = ref;//���Կ���
		//AAAŬ������ ��������ڿ� ���Կ����ڰ� ȣ���
		//�������� ��ü�κп��� ���Կ����� ���� �ʱ�ȭ�� �����ϸ�, ����� �ʱ�ȭ�� ����
		//������ ���忡�� �����ϴ� ���·� ���̳ʸ� �ڵ尡 ������.
	}
};

int main() {
	AAA a(12);
	cout << '\n';
	BBB b(a);
	cout << '\n';
	CCC c(a);

}