#include<iostream>
using namespace std;

/*
�Լ��� �����ε� �Ǹ� �����ε��� ����ŭ �پ��� ����� �����ϰ� �ȴ�.
��, �̸��� �ϳ������� �����(����� �����ϴ� �Լ�) ���������� �Ǵ� ���̴�
�������� �����ε��� ���� ������ �����ϴ� �������� �⺻ ����̿ܿ� �ٸ������ �߰��� �� �ִ�*/

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