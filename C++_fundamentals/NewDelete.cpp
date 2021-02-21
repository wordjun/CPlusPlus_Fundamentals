#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

//C언어 스타일의 동적할당
char* makeStrAdr1(int len) {
	//문자열 저장을 위한 배열을 힙 영역에 할당하고 있다
	char* str = (char*)malloc(sizeof(char) * len);//char형 * 길이(len)만큼 할당
	return str;
}
//C++언어 스타일의 동적할당
char* makeStrAdr2(int len) {
	char* str = new char[len];
	return str;
}


int main(void) {
	//할당할 대상의 정보를 무조건 바이트 크기단위로 전달해야 함
	//반환형이 void형 포인터이기 때문에 적절한 형변환(char*, 캐스팅)이 필요하다.
	char* str = makeStrAdr1(20);
	strcpy_s(str, 20, "Im so happy");
	cout << str << '\n';
	free(str);//heap에 할당되었던 메모리 공간을 해제(소멸)한다

	char* newStr = makeStrAdr2(20);
	strcpy_s(newStr, 20, "This is the new string.");
	cout << newStr << '\n';
	delete []newStr;//배열의 형태로 할당된 메모리공간의 해제
	return 0;
}