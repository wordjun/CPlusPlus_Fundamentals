#include<iostream>
#include<cstdlib>
using namespace std;

template<typename T>
class Point {
private:
	T xpos, ypos;
public:
	Point(T x = 0, T y = 0)
		:xpos(x), ypos(y) {

	}
	void showPos() const {
		cout << xpos << ", " << ypos << '\n';
	}
};

int main() {
	Point<int> p1(3, 5);//템플릿 클래스의 객체 생성시엔 반드시 자료형 정보를 명시해야 한다.
	p1.showPos();

	Point<double> p2(1.1, 7.4);
	p2.showPos();

	Point<char> p3('A', 'Z');
	p3.showPos();
}