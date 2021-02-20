#include<iostream>
using namespace std;

//2개의 정수를 인자로 요구.
//따라서 call-by-value 기반의 함수이다
//그러나 call-by-value의 형태로 정의된 함수 내부에선 함수 외부에 선언된 변수에
//접근이 불가능함.
int Adder(int n1, int n2) {
	return n1 + n2;
}

void swap(int n1, int n2) {
	int temp = n1;
	n1 = n2;
	n2 = temp;
}

//call-by-reference: 2개의 주소값을 인자로 받음.
//그 주소값이 참조하는 영역에 저장된 값을 직접 변경한다.
void swap(int* n1, int* n2) {
	int temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

void swapByRef(int& ref1, int& ref2) {
	int temp = ref1;//참조자 ref1은 main함수에서 val1을 가리키고 있기 때문에 ref1은 val1의 값과 동일하다
	ref1 = ref2;
	ref2 = temp;
}

//참조자를 이용한 call-by-reference
	//c++에서는 최소한 함수의 원형은 확인해야 함. 따라서 참조자 기반의 함수정의를 하지 말아야 함
	//const를 사용하여 이를 어느정도 극복가능
void happyFunc(const int& ref) {
	//코드분석과정에서 함수의 호출문장만 보고도 함수의 특성을 어느정도 판단할 수 있어야 함
	//허나 참조자의 경우 함수의 원형을 확인해야 하고, 참조자가 매개변수의 선언에 와있다면 함수의 몸체까지 문장단위로 확인해야 함(참조자를 통한 값 변경 유무확인)
	//따라서 참조자 매개변수 앞에 const를 붙여주면 해당 함수 내에서 참조자 ref를 이용한 값변경은 않겠다는 의미를 부여한다.
	//ref = 20;

	//함수 내에서 참조자를 통한 값의 변경을 진행하지 않을 경우 참조자를 const로 선언하여 함수의 원형만 봐도 값변경이 이뤄지지않음을 명시한다.
}

int main() {
	//참조자는 자신이 참조하는 변수를 대신할 수 있는 또 하나의 이름
	int num1 = 1020;
	int& num2 = num1;

	num2 = 3047;
	cout << "VAL: " << num1 << '\n';
	cout << "REF: " << num2 << '\n';

	//주소 역시 동일하다
	cout << "VAL: " << &num1 << '\n';
	cout << "REF: " << &num2 << '\n';

	//참조자는 변수를 대상으로만 선언이 가능하다. 변수에 별명을 하나 붙여주는 꼴이다.
	//그러나 선언과 동시에 무조건 변수를 참조하도록 해야한다
	//참조자의 수에는 제한이 없으며 참조자를 대상으로도 참조자 선언이 가능하다.
	int n1 = 2759;
	int& n2 = n1;
	int& n3 = n1;

	int num = 12;
	int* ptr = &num;
	int** dptr = &ptr;
	cout << "num: " << num << ", &num: " << &num << '\n';
	cout << "*ptr: " << *ptr <<", ptr: "<<ptr<< ", &ptr: " << &ptr << '\n';
	cout << "**dptr: " << **dptr << ", *dptr: " << *dptr << ", dptr: " << dptr <<", &dptr: "<<&dptr<<'\n';

	int& ref = num;
	int* (&pref) = ptr;//포인터 변수 ptr의 참조자이므로 변수 num에 저장된 값이 출력됨
	int** (&dpref) = dptr;//포인터 변수 dptr의 참조자이므로 변수 num에 저장된 값이 출력됨.

	cout << ref << '\n';
	cout << *pref << '\n';
	cout << "pref: " << pref << ", &pref: " << &pref << '\n';
	cout << **dpref << '\n';
	cout << "*dpref: " << *dpref << ", dpref: " << dpref << ", &dpref: "<< &dpref<<'\n';

	//call by value & vall by reference
	int a = 1, b = 2;
	swap(a, b);//call by value
	cout << a << ' ' << b << '\n';
	swap(&a, &b);//call by reference
	cout << a << ' ' << b << '\n';


	int val1 = 10, val2 = 20;
	cout << val1 << ' ' << val2 << '\n';
	swapByRef(val1, val2);//매개변수로 참조자가 선언됐으니 그 인자로 참조의 대상이 될 변수를 넣으면 된다
	cout << val1 << ' ' << val2 << '\n';

	
	int z = 24;
	happyFunc(z);
	cout << z << '\n';
	return 0;
}