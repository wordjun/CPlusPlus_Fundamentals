#include<iostream>
#include<cstdlib>
using namespace std;

class BoundCheckIntArray {
private:
	int* arr;
	int arrlen;
	//declare copy constructor and substitution operator as private in current class,
	//to prevent copy or substitution
	BoundCheckIntArray(const BoundCheckIntArray& arr);//copy constructor
	BoundCheckIntArray& operator=(const BoundCheckIntArray& arr) {}//substitution operator
public:
	BoundCheckIntArray(int len)
		:arrlen(len) {
		arr = new int[len];
	}
	int& operator[](int idx) {
		if (idx < 0 || idx >= arrlen) {
			//index out of range
			cout << "Array index out of bound exception\n";
			exit(1);
		}
		return arr[idx];
	}
	//함수에 const를 붙였을 떄, 배열을 멤버로 선언하는 경우 저장자체가 불가능해짐
	//const의 선언유무도 함수오버로딩의 조건에 해당한다.
	//아래 함수는 위 함수와 오버로딩 관계를 가지며, 참조값이 아닌 배열요소의 값을 단순히 반환하는 형태이다
	int operator[](int idx) const{
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
	BoundCheckIntArray arr(5);

	for (int i = 0; i < 5; i++) {
		arr[i] = (i + 1) * 11;//const가 붙지 않은 연산자 호출
	}
	ShowAlldata(arr);
}