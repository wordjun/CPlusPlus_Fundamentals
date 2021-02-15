#include<iostream>
using namespace std;

struct _tagStudent {
	int stdId;
	int English;
	int Mathematics;
	int Science;
};

int main() {
	//일반 변수-일반적인 값을 저장
	//포인터: (다른 변수의)메모리주소를 저장
	//모든 변수타입은 포인터타입을 선언할 수 있음.
	//x86으로 개발 시 4byte, x64로 개발 시 8byte가 나옴
	//포인터는 스스로 아무일도 할 수 없음.

	int num = 100;
	/*
	포인터 변수는 선언 시 앞에 별(*)을 붙여준다.
	변수 앞에 ampersand(&)를 붙이면 해당 변수의 메모리주소가 된다
	p는 num변수의 메모리 주소를 값으로 갖게 된다.(&num)
	따라서 p를 이용해 num의 값을 제어할 수 있게 된다.
	*/
	int* p = &num;

	/*cout << sizeof(int*) << '\n';
	cout << sizeof(char*) << '\n';
	cout << sizeof(double) << '\n';*/

	
	

	cout << *p << '\n';
	cout << p << '\n';
	cout << &p << '\n';

	//역참조: 포인터변수 앞에 *를 붙여 사용
	*p = 1234;
	cout << num << '\n';
	cout << &num << '\n';
	cout << "============" << '\n';
	/*
	포인터와 배열의 관계: 배열명은 포인터.
	*/
	int arr[10] = {
		1, 2, 3, 
		4, 5, 6, 
		7, 8, 9};
	
	
	int* pB = arr;
	cout << arr << '\n';//배열명 자체(arr)가 메모리에서의 배열의 첫 메모리 주소가 된다
	cout << pB << '\n';//포인터변수 pB는 배열 arr의 첫번째 메모리주소값을 갖는다
	cout << &arr[0] << '\n';//arr의 첫번째 메모리 주소값

	cout << &pB[2] << '\n';//포인터변수 pB의 세번째 메모리주소값
	cout << pB + 2 << '\n';//포인터변수 pB에 +2연산을 한 값

	cout << *(pB + 2) << '\n';//(pB+2)라는 메모리주소에 들어있는 값을 역참조(*)
	cout << *pB + 3 << '\n';

	//내부적으로 const속성을 갖는다
	const char *pStr = "Test String";
	cout << pStr << '\n';
	cout << (int*)pStr << '\n';

	pStr = "abcd";
	cout << pStr << '\n';
	cout << (int*)pStr << '\n';

	pStr = "abcd";//같은 문자열 사용 시 내부적으로 배열을 잡는 메모리 공간이 같고,
	cout << pStr << '\n';
	cout << (int*)pStr << '\n';

	pStr = "abcdefgh";//다른 문자열 사용 시 내부적으로 배열을 잡는 메모리 공간이 달라진다
	//abcd와 전혀 다른 문자열이므로 다른 메모리공간에 할당됨(각 문자열마다 상수주소가 잡힘)
	cout << pStr << '\n';
	cout << (int*)pStr << '\n';

	pStr = "Test String";
	cout << pStr << '\n';
	cout << (int*)pStr << '\n';

	char str[8] = "abcdefg";
	cout << str << '\n';
	cout << &str << '\n';
	cout << (int*)str << '\n';
	cout << (int*)&str[0] << '\n';


	//포인터의 역할을 설명하시오.
	//포인터는 다른 변수의 메모리주소값을 갖게 되고,
	//해당 메모리주소를 알고 있기 때문에 그에 접근하여 값을 manipulate할 수 있다.
	_tagStudent tStudent = {};
	tStudent.English = 100;
	cout << tStudent.English << '\n';

	_tagStudent* pStd = &tStudent;

	//연산자 우선순위때문에 .을 먼저 인식
	//메모리주소.은 잘못된 문법 -> *pStd를 괄호로 감싸준 후에 .을 이용해 멤버변수 접근
	pStd->English = 50;
	cout << pStd->English << '\n';
	cout << (*pStd).English << '\n';
	cout << &pStd->English << '\n';
	//구조체 포인터는 멤버변수를 위와 같이 접근한다.

	//void pointer: no type.
	//int *pStd2 = &tStudent;
	//void의 포인터타입을 활용할 수 있게 됨
	//그 어느 타입의 메모리 주소든 모두 저장가능 (void*)
	void* pStd2 = &tStudent.English;
	//단, 역참조 불가, 메모리주소만 저장가능
	cout << pStd2 << '\n';
	//cout << *pStd2 << '\n';
	//역참조가 불가능하기때문에(*pStd2 사용불가) 타입형변환을 통해 값을 변경한다
	int* pConvert = (int*)pStd2;
	*pConvert = 1000001;
	//혹은 다음과 같이 변경가능
	*((int*)pStd2) = 101;
	cout << tStudent.English << '\n';

	int a1= 1111;
	int a2 = 2222;
	int* p = &a2;
	//이중포인타: *을 2개 붙임.
	//일반 포인터변수: 일반 변수의 메모리변수를 저장하는 변수
	//이중포인터: 포인터의 포인터. 즉 포인터변수의 메모리주소를 저장하는 포인터
	int** pp = &p;
	*p = 1234;
	cout << a2 << '\n';
	cout << &a2 << '\n';
	cout << *p << '\n';//*을 붙여 역참조하면 해당 포인터가 가리키고 있는 메모리주소의 대상의 값/
	cout << p << '\n';
	cout << &p << '\n';
	cout << **pp << '\n';//이중포인터 역시 **을 통해 역참조하게 되면 가리키는 대상의 값
	cout << *pp << '\n';
	cout << pp << '\n';
	cout << &pp << '\n';
	return 0;
}