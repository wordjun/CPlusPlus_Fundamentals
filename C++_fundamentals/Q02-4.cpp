#include<iostream>
#include<cstring>
#include<cstdlib>
#include<ctime>
using namespace std;

int main() {
	char *str = new char[256];
	strcpy_s(str, 256, "jun hyun");
	cout << strlen(str) << '\n';
	cout << strcmp(str, "jun hyun")<<endl;
	strcat_s(str, 256, " park");
	cout <<  str<< '\n';

	srand((unsigned int)time(0));//�õ�
	int* a = new int[5];
	for (int i = 0; i < 5; i++) {
		a[i] = rand() % 100;//0�̻� 100�̸��� ����
		cout << a[i] << '\n';
	}
}