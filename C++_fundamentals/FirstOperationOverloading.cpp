#include<iostream>
using namespace std;

/*
함수가 오버로딩 되면 오버로딩된 수만큼 다양한 기능을 제공하게 된다.
즉, 이름은 하나이지만 기능은(기능을 제공하는 함수) 여러가지가 되는 셈이다
연산자의 오버로딩을 통해 기존에 존재하던 연산자의 기본 기능이외에 다른기능을 추가할 수 있다*/

class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0)
		:xpos(x), ypos(y) {}

	void ShowPosition() const{
		cout << "x: " << xpos << ", y: " << ypos << '\n';
	}
	Point operator+(const Point& ref) {
		Point pos(xpos + ref.xpos, ypos + ref.ypos);
		return pos;
	}
};

int main() {
	Point p1(3, 4);
	Point p2(10, 20);
	Point p3 = p1.operator+(p2);
	p3.ShowPosition();
	return 0;
}