#include<iostream>

class Parent {
public:
	void print1() {
		std::cout << "Parent print1()\n";
	}
	virtual void print2() {
		std::cout << "Parent print2()\n";
	}
	virtual void print3(int a) {
		std::cout << "Parent print3(), parameter "<<a<<'\n';
	}
};

class Child : public Parent {
public:
	void print2() {
		std::cout << "Child print2()\n";
	}
	void print3(int x) {
		std::cout << "Child print3(), parameter " << x << '\n';
	}
};

void main() {
	Parent* p1;//Parent클래스를 가리키는 포인터 p1선언,
	Child c1;// Child클래스의 객체 c1선언
	p1 = &c1;//포인터 p1은 객체 c1을 가리킴
	//몸체(p1)는 Parent클래스이지만 실제객체(c1)는 Child클래스임


	p1->print1();//일반함수 호출
	p1->print2();//가상함수 호출
	p1->print3(7);

	//print1(): 일반함수이기 때문에 compile time에 결정남.=>Parent클래스의 print1()이 호출됨
	//print2(): 가상함수이기때문에 runtime에 결정됨.=>Parent클래스이지만 가리키고있는 객체가 Child클래스이기때문에
	//	child클래스의 print2가 호출됨.

	//print3(): 가상함수이지만 Child클래스에선 매개변수가 없는 함수를 호출했기 때문에 부모클래스인 Parent클래스의
	//	print3가 호출됨.
	//만약 매개변수가 주어지면 Child클래스의 print3가 호출되게 된다.
}