#include<iostream>
using namespace std;

class SimpleClass {
private:
	int num1, num2;
public:
	//�����ڴ� ��ü ���� �ÿ� �� �ѹ� ȣ��ȴ�
	SimpleClass() {
		num1 = 0, num2 = 0;
	}
	SimpleClass(int n) {
		num1 = n, num2 = 0;
	}
	SimpleClass(int n1, int n2) {
		num1 = n1, num2 = n2;
	}

	/*
	SimpleClass(int n1 = 0, int n2 = 0) {//�Ű������� default�� ��������
		num1 = n1, num2 = n2;
	}
	*/

	void ShowData() const {
		cout << num1 << ' ' << num2 << '\n';
	}
};

int main() {
	SimpleClass sc1;
	sc1.ShowData();

	SimpleClass sc2(100);
	sc2.ShowData();

	SimpleClass sc3(200, 300);
	sc3.ShowData();

	SimpleClass newClass;
	newClass.ShowData();
	SimpleClass* ptr1 = new SimpleClass(5000);
	ptr1->ShowData();
}