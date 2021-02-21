#include<iostream>
#include<stdlib.h>
using namespace std;

class Simple {
public:
	Simple() {
		cout << "this is a constructor of class Simple.\n";
	}
};

typedef struct _Point {
	int x;
	int y;
}Point;

Point& pntAdder(const Point& p1, const Point& p2);

int main() {
	//cout << "case 1: ";
	//Simple* s1 = new Simple;//heap영역에 클래스 객체를 할당

	//cout << "case 2: ";
	//Simple* s2 = (Simple*)malloc(sizeof(Simple) * 1);//malloc함수호출을 통해 heap영역에 변수할당

	////그러나 두 함수(new와 malloc)의 동작방식에는 차이가 있다.

	//delete s1;
	//free(s2);
	//cout << '\n';
	//int* ptr = new int;
	//int& ref = *ptr;//힙영역에 할당된 변수에 대한 참조자 선언
	//ref = 20;
	//cout << ref << ' ' << *ptr << '\n';

	////참조자의 선언은 상수가 아닌 변수를 대상으로만 가능함.(const참조자 제외)
	////new를 이용해 할당된 메모리공간에도 참조자 선언이 가능하다.
	////C++에선 new를 이용해 할당된 메모리 공간도 변수로 간주하여 참조자의 선언이 가능하다.


	////Q02-3
	//Point* p1 = new Point;
	//p1->x = 3, p1->y = 4;
	//Point* p2 = new Point;
	//p2->x = 6, p2->y = 10;
	//Point &sumPnt = pntAdder(*p1, *p2);//참조자선언
	//cout << "The sum of two points is: (" << sumPnt.x << ", " << sumPnt.y << ")\n";
	//cout <<p1 <<' '<<&p1<< '\n';
	//
	//delete p1;
	//delete p2;
	//delete& sumPnt;//참조자 삭제시 &붙임

	int value = 5; 
	int* ptr = &value; // 변수 값의 주소로 ptr 초기화 
	std::cout << &value << '\n'; // value 변수의 주소 출력 
	std::cout << ptr << '\n'; // ptr 변수 값 출력

	//포인터변수의 자료형 = 가리키는 변수의 자료형
	int iValue = 5;
	double dValue = 7.0;
	int* iPtr = &iValue;
	double* dPtr = &dValue;

	int x(4);
	//주소 연산자 &(ampersand)는 피연산자의 주소를 literal로 반환하지 않음.
	//대신 피연산자의 주소가 들어있는 포인터를 반환함
	cout << x << '\n' << typeid(&x).name() << '\n' << typeid(x).name() << '\n';

	return 0;
}

Point& pntAdder(const Point& p1, const Point& p2) {
	Point* retPnt = new Point;
	retPnt->x = p1.x + p2.x;
	retPnt->y = p1.y + p2.y;
	return *retPnt;
}