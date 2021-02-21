#include<iostream>
#include<stdlib.h>
using namespace std;

class Simple {
public:
	Simple() {
		cout << "this is a constructor of class Simple.\n";
	}
};

typedef struct _Point {
	int x;
	int y;
}Point;

Point& pntAdder(const Point& p1, const Point& p2);

int main() {
	//cout << "case 1: ";
	//Simple* s1 = new Simple;//heap������ Ŭ���� ��ü�� �Ҵ�

	//cout << "case 2: ";
	//Simple* s2 = (Simple*)malloc(sizeof(Simple) * 1);//malloc�Լ�ȣ���� ���� heap������ �����Ҵ�

	////�׷��� �� �Լ�(new�� malloc)�� ���۹�Ŀ��� ���̰� �ִ�.

	//delete s1;
	//free(s2);
	//cout << '\n';
	//int* ptr = new int;
	//int& ref = *ptr;//�������� �Ҵ�� ������ ���� ������ ����
	//ref = 20;
	//cout << ref << ' ' << *ptr << '\n';

	////�������� ������ ����� �ƴ� ������ ������θ� ������.(const������ ����)
	////new�� �̿��� �Ҵ�� �޸𸮰������� ������ ������ �����ϴ�.
	////C++���� new�� �̿��� �Ҵ�� �޸� ������ ������ �����Ͽ� �������� ������ �����ϴ�.


	////Q02-3
	//Point* p1 = new Point;
	//p1->x = 3, p1->y = 4;
	//Point* p2 = new Point;
	//p2->x = 6, p2->y = 10;
	//Point &sumPnt = pntAdder(*p1, *p2);//�����ڼ���
	//cout << "The sum of two points is: (" << sumPnt.x << ", " << sumPnt.y << ")\n";
	//cout <<p1 <<' '<<&p1<< '\n';
	//
	//delete p1;
	//delete p2;
	//delete& sumPnt;//������ ������ &����

	int value = 5; 
	int* ptr = &value; // ���� ���� �ּҷ� ptr �ʱ�ȭ 
	std::cout << &value << '\n'; // value ������ �ּ� ��� 
	std::cout << ptr << '\n'; // ptr ���� �� ���

	//�����ͺ����� �ڷ��� = ����Ű�� ������ �ڷ���
	int iValue = 5;
	double dValue = 7.0;
	int* iPtr = &iValue;
	double* dPtr = &dValue;

	int x(4);
	//�ּ� ������ &(ampersand)�� �ǿ������� �ּҸ� literal�� ��ȯ���� ����.
	//��� �ǿ������� �ּҰ� ����ִ� �����͸� ��ȯ��
	cout << x << '\n' << typeid(&x).name() << '\n' << typeid(x).name() << '\n';

	return 0;
}

Point& pntAdder(const Point& p1, const Point& p2) {
	Point* retPnt = new Point;
	retPnt->x = p1.x + p2.x;
	retPnt->y = p1.y + p2.y;
	return *retPnt;
}