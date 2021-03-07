#include<iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0)
		:xpos(x), ypos(y) {}

	void ShowPosition() const {
		cout << "x: " << xpos << ", y: " << ypos << '\n';
	}
	/*Point operator+(const Point& ref) {
		Point pos(xpos + ref.xpos, ypos + ref.ypos);
		return pos;
	}*/
	Point& operator+=(const Point& ref) {
		this->xpos += ref.xpos;
		this->ypos += ref.ypos;
		return *this;
	}
	Point& operator-=(const Point& ref) {
		xpos -= ref.xpos;
		ypos -= ref.ypos;
		return *this;
	}
	friend Point operator-(const Point&, const Point&);
	friend bool operator==(const Point&, const Point&);
	friend bool operator != (const Point &, const Point &);
};

Point operator-(const Point& p1, const Point& p2) {
	Point newP = Point(p1.xpos - p2.xpos, p1.ypos - p2.ypos);
	return newP;
}

//전역함수 형태로 오버로딩
bool operator==(const Point& p1, const Point& p2) {
	if (p1.xpos == p2.xpos && p1.ypos == p2.ypos)
		return true;
	else
		return false;
}

bool operator!=(const Point& p1, const Point& p2) {
	/*if (p1.xpos != p2.xpos || p1.ypos != p2.ypos)
		return true;
	else
		return false;*/
	return !(p1 == p2);
}

int main() {
	Point p1(3, 4);
	Point p2(10, 20);
	Point p3(22, 34);
	Point p4(10, 20);

	//(p1 += p3).ShowPosition();
	(p4 -= p1).ShowPosition();
	cout << (p2 != p4) << '\n';
	cout << (p2 == p3) << '\n';
}