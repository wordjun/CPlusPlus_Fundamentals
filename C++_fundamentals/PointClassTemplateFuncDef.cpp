#include<iostream>
using namespace std;

template<typename T>
class Point {
private:
	T xpos, ypos;
public:
	Point(T x = 0, T y = 0);
	void showPos() const;
};

template<typename T>
Point<T>::Point(T x, T y)
	:xpos(x), ypos(y) {}

template<typename T>//������� ������ "identifier "T" is undefined" ��� ������ ���
void Point<T>::showPos() const {
	cout << xpos << ", " << ypos << '\n';
}

int main() {
	Point<int> p1(3, 5);//���ø� Ŭ������ ��ü �����ÿ� �ݵ�� �ڷ��� ������ ����ؾ� �Ѵ�.
	p1.showPos();

	Point<double> p2(1.1, 7.4);
	p2.showPos();

	Point<char> p3('A', 'Z');
	p3.showPos();
}