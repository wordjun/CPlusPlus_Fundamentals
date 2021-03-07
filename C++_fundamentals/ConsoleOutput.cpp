#include<iostream>
namespace mystd {
	using namespace std;

	class ostream {
	public:
		ostream& operator<<(const char* str) {
			printf("%s", str);
			return *this;
		}
		ostream& operator << (char str) {
			printf("%c", str);
			return *this;
		}
		ostream& operator << (int num) {
			printf("%d", num);
			return *this;
		}
		ostream& operator << (double e) {
			printf("%g", e);
			return *this;
		}
		ostream& operator << (ostream& (*fp)(ostream &ostm)) {
			return fp(*this);
		}
	};
	ostream& endl(ostream& ostm) {
		ostm << '\n';
		fflush(stdout);
		return ostm;
	}
	ostream cout;
}

int main() {
	using mystd::cout;
	using mystd::endl;

	cout << "simple string";//cout.operator<<("simple string"), 이때 사용된 cout은 mystd 이름공간 내에 선언된 cout
	cout << endl;
	cout << 3.14;
	cout << endl;
	cout << 123;
	cout<<endl;
	cout << 3.14 << ", Simple String" << endl;
	endl(cout);
}