#include<iostream>
#include"ArrayTemplate.h"
#include"Point.h"
using namespace std;

int main() {
	//int형 정수 저장
	BoundCheckArray<int> iarr(5);
	for (int i = 0; i < 5; i++)
		iarr[i] = (i + 1) * 11;
	for (int i = 0; i < 5; i++)
		cout << iarr[i] << '\n';

	//Point객체 저장
	BoundCheckArray<Point> parr(3);
	parr[0] = Point(3, 4);
	parr[1] = Point(1, 2);
	parr[2] = Point(0, 9);

	for (int i = 0; i < parr.GetArrLen(); i++)
		cout << parr[i];

	//Point객체의 주소값 저장
	typedef Point* POINT_PTR;
	BoundCheckArray<POINT_PTR> ptrArr(3);
	ptrArr[0] = new Point(7, 8);
	ptrArr[1] = new Point(3, 2);
	ptrArr[2] = new Point(4, 0);

	for (int i = 0; i < ptrArr.GetArrLen(); i++)
		cout << *(ptrArr[i]);

	for (int i = 0; i < ptrArr.GetArrLen(); i++)
		delete ptrArr[i];
}