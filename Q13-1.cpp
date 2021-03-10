#include<iostream>
using namespace std;



class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0)
		:xpos(x), ypos(y) {

	}
	
	void ShowPosition() const {
		cout << xpos << ", " << ypos << '\n';
	}
};

template<typename T>
void SwapData(T &x, T &y) {
	T temp = x;
	x = y;
	y = temp;
}

int main() {
	Point p1(3, 5);
	Point p2(4, 7);
	SwapData(p1, p2);
	p1.ShowPosition();
	p2.ShowPosition();

}