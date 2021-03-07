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
	friend Point operator+(const Point &p1, const Point &p2);
};

Point operator+(const Point &p1, const Point &p2) {
	Point retP(p1.xpos + p2.xpos, p1.ypos + p2.ypos);
	return retP;
}

int main(){
	Point p1(3, 4);
	Point p2(10, 20);
	Point p3 = p1 + p2;//p1 + p1이 p1.operator+(p1)의 다른 표현이다
	p3.ShowPosition();
	return 0;
}