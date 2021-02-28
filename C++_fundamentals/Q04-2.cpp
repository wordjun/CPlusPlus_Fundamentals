#include<iostream>
using namespace std;

class Point {
private:
	int xpos;
	int ypos;
public:
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
	Ring ring;
	ring.Init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}