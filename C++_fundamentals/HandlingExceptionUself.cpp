#include<iostream>
using namespace std;

int main() {
	int n1, n2;
	cout << "Enter two numbers: ";
	cin >> n1 >> n2;

	if (n2 == 0) {
		cout << "dividend cannot be zero.\n";
		cout << "restart program\n";
	}
	else {
		cout << "quotient: " << n1/n2 << '\n';
		cout << "remainder: " << n1 % n2 << '\n';
	}
}