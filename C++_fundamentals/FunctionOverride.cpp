#include<iostream>
using namespace std;

class First {
public:
	virtual void MyFunc() {//�ش� �Լ��� �������̵��ϴ� �Լ��� virtual�� �ȴ�
		cout << "FirstFunc\n";
	}
};

class Second : public First {
public:
	virtual void MyFunc() {//���� virtualŰ���带 ������� �ʾƵ� ������ ����ϴ� ���� ����
		cout << "SecondFunc\n";
	}
};

class Third : public Second {
public:
	virtual void MyFunc() {//virtual�� ����Ǹ� �ش��Լ� ȣ�� �� �������� �ڷ����� ������� ȣ������ �������� �ʰ�, �����ͺ����� ������ ����Ű�� ��ü�� �����Ͽ� ȣ������ �����Ѵ�.
		cout << "ThirdFunc\n";
	}
};

int main(void) {
	Third* t = new Third();
	Second* s = t;
	First* f = s;

	f->MyFunc();//�����Ϸ��� f�� First�� �������̴� �� �����Ͱ� ����Ű�� ��ü(s)�� ������� FirstŬ������ ���ǵ� Myfunc()�Լ��� ������ ȣ�� �� �� �ִٰ� �Ǵ�
	s->MyFunc();//�� �����ʹ� Second���̹Ƿ� �� �����Ͱ� ����Ű�� ��ü���� First�� Second�� MyFunc�Լ��� �������̵� ����� �����Ѵ�. ���� �������̵��� SEcond�� Myfunc�Լ��� ȣ���Ѵ�
	t->MyFunc();
	delete t;
	return 0;
}