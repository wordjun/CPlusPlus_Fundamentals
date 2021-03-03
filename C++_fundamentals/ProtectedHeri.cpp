#include<iostream>
using namespace std;

class Base {
private:
	int num1;
protected:
	int num2;
public:
	int num3;

	Base()
		:num1(1), num2(2), num3(3) {}

};

class Derived : protected Base {//protected���� ���ٹ����� ���� ����� protected�� ������� ��ӽ�Ų��(private < protected < public)
	//empty
};

//public ���: private�� ������ �������� �״�� ����Ѵ�

int main(void) {
	Derived derived1;
	//Inherited Base class as protected.
	//public ������ num3�� derived���� protected�� �ȴ�
	//cout << derived1.num3 << '\n';//compile error, num3 inaccessible
	return 0;
}