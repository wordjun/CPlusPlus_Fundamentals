#include<iostream>
using namespace std;

class First {
public:
	void FirstFunc() {
		cout << "FirstFunc()\n";
	}
	virtual void SimpleFunc() {
		cout << "First's SimpleFunc()\n";
	}
};

class Second : public First {
public:
	void SecondFunc() {
		cout << "SecondFunc()\n";
	}
	virtual void SimpleFunc() {
		cout << "Second's SimpleFunc()\n";
	}
};

class Third :public Second {
public:
	void ThirdFunc() {
		cout << "ThirdFunc()\n";
	}
	virtual void SimpleFunc() {
		cout << "Third's SimpleFunc()\n";
	}
};

int main() {
	Third obj;
	/*obj.FirstFunc();
	obj.SecondFunc();
	obj.ThirdFunc();
	obj.SimpleFunc();*/

	Second& sref = obj;//obj�� SecondŬ������ ����ϴ� Third�� ��ü�̹Ƿ� Second�� ������ &sref�� ������ ����
	sref.FirstFunc();
	sref.SecondFunc();//compiler�� �������� �ڷ����� ���� �Լ��� ȣ�� ���ɼ��� �Ǵ��ϱ⶧���� 
	//������ sref�� SecondŬ�������̰�, SecondŬ������ FirstŬ������ ����ϱ� ������ FirstŬ������ ���ǵ� FirstFunc�Լ��� SecondŬ������ ���ǵ� SecondFunc�Լ��� ȣ���� �����ϴ�.
	//but thirdŬ������ ���ǵ� ThirdFunc�� ȣ�� �Ұ���
	sref.SimpleFunc();//SimpleFunc()�Լ��� virtual�Լ��̸�, sref�� �����ϴ� ����� ThirdŬ������ ��ü obj�̹Ƿ�, ThirdŬ������ ���ǵ� SimpleFunc()��ü�� ȣ��ȴ�

	First& fref = obj;//obj�� First�� �������(Second�� ����), ���� First�� �����ڷ� ��������
	fref.FirstFunc();
	fref.SimpleFunc();

	//void Goodfunction(const First &ref);
	//First��ü �Ǵ� First�� ����/���������� ����ϴ� Ŭ������ ��ü�� ���� &ref�� ����� �ȴ�.
	//���ڷ� ���޵Ǵ� ��ü�� ���� �ڷ����� ������� �Լ� ������ FirstŬ������ ���ǵ� �Լ��� ȣ���� �����ϴ�.
}