#include<iostream>
using namespace std;

class First {
private:
	int num1, num2;
public:
	First(int n1 = 0, int n2 = 0)
		:num1(n1), num2(n2) {}

	void ShowData() {
		cout << num1 << ", " << num2 << '\n';
	}
	First& operator=(const First& ref) {//SecondŬ������ ���Կ����ڿ��� �ش� �Լ� ȣ���, �Ű������� Second�� �����ڰ� �Ѿ���� �Ǹ�,
		//First�� �����ڴ� First�Ǵ� First�� ����/���������� ����ϴ� ��� ��ü�� ������ �� �����Ƿ� ������ ���� �ʴ´�.
		cout << "First& operator=():\n";
		num1 = ref.num1;
		num2 = ref.num2;
		return *this;
	}
};

//����Ŭ����(Second)�� �����ڿ� �ƹ��� ��ø� ���� �ʾƵ� ����Ŭ����(First)�� �����ڰ� ȣ�������,
//����Ŭ������ ���Կ����ڿ� �ƹ��� ��ø� ���������� ����Ŭ������ ���Կ����ڰ� ȣ����� �ʴ´�.
class Second : public First {
private:
	int num3, num4;
public:
	Second(int n1, int n2, int n3, int n4)
		:First(n1, n2), num3(n3), num4(n4) {}

	void ShowData() {
		First::ShowData();
		cout << num3 << ", " << num4 << '\n';
	}
	//���Կ����ڰ� ���ǵ��� �ʾ��� ��� ����Ŭ������ ���Ե� ����Ʈ ���Կ����ڰ� ����Ŭ������ ���Կ����ڱ��� ȣ���Ѵ�.
	Second& operator=(const Second& ref) {
		cout << "Second& operator=():\n";
		//����Ŭ������ ���Կ����� ��������� ȣ���ؾߵ�.
		First::operator=(ref);
		num3 = ref.num3;
		num4 = ref.num4;
		return *this;
	}
	//����Ŭ���� ���Կ����� ���ǿ��� ��������� ����Ŭ������ ���Կ����� ȣ�⹮�� ���� ������ ����Ŭ������ ���Կ����ڴ� ȣ����� �ʾƼ�
	//����Ŭ������ ��������� ������� �����󿡼� ���ܵ�.
};

int main() {
	Second s1(11, 22, 33, 44);
	Second scpy(0, 0, 0, 0);
	scpy = s1;
	scpy.ShowData();
}