#include<iostream>
#include"PointTemplate.h"
using namespace std;

template<typename T>
Point<T>::Point(T x, T y)
	:xpos(x), ypos(y) {

}

template<typename T>
void Point<T>::showPos() const {
	cout << xpos << ", " << ypos << '\n';
}