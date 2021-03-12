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
};

class Second {
private:
	int num3, num4;
public:
	Second(int n3 = 0, int n4 = 0)
		:num3(n3), num4(n4) {}

	void ShowData() {
		cout << num3 << ", " << num4 << '\n';
	}
	Second& operator=(const Second& ref) {
		cout << "Second& operator=():\n";
		num3 = ref.num3;
		num4 = ref.num4;
		return *this;
	}
};

int main() {
	First fsrc(111, 222);
	First fcpy;
	Second ssrc(333, 444);
	Second scpy;
	fcpy = fsrc;//FirstŬ������ ���Կ����� �����ε����� ����. ���� ����Ʈ�� ���Ե� ���Կ����ڰ� ȣ���(fcpy.operator=(fsrc))
	scpy = ssrc;//����� ������簡 �ǵ��� ���Կ����ڸ� �����ε��ߴ�.(��ȯ���� ������) �ٶ� (scpy.operator=(ssrc))�� �ؼ��Ǿ� Ŭ������ ���ǵ� ���Կ����ڰ� ȣ��ȴ�.
	//���Կ����ڴ� �����ʿ��� �������� �����.

	fcpy.ShowData();
	ssrc.ShowData();
}