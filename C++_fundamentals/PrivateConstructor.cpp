#include<iostream>
using namespace std;

class AAA {
private:
	int num;
public:
	AAA() :
		num(0) {
		//클래스의 외부에선 이 생성자를 기반으로 객체를 생성해야 함.
	}

	//함수 내에서 18행에 정의된 private생성자를 통해 AAA객체를 생성 및 반환함.
	AAA& CreateInitObj(int n) const {
		//동적할당->힙 영역에 생성된 객체를 참조의 형태로 반환하고 있음(AAA&)
		//힙에 할당된 메모리 공간은 변수로 간주하여, 참조자를 통한 참조가 가능하다
		AAA* ptr = new AAA(n);//18행에 정의된 생성자 사용
		return *ptr;
	}

	
private:
	AAA(int n)
		:num(n) {

	}
};