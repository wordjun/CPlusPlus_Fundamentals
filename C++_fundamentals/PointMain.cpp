#include<iostream>
#include "PointTemplate.h"
using namespace std;

//PointTemplate.cpp�� �������� �ʱ� ������ ���ø��Լ��� ���� ������ �����Ͽ� �����Ͽ����� �߻�
#include"PointTemplate.cpp"//�ҽ������� �����Ͽ� ���ø��� ���� ��� ������ ���� �ҽ����Ͽ� �����ؾ� ��.

int main(void) {
	Point<int> p1(3, 5);//���ø� Ŭ������ ��ü �����ÿ� �ݵ�� �ڷ��� ������ ����ؾ� �Ѵ�.
	p1.showPos();

	Point<double> p2(1.1, 7.4);
	p2.showPos();

	Point<char> p3('A', 'Y');
	p3.showPos();
	return 0;
}