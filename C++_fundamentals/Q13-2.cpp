#include<iostream>
using namespace std;

template<typename T>
T SumArray(T arr[], int len) {
	T sum = 0;
	for (int i = 0; i < len; i++) {
		sum += arr[i];
	}
	return sum;
}

int main() {
	int arr[] = { 80, 90, 100 };
	cout << SumArray(arr, sizeof(arr) / sizeof(int))<<'\n';

	double arr2[] = { 33.8, 74.9, 21.6 };
	cout << SumArray(arr2, sizeof(arr2) / sizeof(double)) << '\n';
	return 0;
}