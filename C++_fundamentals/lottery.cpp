#include<iostream>
using namespace std;
#define MAX 45

int main() {
	int numbers[MAX] = {};
	bool check[MAX];
	srand((unsigned int)time(0));
	for (int i = 0; i < MAX; i++) {
		numbers[i] = i + 1;
	}

	int temp, index1, index2;
	for (int i = 0; i < 100; i++) {
		index1 = rand() % 45;
		index2 = rand() % 45;

		temp = numbers[index1];
		numbers[index1] = numbers[index2];
		numbers[index2] = temp;
	}

	/*for (int i = 0; i < MAX; i++) {
		cout << numbers[i] << '\n';
	}*/

	for (int i = 0; i < 6; i++) {
		cout << numbers[i] << '\t';
	}
	cout << '\n';
}