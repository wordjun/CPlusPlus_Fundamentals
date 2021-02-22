#include<iostream>
using namespace std;

struct Point {
	int xpos;
	int ypos;

	void MovePos(int x, int y) {
		this->xpos += x;
		this->ypos += y;
	}

	void AddPoint(const Point& pos) {
		this->xpos += pos.xpos;
		this->ypos += pos.ypos;
	}
	void ShowPosition() {
		cout << "[" << this->xpos << ", " << this->ypos << "]\n";
	}
};



int main() {
	Point p1 = { 12, 4 };
	Point p2 = { 20, 30 };

	p1.MovePos(-7, 10);
	p1.ShowPosition();

	p1.AddPoint(p2);
	p1.ShowPosition();
	return 0;
}