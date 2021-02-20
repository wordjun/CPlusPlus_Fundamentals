#include<iostream>
using namespace std;

int main() {
	//변수 num을 상수화
	const int num = 10;

	//포인터 ptr1을 이용해 val1의 값을 변경할 수 없음
	int val1 = 10, val2 = 20, val3 = 30;
	const int* ptr1 = &val1;
	ptr1 = &val2;
	//*ptr1 = 15;//"you cant assign to a variable that is const
	cout << *ptr1 << '\n';

	//포인터 ptr2가 상수화됨
	int* const ptr2 = &val2;
	//ptr2 = &val1;//"you cant assign to a variable that is const
	*ptr2 = 25;//포인터를 통한 값 변경은 가능
	cout << *ptr2 << '\n';

	//포인터 ptr3가 상수화됐으며, ptr3를 이용해 val3의 값을 변경할수 없음
	const int* const ptr3 = &val3;
	//모두 불가능
	//ptr3 = &val1;
	//*ptr3 = 35;
}