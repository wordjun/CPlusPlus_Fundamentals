#include<iostream>

//������
//�������̵��� ������ ������ �ִ� OOP�� Ư¡ �� �ϳ�
//���� �޼ҵ� ȣ�� �� ���� ����Ǵ� ������ �ش� ��ü�� �����̳Ŀ� ���� �޶����ٴ� ��.
//��) �׸� �׸� �� �ﰢ�� ��ü���� Draw�Լ�ȣ���ϴ� �Ͱ� ���簢�� ��ü���� Draw�Լ�ȣ���ϴ°���
//�� �� Draw��� ��ƾ�� ���ؼ� ��������� �׸��� �׸��� ���� �ٸ��� �ȴٴ� ��.(���� ������ �ٸ��� ��Ÿ��)
//���� �� �� ���� �θ� ��ӹ޾ƾ� ��

class Shape {
public:
	void Draw() {
		//������ �ڽĿ��� �Ѵ�
	}
};

class Triangle :Shape {
public:
	void Draw() {
		std::cout << "Draw Triangle\n";
	}
};

class Rectangle :Shape {
public:
	void Draw() {
		std::cout << "Draw Rectangle\n";
	}
};

void main() {
	Triangle t1;
	Rectangle r1;

	t1.Draw(), r1.Draw();
}