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
	//�Լ��� const�� �ٿ��� ��, �迭�� ����� �����ϴ� ��� ������ü�� �Ұ�������
	//const�� ���������� �Լ������ε��� ���ǿ� �ش��Ѵ�.
	//�Ʒ� �Լ��� �� �Լ��� �����ε� ���踦 ������, �������� �ƴ� �迭����� ���� �ܼ��� ��ȯ�ϴ� �����̴�
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
	//const �����ڸ� �̿��� �����̴�, �Լ��ڿ� const�� ���� operator�� ȣ���
	for (int i = 0; i < len; i++)
		cout << ref[i] << '\n';//compile error due to mismatch of array type
}

int main() {
	BoundCheckIntArray arr(5);

	for (int i = 0; i < 5; i++) {
		arr[i] = (i + 1) * 11;//const�� ���� ���� ������ ȣ��
	}
	ShowAlldata(arr);
}
