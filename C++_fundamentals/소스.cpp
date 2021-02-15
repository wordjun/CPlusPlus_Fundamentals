#include<iostream>
using namespace std;

int change_val(int* p) {
	*p = 3;
	return 0;
}

void change_val2(int& p) {
	p = 1;
}

int& function(int& a) {
	a = 5;
	return a;
}

int main() {
	//int number = 5;

	//cout << number << endl;
	//change_val(&number);
	//cout << number << '\n';


	////레퍼런스
	//int a = 3;
	//int& another_a = a;//a의 참조자 another_a 주소공유
	////another_a는 a의 참조자다. 
	////즉, another_a는 a의 또다른 이름이라고 컴파일러에게 알려주는 것
	////따라서 another_a에 어떤 작업을 수행하든 사실상 a에 동일한 작업을 하는것과 마찬가지
	////단, 레퍼런스는 정의 시 반드시 누구의 별명인지 명시해야함.
	////int &another_a;같은 정의는 불가능함. 레퍼런스가 한 번 별명이 되면 절대로 다른 이의 별명이 될 수 없다
	//another_a = 5;
	//cout << "a: " << a << '\n';
	//cout << "another_a: " << another_a << '\n';

	//int a1 = 10;
	//int& another_a1 = a1;//another_a1은 a의 참조자
	//int b = 3;
	//another_a1 = b;//another_a1에 대한 연산은 a1에 대한 연산을 하는것과 동일함. 따라서 a1 = b;와 같은 효과가 남

	//int a = 10;
	//int* p = &a;//포인터는 메모리 상에서 8바이트공간을 차지함.
	//int b = 3;
	//p = &b;//p는 a를 버리고 b를 가리킴

	//int& another_a = a;//another_A가 쓰이는 자리는 모두 a로 바꿔치기하면 되므로 공간할당이 필요없다.

	//int a = 6;
	//cout << a << '\n';
	//change_val2(a);//p가 정의되는 순간은 change_val2로 호출할 때이므로 사실상 int& p = a가 실행된다고 생각할 수 있다.
	//cout << a << '\n';

	//int x;
	//int& y = x;//y는 x의 또다른 별명
	//int& z = y;//z는 y의 또다른 별명, 즉 x의 또다른 별명
	//x = 1;
	//cout << x<<" " << y << " " << z << '\n';
	//y = 2;
	//cout << x << " " << y << " " << z << '\n';
	//z = 3;
	//cout << x << " " << y << " " << z << '\n';

	//int& ref = 4;//상수값 자체는 리터럴이기때문에 값을 바꿀 수 없음
	//const int& ref = 4;//상수 참조자로 선언시 리터럴 참조가능.
	//cout << ref << '\n';


	////배열의 레퍼런스
	//int arr[3] = { 1, 2, 3 };
	//int(&ref)[3] = arr;//ref가 arr을 참조하도록 함

	//ref[0] = 2;
	//ref[1] = 4;
	//ref[2] = 0;
	////ref[0]부터 ref[2]가 각각 arr[0]부터 arr[2]의 레퍼런스가 된다

	//cout << arr[0] << " " << arr[1] << " " << arr[2] << '\n';

	int b = 2;
	int c = function(b);//이시점에서 함수 function의 변수 a는 main의 b를 참조하고 있게 됨
	//따라서 function이 리턴한 참조자는 아직 살아있는 변수인 b를 계속 참조함
	//결국 c에 현재의 b값인 5를 대입하는 것과 동일한 문장이 됨
	cout << c << '\n';
}