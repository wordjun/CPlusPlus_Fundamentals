#include<iostream>
using namespace std;

template <typename T>
inline T SQUARE(T x) {
	return x * x;
}

inline int SQUARE(int x) {
	return x * x;
}

int main() {
	cout << SQUARE(4) << '\n';
	cout << SQUARE(3.5) << '\n';
}