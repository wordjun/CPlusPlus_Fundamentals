#include<iostream>
#include<cstdlib>
using namespace std;

class BoundCheckIntArray {
private:
	int* arr;
	int arrlen;
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
	~BoundCheckIntArray() {
		delete[]arr;
	}
};

int main() {
	BoundCheckIntArray arr(5);
	
	for (int i = 0; i < 5; i++) {
		arr[i] = (i + 1) * 11;
	}

	/*for (int i = 0; i < 6; i++)
		cout << arr[i] << '\n';*/

	BoundCheckIntArray copy(5);
	copy = arr;//not safe
	BoundCheckIntArray copy2 = arr;//also unsafe
}
