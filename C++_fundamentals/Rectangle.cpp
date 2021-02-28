#include<iostream>
#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle(const int& x1, const int& y1, const int& x2, const int& y2)
	:upLeft(x1, y1), lowRight(x2, y2) {//member initializer를 사용
	//객체 upLeft의 생성과정에서 x1과 y1을 인자로 전달받는 생성자 호출
	//멤버이니셜라이저는 멤버변수로 선언된 객체의 생성자 호출에 활용됨
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