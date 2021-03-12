#include<iostream>
using namespace std;

template <typename T>
T Max(T a, T b) {
	return a > b ? a : b;
}

//�Լ����ø� Max�� char*���� ���� Ư��ȭ: char*�� �Լ��� �̷��� ���ǰ� �Ǿ� ������,
//char*�� ���ø� �Լ��� �ʿ��� ��� ���� �������� ���� �� �Լ��� ����� ��
template<>
char* Max<char*>(char* a, char* b) {
	cout << "char* Max<char*>(char *a, char *b)\n";
	return strlen(a) > strlen(b) ? a : b;
}

template<>
const char* Max<const char*>(const char* a, const char* b) {//<>�� �������������� ������ ����ϴ����� ����
	cout << "const char* Max<char*>(const char *a, const char *b)\n";
	return strlen(a) > strlen(b) ? a : b;
}

int main()
{
	cout << Max(11, 15) << '\n';
	cout << Max('A', 'C') << '\n';
}