#include<iostream>
using namespace std;

class First {
private:
	char* strOne;
public:
	First(const char* str) {
		strOne = new char[strlen(str) + 1];
	}
	virtual ~First() {
		cout << "delete strOne\n";
		delete[] strOne;
	}
};

class Second : public First {
private:
	char* strTwo;
public:
	Second(const char* str1, const char* str2)
		:First(str1) {
		strTwo = new char[strlen(str2) + 1];
	}
	~Second() {
		cout << "delete strTwo\n";
		delete[] strTwo;
	}
};

int main(void) {
	First* ptr = new Second("simple", "complex");
	delete ptr;//객체의 소멸을 First형 포인터로 명령->First클래스의 소멸자만 호출됨
	//메모리 leak발생: 객체소멸과정에선 delete에 사용된 포인터변수의 자료형에 상관없이
	//모든 소멸자가 호출돼야 함. 이를 위해선 ~First()에 virtual을 추가한다
	//가상함수와 똑같이, 소멸자도 상속의 계층구조상 맨 위에 존재하는 base클래스의 소멸자만 virtual로
	//선언하게 되면 이를 상속하는 유도클래스의 소멸자들도 모두 가상소멸자로 선언된다
	//가상소멸자 호출 시: 상속의 계층구조상 맨 아래에 존재하는 유도클래스의 소멸자가 대신 호출되며
	//기초 클래스의 소멸자가 순차적으로 호출됨.
	return 0;
}