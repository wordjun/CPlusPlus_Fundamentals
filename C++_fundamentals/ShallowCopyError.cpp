#include<iostream>
using namespace std;
#pragma warning(disable:4996)

class Person {
private:
	char* name;
	int age;
public:
	Person(const char* myname, int myage) {
		name = new char[strlen(myname) + 1];
		strcpy(name, myname);
		age = myage;
	}
	Person(const Person& copy)
		:age(copy.age) {
		name = new char[strlen(copy.name) + 1];
		strcpy(name, copy.name);
	}

	void showInfo() const {
		cout << "name: " << name << '\n' << "age: " << age << '\n';
	}
	~Person() {
		delete[] name;
		cout << "destructor called.\n";
	}
};

int main(void) {
	Person p1("jun hyun park", 25);


	Person p2 = p1;
	p1.showInfo();
	p2.showInfo();


	return 0;
}