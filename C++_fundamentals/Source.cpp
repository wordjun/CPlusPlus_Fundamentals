#include<iostream>
using namespace std;

int main() {
	//1~100 ���� ������ 3�� 7�� ������� ����϶�
	for (int i = 1; i <= 100; i++) {
		if (i % 3 == 0 && i % 7 == 0) {
			cout << i << " ";
		}
	}

}