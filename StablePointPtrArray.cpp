#include<iostream>
#include<cstdlib>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0)
		:xpos(x), ypos(y) {

	}
	friend ostream& operator<<(ostream& os, const Point& pos);
	int getX() const {
		return xpos;
	}
	int getY() const {
		return ypos;
	}
};

ostream& operator<<(ostream& os, const Point* pos) {
	os << pos->getX() << ", " << pos->getY() << '\n';
	return os;//?
}

typedef Point* POINT_PTR;

class BoundCheckPointPtrArray {
private:
	POINT_PTR* arr;
	int arrlen;
	//declare copy constructor and substitution operator as private in current class,
	//to prevent copy or substitution
	BoundCheckPointPtrArray(const BoundCheckPointPtrArray& arr);//copy constructor
	BoundCheckPointPtrArray& operator=(const BoundCheckPointPtrArray& arr) {}//substitution operator
public:
	BoundCheckPointPtrArray(int len)
		:arrlen(len) {
		arr = new POINT_PTR[len];
	}
	POINT_PTR& operator[](int idx) {
		if (idx < 0 || idx >= arrlen) {
			//index out of range
			cout << "Array index out of bound exception\n";
			exit(1);
		}
		return arr[idx];
	}
	POINT_PTR operator[](int idx) const {
		if (idx < 0 || idx >= arrlen) {
			//index out of range
			cout << "Array index out of bound exception\n";
			exit(1);
		}
		return arr[idx];
	}
	int GetArrLen() const {
		return arrlen;
	}
	~BoundCheckPointPtrArray() {
		delete[]arr;
	}
};
//declared const so that the data stored inside the array cannot be manipulated in this function
void ShowAlldata(const BoundCheckPointPtrArray& ref) {
	int len = ref.GetArrLen();
	//const 참조자를 이용한 연산이니, 함수뒤에 const가 붙은 operator가 호출됨
	for (int i = 0; i < len; i++)
		cout << ref[i] << '\n';//compile error due to mismatch of array type
}

int main() {
	BoundCheckPointPtrArray arr(3);

	//Point객체의 주소값을 저장. 객체의 주소값 저장하는 경우, 깊은 복사냐 얕은복사냐의 문제는 신경X
	arr[0] = new Point(1, 2);
	arr[1] = new Point(3, 4);
	arr[2] = new Point(5, 9);

	for (int i = 0; i < arr.GetArrLen(); i++)
		cout << arr[i];//값출력(*)

	delete arr[0];
	delete arr[1];
	delete arr[2];
}