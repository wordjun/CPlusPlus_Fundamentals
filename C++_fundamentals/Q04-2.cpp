#include<iostream>
using namespace std;

class Point {
private:
	int xpos;
	int ypos;
public:
	Point(int x, int y)
		:xpos(x), ypos(y) {}

	void Init(int x, int y) {
		xpos = x;
		ypos = y;
	}
	void setX(int x) {
		xpos = x;
	}
	void setY(int y) {
		ypos = y;
	}
	void ShowPointInfo() const {
		cout << "[" << xpos << ", " << ypos << "]\n";
	}
};

class Circle {
private:
	Point center;
	int radius;
public:
	Circle(const int x, const int y, const int _radius)
		:center(x, y), radius(_radius) {}

	void setCircle(int x, int y, int r) {
		center.setX(x);
		center.setY(y);
		radius = r;
	}
	int getRadius() const {
		return radius;
	}
	void ShowCircleInfo() const {
		//cout << "Center coordinates: ";
		center.ShowPointInfo();
	}
};

class Ring {
private:
	Circle innerCircle;
	Circle outerCircle;
public:
	Ring(const int x1, const int y1, const int r1, const int x2, const int y2, const int r2)
		:innerCircle(x1, y1, r1), outerCircle(x2, y2, r2) {}

	void Init(int x1, int y1, int r1, int x2, int y2, int r2) {
		innerCircle.setCircle(x1, y1, r1);
		outerCircle.setCircle(x2, y2, r2);
	}
	void ShowRingInfo() const {
		cout << "Inner Circle Info...\n";
		cout << "radius: " << innerCircle.getRadius() << '\n';
		innerCircle.ShowCircleInfo();

		cout << "Outer Circle Info...\n";
		cout << "radius: " << outerCircle.getRadius() << '\n';
		outerCircle.ShowCircleInfo();
	}
};


int main(void) {
	Ring ring(1, 1, 5, 3, 3, 12);
	//ring.Init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}