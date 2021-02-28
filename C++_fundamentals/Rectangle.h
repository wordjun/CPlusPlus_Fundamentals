#pragma once
#ifndef __RECTANGLE_H_
#define __RECTANGLE_H_

#include "Point.h"

class Rectangle {
private:
	Point upLeft;
	Point lowRight;
public:
	Rectangle(const int& x1, const int& y1, const int& x2, const int& y2);
	//bool InitMembers(const Point& ul, const Point& lr);
	void ShowRectInfo() const;
	/*
	const 함수: 다음 함수들은 해당 함수 내에서 멤버변수에 저장된 값을 변경하지 않겠다는 의미를 갖는다.
	*/
};
#endif // !__RECTANGLE_H_
