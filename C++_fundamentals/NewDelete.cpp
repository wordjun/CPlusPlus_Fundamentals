#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

//C��� ��Ÿ���� �����Ҵ�
char* makeStrAdr1(int len) {
	//���ڿ� ������ ���� �迭�� �� ������ �Ҵ��ϰ� �ִ�
	char* str = (char*)malloc(sizeof(char) * len);//char�� * ����(len)��ŭ �Ҵ�
	return str;
}
//C++��� ��Ÿ���� �����Ҵ�
char* makeStrAdr2(int len) {
	char* str = new char[len];
	return str;
}


int main(void) {
	//�Ҵ��� ����� ������ ������ ����Ʈ ũ������� �����ؾ� ��
	//��ȯ���� void�� �������̱� ������ ������ ����ȯ(char*, ĳ����)�� �ʿ��ϴ�.
	char* str = makeStrAdr1(20);
	strcpy_s(str, 20, "Im so happy");
	cout << str << '\n';
	free(str);//heap�� �Ҵ�Ǿ��� �޸� ������ ����(�Ҹ�)�Ѵ�

	char* newStr = makeStrAdr2(20);
	strcpy_s(newStr, 20, "This is the new string.");
	cout << newStr << '\n';
	delete []newStr;//�迭�� ���·� �Ҵ�� �޸𸮰����� ����
	return 0;
}