#include<iostream>
#include<vector>
using namespace std;

class Animal {
public:
	Animal() {
		cout << "Animal �ڿ��Ҵ�" << endl;
	}
	virtual ~Animal() {
		cout << "Animal �ڿ�����" << endl;
	}
	virtual void Cry() {
		cout << "Animal Cry" << endl;
	}
};

class Dog : public Animal {
public:
	Dog() {
		cout << "Dog �ڿ��Ҵ�" << endl;
	}
	virtual ~Dog() {
		cout << "Dog �ڿ�����" << endl;
	}
	// virtual, override�� �����ص� ���� ������ �Ǽ� ������
	virtual void Cry() override{//AnimalŬ�������� Cry()�� virtual�����߱� ������ �ڵ����� virtual������ �ȴ�
		cout << "Dog Cry" << endl;
	}
};

int main() {
	Animal* anim = new Dog();
	//anim.Cry();
	//Dog *dog = new Dog();
	//Dog d;
	//d.Cry();

	//Animal* p = &d;//animal��ü�� ���� ����Ű�� ����� dog�� ��ü
	//p->Cry();//�׷��� virtual�� �������� �ʾ� Animal::Cry()�� ȣ���ϰ� �ȴ�
	////(������ �޸� Ÿ���� �Լ�)
	////virtual ���� �� �����Ͱ� ������ ����Ű�� �ִ� ��ü, �� d�� �Լ��� ȣ���ϰ� �ȴ�

	delete anim;
	//delete dog;
}