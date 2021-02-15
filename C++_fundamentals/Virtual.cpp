#include<iostream>

//�����Լ�(virtual function)
//�⺻Ŭ���� ������ ����Ǿ� �Ļ� Ŭ����(�ڽ�Ŭ����)�� ���� �����ǵǴ� ����Լ�.(override)
//������ Ȥ�� �⺻Ŭ������ ���� ������ ���� �Ļ�Ŭ������ ��ü�� �����ϸ� 
//�ش� ��ü�� ���� �����Լ��� ȣ���ϰ� �Ļ�Ŭ������ �Լ��� ������ �� �ִ�.

//�̴� �ַ� ����ð�(Runtime)�� �Լ��� �������� �����ϴµ� ����.

//virtual�Լ��� ��Ģ:
//1. public section�� ����
//2. static�� �� ������, �ٸ� Ŭ������ friend �Լ��� �� �� ����.
//3. ����ð� �������� ������� �⺻Ŭ������ ������/������ ���� �����ؾ� ��
//4. �����Լ��� prototype�� �⺻Ŭ������ �Ļ�Ŭ�������� ������
//5. Ŭ������ ����Ҹ��ڸ� ���� �� ������ ��������ڴ� ���� �� ����

class Parent {
public:
	virtual void v_print() {
		std::cout << "parent(v_print)\n";
	}
	void print() {
		std::cout << "parent(print)\n";
	}
};

class Child : public Parent {
public:
	void v_print() {
		std::cout << "child(v_print)\n";
	}
	void print() {
		std::cout << "child(print)\n";
	}
};

void main() {
	Parent* p1;//ParentŬ������ ����Ű�� ������ p1����,
	Child c1;// ChildŬ������ ��ü c1����
	p1 = &c1;//������ p1�� ��ü c1�� ����Ŵ
	//��ü(p1)�� ParentŬ���������� ������ü(c1)�� ChildŬ������

	
	p1->v_print();//�����Լ� ȣ��
	p1->print();//�Ϲ��Լ� ȣ��

	//����� child, parent�̴�
	//v_print()�Լ��� ����Ű����� ����Ǿ� �����Լ��� ������
	//�����Լ��� ����ð�(runtime)�� �� ���� ������.(�ı���ε�)
	//������ p1���� ChildŬ������ ��ü(c1)�� �� �ְ�,
	//�����Ͱ� ����Ű�� ��ġ�� ���� ChildŬ������ v_print()�Լ��� ȣ�������,
	//�Ϲ� �Լ��� print()�� compile time�� �̹� �����Ǳ� ������ 
	//ParentŬ������ print()�Լ��� ȣ��Ǵ� ������ ������ �������� ������
	//���� ParentŬ������ print()�Լ��� ȣ��ǰ� ��
}