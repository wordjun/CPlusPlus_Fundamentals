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

class Derived : protected Base {//protected보다 접근범위가 넓은 멤버는 protected로 변경시켜 상속시킨다(private < protected < public)
	//empty
};

//public 상속: private을 제외한 나머지는 그대로 상속한다

int main(void) {
	Derived derived1;
	//Inherited Base class as protected.
	//public 변수인 num3는 derived에서 protected가 된다
	//cout << derived1.num3 << '\n';//compile error, num3 inaccessible
	return 0;
}