#include<iostream>
#include "Point.h"
using namespace std;

Point::Point(const int& xpos, const int& ypos) {
	x = xpos;
	y = ypos;
}

//bool Point::InitMembers(int xpos, int ypos) {
//	if (xpos < 0 || ypos < 0) {
//		cout << "OUT OF RANGE\n";
//		return false;
//	}
//	x = xpos;
//	y = ypos;
//	return true;
//}

//get, set함수들을 access function이라 한다.
//멤버변수를 private으로 선언하며 클래스외부에서의 멤버변수 접근을 목적으로 정의되는 함수들이다
int Point::getX() const {
	return x;
}

int Point::getY() const {
	return y;
}

bool Point::setX(int xpos) {
	if (xpos < 0 || xpos > 100) {
		cout << "OUT OF RANGE\n";
		return false;
	}
	x = xpos;
	return true;
}

bool Point::setY(int ypos) {
	if (ypos < 0 || ypos > 100) {
		cout << "OUT OF RANGE\n";
		return false;
	}
	y = ypos;
	return true;
}