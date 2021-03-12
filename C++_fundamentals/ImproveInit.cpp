#include<iostream>
using namespace std;

class AAA {
private:
	int num;
public:
	AAA(int n = 0)
		:num(n) {
		cout << "AAA(int n = 0)\n";
	}
	AAA(const AAA& ref)
		:num(ref.num) {
		cout << "AAA(const AAA& ref)\n";
	}
	AAA& operator=(const AAA& ref) {
		num = ref.num;
		cout << "operator=(const AAA& ref)\n";
		return *this;
	}
};

class BBB {
private:
	AAA mem;
public:
	BBB(const AAA& ref)
		:mem(ref) {//멤버 이니셜라이저
		//AAA클래스의 복사생성자가 호출됨
		//이니셜라이저 사용시 선언과 동시에 초기화가 이뤄지는 형태로 바이너리 코드가 생성됨.
		//AAA mem=ref
		//아래보다 약간의 성능향상 기대가능
	}
};

class CCC {
private:
	AAA mem;
public:
	CCC(const AAA& ref) {
		mem = ref;//대입연산
		//AAA클래스의 복사생성자와 대입연산자가 호출됨
		//생성자의 몸체부분에서 대입연산을 통한 초기화를 진행하면, 선언과 초기화를 각각
		//별도의 문장에서 진행하는 형태로 바이너리 코드가 생성됨.
	}
};

int main() {
	AAA a(12);
	cout << '\n';
	BBB b(a);
	cout << '\n';
	CCC c(a);

}