#include<iostream>
using namespace std;

template <class T1, class T2>
void ShowData(double num) {
	cout << (T1)num << ", " << (T2)num<<'\n';
	//T1(num), T2(num)
}

int main() {
	ShowData<char, int>(65);
	ShowData<char, double>(68.5);
	ShowData<short, double>(69.2);
}