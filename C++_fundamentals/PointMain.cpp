#include<iostream>
#include "PointTemplate.h"
using namespace std;

//PointTemplate.cpp를 참조하지 않기 때문에 템플릿함수에 대한 정보가 부족하여 컴파일에러가 발생
#include"PointTemplate.cpp"//소스파일을 참조하여 템플릿에 대한 모든 정보를 현재 소스파일에 전달해야 함.

int main(void) {
	Point<int> p1(3, 5);//템플릿 클래스의 객체 생성시엔 반드시 자료형 정보를 명시해야 한다.
	p1.showPos();

	Point<double> p2(1.1, 7.4);
	p2.showPos();

	Point<char> p3('A', 'Y');
	p3.showPos();
	return 0;
}