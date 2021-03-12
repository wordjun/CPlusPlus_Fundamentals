#include<iostream>
#include<cstring>
#pragma warning(disable:4996)
using namespace std;

class String {
private:
	int len;
	char* str;
public:
	String();
	String(const char* s);
	String(const String& s);
	~String();
	String& operator=(const String& s);
	String& operator+=(const String& s);
	bool operator==(const String& s);
	String operator+ (const String& s);

	friend ostream& operator<<(ostream& os, const String& s);
	friend istream& operator>>(istream& is, String& s);
};

String::String() {
	len = 0;
	str = NULL;
}

String::String(const char* s) {
	len = strlen(s) + 1;
	str = new char[len];
	strcpy(str, s);
}

String::String(const String& s) {
	len = s.len;
	str = new char[len];
	strcpy(str, s.str);
}

String::~String() {
	if(str!=NULL)
		delete[] str;
}

String& String::operator=(const String& s) {
	//prevent memory leak
	if (str != NULL)
		delete[] str;
	len = s.len;
	str = new char[len];
	strcpy(str, s.str);
	return *this;
}

String& String::operator+=(const String& s) {
	len += (s.len - 1);
	char* tempstr = new char[len];
	strcpy(tempstr, str);
	strcat(tempstr, s.str);

	if (str != NULL)
		delete[] str;
	str = tempstr;
	return *this;
}

bool String::operator==(const String& s) {
	return strcmp(str, s.str) ? false : true;
}

String String::operator+(const String& s) {//피연산자(operand)의 값을 변경하는 함수가 아니므로 const선언
	char* tempstr = new char[len + s.len - 1];//문자열의 끝을 알리는 NULL이 두 번 들어가므로 1을 빼줘야 함
	strcpy(tempstr, str);
	strcat(tempstr, s.str);

	String temp(tempstr);
	delete[] tempstr;
	return temp;
}

ostream& operator<<(ostream& os, const String& s) {
	os << s.str;
	return os;
}

istream& operator>>(istream& is, String& s) {
	char str[100];
	is >> str;
	s = String(str);
	return is;
}


int main() {
	String str1 = "I like ";
	String str2 = "custom String class";
	String str3 = str1 + str2;

	cout << str1 << '\n';
	cout << str2 << '\n';
	cout << str3 << '\n';
	str1 += str2;

	if (str1 == str3)
		cout << "Same string\n";
	else
		cout << "Different string\n";

	String str4;
	cout << "Enter string: ";
	cin >> str4;
	cout << "String entered: " << str4 << '\n';

	return 0;
}
