#include<iostream>
using namespace std;


class Rectangle {
private:
	int height;
	int width;
public:
	Rectangle(int h, int w)
		:height(h), width(w) {}
	void ShowAreaInfo() const {
		cout << height * width << '\n';
	}
};

class Square :public Rectangle{

public:
	Square(int len)
		:Rectangle(len, len) {}
};

int main(void) {
	Rectangle rec(4, 3);
	rec.ShowAreaInfo();
	Square sqr(7);
	sqr.ShowAreaInfo();
	return 0;
}