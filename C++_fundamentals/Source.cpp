#include<iostream>
using namespace std;

int main() {
	//1~100 사이 숫자중 3과 7의 공배수만 출력하라
	for (int i = 1; i <= 100; i++) {
		if (i % 3 == 0 && i % 7 == 0) {
			cout << i << " ";
		}
	}

}