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
	friend ostream& operator<<(ostream& os, const Point&);
	friend istream& operator>>(istream& is, Point&);
};

ostream& operator<<(ostream& os, const Point& ref) {
	os << "x: " << ref.xpos << ", y: " << ref.ypos << '\n';
	return os;
}
istream& operator>>(istream& is, Point& ref) {
	is >> ref.xpos>> ref.ypos;
	return is;
}

int main() {
	Point p1;
	//cout << p1;//operator<<(cout, pos)
	cout<<"enter x, y: ";
	cin >> p1;
	p1.ShowPosition();
	return 0;
}