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
	Parent* p1;//ParentŬ������ ����Ű�� ������ p1����,
	Child c1;// ChildŬ������ ��ü c1����
	p1 = &c1;//������ p1�� ��ü c1�� ����Ŵ
	//��ü(p1)�� ParentŬ���������� ������ü(c1)�� ChildŬ������


	p1->print1();//�Ϲ��Լ� ȣ��
	p1->print2();//�����Լ� ȣ��
	p1->print3(7);

	//print1(): �Ϲ��Լ��̱� ������ compile time�� ������.=>ParentŬ������ print1()�� ȣ���
	//print2(): �����Լ��̱⶧���� runtime�� ������.=>ParentŬ���������� ����Ű���ִ� ��ü�� ChildŬ�����̱⶧����
	//	childŬ������ print2�� ȣ���.

	//print3(): �����Լ������� ChildŬ�������� �Ű������� ���� �Լ��� ȣ���߱� ������ �θ�Ŭ������ ParentŬ������
	//	print3�� ȣ���.
	//���� �Ű������� �־����� ChildŬ������ print3�� ȣ��ǰ� �ȴ�.
}