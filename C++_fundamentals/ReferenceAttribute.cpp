#include<iostream>
using namespace std;

class First {
public:
	void FirstFunc() {
		cout << "FirstFunc()\n";
	}
	virtual void SimpleFunc() {
		cout << "First's SimpleFunc()\n";
	}
};

class Second : public First {
public:
	void SecondFunc() {
		cout << "SecondFunc()\n";
	}
	virtual void SimpleFunc() {
		cout << "Second's SimpleFunc()\n";
	}
};

class Third :public Second {
public:
	void ThirdFunc() {
		cout << "ThirdFunc()\n";
	}
	virtual void SimpleFunc() {
		cout << "Third's SimpleFunc()\n";
	}
};

int main() {
	Third obj;
	/*obj.FirstFunc();
	obj.SecondFunc();
	obj.ThirdFunc();
	obj.SimpleFunc();*/

	Second& sref = obj;//obj는 Second클래스를 상속하는 Third형 객체이므로 Second형 참조자 &sref로 참조가 가능
	sref.FirstFunc();
	sref.SecondFunc();//compiler는 참조자의 자료형을 갖고 함수의 호출 가능성을 판단하기때문에 
	//참조자 sref는 Second클래스형이고, Second클래스는 First클래스를 상속하기 때문에 First클래스에 정의된 FirstFunc함수와 Second클래스에 정의된 SecondFunc함수는 호출이 가능하다.
	//but third클래스에 정의된 ThirdFunc는 호출 불가능
	sref.SimpleFunc();//SimpleFunc()함수는 virtual함수이며, sref가 참조하는 대상이 Third클래스의 객체 obj이므로, Third클래스에 정의된 SimpleFunc()객체가 호출된다

	First& fref = obj;//obj는 First를 간접상속(Second를 통해), 따라서 First형 참조자로 참조가능
	fref.FirstFunc();
	fref.SimpleFunc();

	//void Goodfunction(const First &ref);
	//First객체 또는 First를 직접/간접적으로 상속하는 클래스의 객체가 인자 &ref의 대상이 된다.
	//인자로 전달되는 객체의 실제 자료형에 상관없이 함수 내에선 First클래스에 정의된 함수만 호출이 가능하다.
}