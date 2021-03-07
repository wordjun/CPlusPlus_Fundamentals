#include<iostream>
using namespace std;

class First {
private:
	char* strOne;
public:
	First(const char* str) {
		strOne = new char[strlen(str) + 1];
	}
	virtual ~First() {
		cout << "delete strOne\n";
		delete[] strOne;
	}
};

class Second : public First {
private:
	char* strTwo;
public:
	Second(const char* str1, const char* str2)
		:First(str1) {
		strTwo = new char[strlen(str2) + 1];
	}
	~Second() {
		cout << "delete strTwo\n";
		delete[] strTwo;
	}
};

int main(void) {
	First* ptr = new Second("simple", "complex");
	delete ptr;//��ü�� �Ҹ��� First�� �����ͷ� ���->FirstŬ������ �Ҹ��ڸ� ȣ���
	//�޸� leak�߻�: ��ü�Ҹ�������� delete�� ���� �����ͺ����� �ڷ����� �������
	//��� �Ҹ��ڰ� ȣ��ž� ��. �̸� ���ؼ� ~First()�� virtual�� �߰��Ѵ�
	//�����Լ��� �Ȱ���, �Ҹ��ڵ� ����� ���������� �� ���� �����ϴ� baseŬ������ �Ҹ��ڸ� virtual��
	//�����ϰ� �Ǹ� �̸� ����ϴ� ����Ŭ������ �Ҹ��ڵ鵵 ��� ����Ҹ��ڷ� ����ȴ�
	//����Ҹ��� ȣ�� ��: ����� ���������� �� �Ʒ��� �����ϴ� ����Ŭ������ �Ҹ��ڰ� ��� ȣ��Ǹ�
	//���� Ŭ������ �Ҹ��ڰ� ���������� ȣ���.
	return 0;
}