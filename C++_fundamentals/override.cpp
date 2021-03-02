#include"override.h"
#include<iostream>
using namespace std;

void Parent::outA(int a) {
	cout << a << '\n';
}
void Child::outA(int b) {
	cout << b + b << '\n';
}

int main() {
	//1. override하고자 하는 함수가 상위 클래스에 존재해야 함
	//2. 함수 이름이 같아야 overriding이 가능
	//3. 함수의 매개변수(parameter)개수와 자료형이 같아야 오버라이딩이 가능하다
	//4. 함수 리턴형이 같아야 함
	//5. 상위 함수와 동일하거나 내용이 추가되어야 함

	//overriding: 상속 관계간에 발생. 부모클래스에 정의된 함수와 똑같은 시그니쳐를 갖는 함수를
	//자식클래스에서 정의하여 부모클래스에서의 내용이 보이지 않게 하는것. 이를 통해 상속받은 내용 중 
	//일부를 변경하여 사용하는 것이 가능하다.

	//오버라이딩을 위해선 부모클래스에서 정의된 내용과 똑같은 이름과 인수 구성을 가져야 한다.(중요)

	Parent p1;
	p1.outA(10);

	Child c1;
	c1.outA(10);
	return 0;
}