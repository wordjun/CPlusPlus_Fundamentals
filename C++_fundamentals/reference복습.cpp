#include<iostream>
using namespace std;

//포인터와 레퍼런스의 차이점

//1. 포인터는 NULL값을 허용하지만 레퍼런스는 NULL이 될 수 없다.
struct Person {
	int birthday;
};
void isBirthdayByPointer(struct Person*);
void isBirthdayByReference(struct Person&);
//위와 같이 선언된 함수가 있을때 포인터 매개변수를 갖는 함수는 
//매개변수에 접근할때 반드시 NULL여부를 체크해야함. 
//반면 레퍼런스매개변수를 갖는 함수는 
//NULL을 허용하지 않기때문에 생략이 가능하다.

//2. 포인터는 할당 때 참조대상에 대해 &연산을 통해 다른 변수의 주소값을 할당함.
//	반면, 레퍼런스는 참조대상을 그래도 할당한다.

int main() {
	int a = 10;
	int* p = &a;//포인터는 변수의 주소값을 할당받음
	int& r = a;//레퍼런스는 대상을 직접 할당, 따라서 레퍼런스는 애초에 NULL할당이 불가함.
	//또, 레퍼런스는 선언과 동시에 초기화를 반드시 해야 컴파일에러가 발생하지 않는다
	
	struct Person* peter = new Person();
	

	//포인터변수 사용 시 반드시 validation하는 과정 필요
	if (peter)
		peter->birthday = 1212;
	else
		cout << "peter is null\n";

	//하지만 포인터대신 레퍼런스 사용 시 이런문제 발생 X. 레퍼런스는 NULL을 할당할 수 없도록
	//제한되기 때문임. 포인터와 목적은 같으나 잘못된 참조로 인해 발생되는 오류를 방지하기 위해
	//고안되었다고 보면 된다.
	isBirthdayByPointer(peter);//struct Person* temp = peter, (객체 주소값을 인자로 넘겨줌)
	isBirthdayByReference(*peter);//struct Person& temp = *peter;

	//결론: 레퍼런스는 포인터를 잘못 사용해서 생기는 수많은 문제들을 최소화하기위해 등장한것.
	//레퍼런스는 제약사항이 존재하므로..
	cout << &peter << '\n';
	cout << &(*peter) << '\n';


	/*
	참조자는 자신이 참조하는 변수를 대신할 수 있는 또 하나의 이름이다.
	간단히 말해서 "별칭"이다.
	*/

	int num1 = 10;
	int& num2 = num1;//참조자는 &를 사용하여 선언한다. 이미 선언된 변수의 앞에 이 연산자가 오면
	//해당 변수의 주소값을 반환하게 되지만, 새로 선언되는 변수앞에 붙이면 참조자를 선언하게 됨.
	//따라서 num2는 num1의 또다른 이름이므로 num2에 가해지는 연산들은 그대로 num1에 동일하게 반영된다.

	//참조자는 한번 지정한 객체를 변경할 수 없으나, 포인터는 "변수"이다. 계속해서 주소값을 바꿀 수 있다.

	//const와 포인터
	int val1 = 3;
	const int* ptr = &val1;
	val1 = 4;
	//*ptr = 6;//const변수에 대한 포인터는 자신이 가리키는 변수(val1)를 const로 여기기때문에 그 포인터를 통해
	//해당 변수를 수정할 수 없다.

	//const변수와 같이 초기화 후에 변경할 수 없는 const포인터를 선언할 수 있다.
	int val2 = 7;
	int* const ptr2 = &val2;//해당 const포인터 ptr2는 초기화 이후 다른 변수의 포인터로 변경될 수 없지만
	//현재 가리키고 있는 val2의 값은 변경할 수 있다.
	*ptr2 = 90;

	//따라서 위 두개를 같이 사용하면 const값을 가리키는 const포인터는 
	//초기화 이후 변경불가(다른변수 가리키도록 변경X)에다가,
	//초기화 때 가리키고 있던 변수의 값을 포인터를 통해 변경할 수도 없다.
	const int* const ptr3 = &val2;



}

void isBirthdayByPointer(Person* ref) {
	cout << "birthday by pointer: " << ref->birthday << '\n';
}

void isBirthdayByReference(Person& ref) {
	cout << "birthday by reference: " << ref.birthday << '\n';
}