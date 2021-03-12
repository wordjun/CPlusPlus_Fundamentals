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
	//���Կ����� ��������
	Person& operator=(const Person& ref) {//���Կ����ڴ� �����ڰ� �ƴϴ�. 
		//prevent memory leak
		delete[] name;//����� ��� �������� ������ ����Ű�� �ִ� ���ڿ��� ����
		name = new char[strlen(ref.name) + 1];
		strcpy(name, ref.name);
		age = ref.age;
		return *this;
	}
};

int main(void) {
	Person p1("Lee", 12);
	Person p2("Yoon", 523);
	p2 = p1;//PersonŬ������ ���Կ����� �����ε��� ���ǵ��� �ʾ����Ƿ�, ����Ʈ ���Կ����ڰ� ȣ��ȴ�.
	/*
	�׷��� ����Ʈ���Կ����ڴ� ��������� �����ϹǷ�, �Ҹ��� ȣ��������� ������ �߻���.
	�ϳ��� ���ڿ��� �� 2���� ��ü�� ���ÿ� �����ϴ� ��Ȳ�� �߻�.
	Park�� ����Ű�� ���ڿ��� �ּҰ��� �Ұ� �ǰ�, ��������(�ܼ� �����������)�� ���� ��ü�� �Ҹ�������� ������ ���ڿ��� �ٽ� �Ҹ��Ϸ��� �õ��ϰ� �Ǹ鼭 ������ �߻��Ѵ�.
	�̸� memory leak(�޸𸮴���)��� �Ѵ�
	�ذ���� ���� ���縦 �����ϰ�, �޸𸮴����� �����ϱ� ���� �޸������� ������ ���ľ� �Ѵ�*/

	p1.ShowPersonInfo();
	p2.ShowPersonInfo();
}