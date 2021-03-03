#include<iostream>
using namespace std;

class First {
public:
	virtual void MyFunc() {//해당 함수를 오버라이딩하는 함수도 virtual이 된다
		cout << "FirstFunc\n";
	}
};

class Second : public First {
public:
	virtual void MyFunc() {//굳이 virtual키워드를 사용하지 않아도 되지만 명시하는 것이 좋다
		cout << "SecondFunc\n";
	}
};

class Third : public Second {
public:
	virtual void MyFunc() {//virtual로 선언되면 해당함수 호출 시 포인터의 자료형을 기반으로 호출대상을 결정하지 않고, 포인터변수가 실제로 가리키는 객체를 참조하여 호출대상을 결정한다.
		cout << "ThirdFunc\n";
	}
};

int main(void) {
	Third* t = new Third();
	Second* s = t;
	First* f = s;

	f->MyFunc();//컴파일러는 f가 First형 포인터이니 이 포인터가 가리키는 객체(s)를 대상으로 First클래스에 정의된 Myfunc()함수는 무조건 호출 할 수 있다고 판단
	s->MyFunc();//이 포인터는 Second형이므로 이 포인터가 가리키는 객체에는 First와 Second의 MyFunc함수가 오버라이딩 관계로 존재한다. 따라서 오버라이딩한 SEcond의 Myfunc함수를 호출한다
	t->MyFunc();
	delete t;
	return 0;
}