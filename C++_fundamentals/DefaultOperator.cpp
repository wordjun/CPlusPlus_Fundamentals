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
	fcpy = fsrc;//First클래스는 대입연산자 오버로딩하지 않음. 따라서 디폴트로 삽입된 대입연산자가 호출됨(fcpy.operator=(fsrc))
	scpy = ssrc;//멤버대 멤버복사가 되도록 대입연산자를 오버로딩했다.(반환형이 참조형) 다라서 (scpy.operator=(ssrc))로 해석되어 클래스에 정의된 대입연산자가 호출된다.
	//대입연산자는 오른쪽에서 왼쪽으로 진행됨.

	fcpy.ShowData();
	ssrc.ShowData();
}