#include<iostream>

//가상함수(virtual function)
//기본클래스 내에서 선언되어 파생 클래스(자식클래스)에 의해 재정의되는 멤버함수.(override)
//포인터 혹은 기본클래스에 대한 참조를 통해 파생클래스의 객체를 참조하면 
//해당 객체에 대해 가상함수를 호출하고 파생클래스의 함수를 실행할 수 있다.

//이는 주로 실행시간(Runtime)에 함수의 다형성을 구현하는데 사용됨.

//virtual함수의 규칙:
//1. public section에 선언
//2. static일 수 없으며, 다른 클래스의 friend 함수가 될 수 없다.
//3. 실행시간 다형성을 얻기위해 기본클래스의 포인터/참조를 통해 점근해야 함
//4. 가상함수의 prototype은 기본클래스와 파생클래스에서 동일함
//5. 클래스는 가상소멸자를 가질 수 있으나 가상생성자는 가질 수 없음

class Parent {//기본클래스
public:
	virtual void v_print() {
		std::cout << "parent(v_print)\n";
	}
	void print() {
		std::cout << "parent(print)\n";
	}
};

class Child : public Parent {//파생클래스
public:
	void v_print() {
		std::cout << "child(v_print)\n";
	}
	void print() {
		std::cout << "child(print)\n";
	}
};

void main() {
	Parent* p1;//Parent클래스를 가리키는 포인터 p1선언,
	Child c1;// Child클래스의 객체 c1선언
	p1 = &c1;//포인터 p1은 객체 c1을 가리킴
	//몸체(p1)는 Parent클래스이지만 실제객체(c1)는 Child클래스임

	//v_print함수는 virtual로 선언됐으므로, p1 포인터가 실제로 가리키는 객체인 Child클래스의 v_print함수를 호출하게 된다.
	p1->v_print();//가상함수 호출
	p1->print();//일반함수 호출(p1의 몸체인 Parent클래스의 print함수 호출)

	//결과는 child, parent이다
	//v_print()함수는 가상키워드로 선언되어 가상함수가 됐으며
	//가상함수는 실행시간(runtime)에 그 값이 결정됨.(후기바인딩)
	//포인터 p1에는 Child클래스의 객체(c1)가 들어가 있고,
	//포인터가 가리키는 위치에 따라 Child클래스의 v_print()함수가 호출됐으며,
	//일반 함수인 print()는 compile time에 이미 결정되기 때문에 
	//Parent클래스의 print()함수가 호출되는 것으로 결정이 끝나버린 상태임
	//따라서 Parent클래스의 print()함수가 호출되게 됨
}