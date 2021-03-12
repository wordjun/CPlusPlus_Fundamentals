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
	First& operator=(const First& ref) {//Second클래스의 대입연산자에서 해당 함수 호출시, 매개변수로 Second형 참조자가 넘어오게 되면,
		//First형 참조자는 First또는 First를 직접/간접적으로 상속하는 모든 객체를 참조할 수 있으므로 문제가 되지 않는다.
		cout << "First& operator=():\n";
		num1 = ref.num1;
		num2 = ref.num2;
		return *this;
	}
};

//유도클래스(Second)의 생성자엔 아무런 명시를 하지 않아도 기초클래스(First)의 생성자가 호출되지만,
//유도클래스의 대입연산자엔 아무런 명시를 하지않으면 기초클래스의 대입연산자가 호출되지 않는다.
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
	//대입연산자가 정의되지 않았을 경우 유도클래스에 삽입된 디폴트 대입연산자가 기초클래스의 대입연산자까지 호출한다.
	Second& operator=(const Second& ref) {
		cout << "Second& operator=():\n";
		//기초클래스의 대입연산자 명시적으로 호출해야됨.
		First::operator=(ref);
		num3 = ref.num3;
		num4 = ref.num4;
		return *this;
	}
	//유도클래스 대입연산자 정의에서 명시적으로 기초클래스의 대입연산자 호출문을 넣지 않으면 기초클래스의 대입연산자는 호출되지 않아서
	//기초클래스의 멤버변수는 멤버대멤버 복사대상에서 제외됨.
};

int main() {
	Second s1(11, 22, 33, 44);
	Second scpy(0, 0, 0, 0);
	scpy = s1;
	scpy.ShowData();
}