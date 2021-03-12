#include<iostream>
using namespace std;

template <typename T>
T Max(T a, T b) {
	return a > b ? a : b;
}

//함수템플릿 Max를 char*형에 대해 특수화: char*형 함수는 이렇게 정의가 되어 있으니,
//char*형 템플릿 함수가 필요한 경우 새로 생성하지 말고 이 함수를 쓰라는 뜻
template<>
char* Max<char*>(char* a, char* b) {
	cout << "char* Max<char*>(char *a, char *b)\n";
	return strlen(a) > strlen(b) ? a : b;
}

template<>
const char* Max<const char*>(const char* a, const char* b) {//<>는 생략가능하지만 가급적 명시하는편이 좋다
	cout << "const char* Max<char*>(const char *a, const char *b)\n";
	return strlen(a) > strlen(b) ? a : b;
}

int main()
{
	cout << Max(11, 15) << '\n';
	cout << Max('A', 'C') << '\n';
}