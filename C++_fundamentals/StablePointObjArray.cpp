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
};

ostream& operator<<(ostream& os, const Point& pos) {
	os << pos.xpos << ", " << pos.ypos << '\n';
	return os;//?
}

class BoundCheckIntArray {
private:
	Point* arr;
	int arrlen;
	//declare copy constructor and substitution operator as private in current class,
	//to prevent copy or substitution
	BoundCheckIntArray(const BoundCheckIntArray& arr);//copy constructor
	BoundCheckIntArray& operator=(const BoundCheckIntArray& arr) {}//substitution operator
public:
	BoundCheckIntArray(int len)
		:arrlen(len) {
		arr = new Point[len];
	}
	Point& operator[](int idx) {
		if (idx < 0 || idx >= arrlen) {
			//index out of range
			cout << "Array index out of bound exception\n";
			exit(1);
		}
		return arr[idx];
	}
	Point operator[](int idx) const {
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
	~BoundCheckIntArray() {
		delete[]arr;
	}
};
//declared const so that the data stored inside the array cannot be manipulated in this function
void ShowAlldata(const BoundCheckIntArray& ref) {
	int len = ref.GetArrLen();
	//const 참조자를 이용한 연산이니, 함수뒤에 const가 붙은 operator가 호출됨
	for (int i = 0; i < len; i++)
		cout << ref[i] << '\n';//compile error due to mismatch of array type
}

int main() {
	BoundCheckIntArray arr(3);

	arr[0] = Point(1, 2);
	arr[1] = Point(3, 4);
	arr[2] = Point(5, 6);

	for (int i = 0; i < arr.GetArrLen(); i++)
		cout << arr[i];
}
