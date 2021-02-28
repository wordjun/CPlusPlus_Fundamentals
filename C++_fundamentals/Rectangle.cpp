#include<iostream>
#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle(const int& x1, const int& y1, const int& x2, const int& y2)
	:upLeft(x1, y1), lowRight(x2, y2) {//member initializer�� ���
	//��ü upLeft�� ������������ x1�� y1�� ���ڷ� ���޹޴� ������ ȣ��
	//����̴ϼȶ������� ��������� ����� ��ü�� ������ ȣ�⿡ Ȱ���
}

//bool Rectangle::InitMembers(const Point& ul, const Point& lr) {
//	if (ul.getX() > lr.getX() || ul.getY() > lr.getY()) {
//			cout << "WRONG TRANSMISSON OF COORDINATES\n";
//			return false;
//	}
//	upLeft = ul;
//	lowRight = lr;
//	return true;
//}

void Rectangle::ShowRectInfo() const {
	cout << "Upper left: [" << upLeft.getX() << ", " << upLeft.getY() << "]\n";
	cout << "Lower right: [" << lowRight.getX() << ", " << lowRight.getY() << "]\n";
}