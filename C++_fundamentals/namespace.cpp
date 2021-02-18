#include<iostream>

namespace BestComImpl {
	/*void simpleFunc(void) {
		std::cout << "BestCom's simpleFunc\n";
	}*/
	void simpleFunc(void);//함수의 선언만 삽입
}

namespace ProgComImpl {
	/*void simpleFunc(void) {
		std::cout << "ProgCom's simpleFunc\n";
	}*/
	void simpleFunc(void);
}

namespace Parent {
	int num = 2;
	namespace subOne {
		int num = 3;
	}

	namespace subTwo {
		int num = 4;
	}
}

namespace Hybrid {
	void HybFunc(void) {
		std::cout << "hybfunc(void) called from namespace Hybrid\n";
	}
}

namespace AAA {
	namespace BBB {
		namespace CCC {
			int n1=10;
			int n2=20;
		}
	}
}

//전역변수
int val = 100;

int simpleFunc(void) {
	int val = 20;//지역변수
	val += 3;
	std::cout << val << '\n';
	::val += 3;
	std::cout << ::val << '\n';
	return 0;
}

void main() {
	//:: - scope resolution operator
	BestComImpl::simpleFunc();
	ProgComImpl::simpleFunc();

	std::cout << Parent::num << '\n';
	std::cout << Parent::subOne::num << '\n';
	std::cout << Parent::subTwo::num << '\n';

	//HybFunc를 이름공간 Hybrid에서 찾으라
	using Hybrid::HybFunc;

	std::cout << AAA::BBB::CCC::n1 << ' ' << AAA::BBB::CCC::n2 << '\n';
	//namespace에 별칭주기
	namespace ABC = AAA::BBB::CCC;
	std::cout << ABC::n1 << ' ' << ABC::n2 << '\n';


	simpleFunc();
}

//각 namespace의 함수의 정의
void BestComImpl::simpleFunc() {
	std::cout << "BestCom's simpleFunc\n";
}

void ProgComImpl::simpleFunc() {
	std::cout << "ProgCom's simpleFunc\n";
}