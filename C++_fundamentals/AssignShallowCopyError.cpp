#include<iostream>
#include<cstring>
#pragma warning (disable:4996)
using namespace std;

class Person {
private:
	char* name;
	int age;
public:
	Person(const char* myname, int myage)
		:age(myage) {
		name = new char[strlen(myname) + 1];
		strcpy(name, myname);
	}
	void ShowPersonInfo() const {
		cout << "name: " << name << '\n';
		cout << "age: " << age << '\n';
	}
	~Person() {
		delete[] name;
		cout << "called destructor\n";
	}
	//대입연산자 직접정의
	Person& operator=(const Person& ref) {//대입연산자는 생성자가 아니다. 
		//prevent memory leak
		delete[] name;//멤버대 멤버 복사전에 기존에 가리키고 있던 문자열은 삭제
		name = new char[strlen(ref.name) + 1];
		strcpy(name, ref.name);
		age = ref.age;
		return *this;
	}
};

int main(void) {
	Person p1("Lee", 12);
	Person p2("Yoon", 523);
	p2 = p1;//Person클래스에 대입연산자 오버로딩이 정의되지 않았으므로, 디폴트 대입연산자가 호출된다.
	/*
	그러나 디폴트대입연산자는 멤버대멤버만 복사하므로, 소멸자 호출과정에서 에러가 발생함.
	하나의 문자열을 총 2개의 객체가 동시에 참조하는 상황이 발생.
	Park을 가리키던 문자열의 주소값을 잃게 되고, 얕은복사(단순 멤버대멤버복사)로 인해 객체의 소멸과정에서 지워진 문자열을 다시 소멸하려고 시도하게 되면서 문제가 발생한다.
	이를 memory leak(메모리누수)라고 한다
	해결법은 깊은 복사를 진행하고, 메모리누수를 방지하기 위해 메모리해제의 과정을 거쳐야 한다*/

	p1.ShowPersonInfo();
	p2.ShowPersonInfo();
}