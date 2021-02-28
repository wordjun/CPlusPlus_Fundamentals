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
	const �Լ�: ���� �Լ����� �ش� �Լ� ������ ��������� ����� ���� �������� �ʰڴٴ� �ǹ̸� ���´�.
	*/
};
#endif // !__RECTANGLE_H_
