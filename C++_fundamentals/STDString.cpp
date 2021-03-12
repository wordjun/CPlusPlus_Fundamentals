#include<iostream>
#include<string>
using namespace std;

int main() {
	string str1 = "I like ";
	string str2 = "string class";
	string str3 = str1 + str2;

	cout << str1 << '\n';
	cout << str2 << '\n';
	cout << str3 << '\n';
	str1 += str2;

	if (str1 == str3)
		cout << "Same string\n";
	else
		cout << "Different string\n";

	string str4;
	cout << "Enter string: ";
	cin >> str4;
	cout << "String entered: " << str4 << '\n';

	return 0;
}
