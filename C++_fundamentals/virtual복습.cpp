#include<iostream>
#include<vector>
using namespace std;

class Animal {
public:
	Animal() {
		cout << "Animal 자원할당" << endl;
	}
	virtual ~Animal() {
		cout << "Animal 자원해제" << endl;
	}
	virtual void Cry() {
		cout << "Animal Cry" << endl;
	}
};

class Dog : public Animal {
public:
	Dog() {
		cout << "Dog 자원할당" << endl;
	}
	virtual ~Dog() {
		cout << "Dog 자원해제" << endl;
	}
	// virtual, override를 제거해도 빌드 되지만 실수 방지용
	virtual void Cry() override{//Animal클래스에서 Cry()를 virtual선언했기 때문에 자동으로 virtual선언이 된다
		cout << "Dog Cry" << endl;
	}
};

int main() {
	Animal* anim = new Dog();
	//anim.Cry();
	//Dog *dog = new Dog();
	//Dog d;
	//d.Cry();

	//Animal* p = &d;//animal객체가 실제 가리키는 대상은 dog형 객체
	//p->Cry();//그러나 virtual로 선언하지 않아 Animal::Cry()를 호출하게 된다
	////(포인터 메모리 타입의 함수)
	////virtual 선언 시 포인터가 실제로 가리키고 있는 객체, 즉 d의 함수를 호출하게 된다

	delete anim;
	//delete dog;
}