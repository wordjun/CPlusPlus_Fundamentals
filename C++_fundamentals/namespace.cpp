#include<iostream>

namespace BestComImpl {
	/*void simpleFunc(void) {
		std::cout << "BestCom's simpleFunc\n";
	}*/
	void simpleFunc(void);//�Լ��� ���� ����
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

//��������
int val = 100;

int simpleFunc(void) {
	int val = 20;//��������
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

	//HybFunc�� �̸����� Hybrid���� ã����
	using Hybrid::HybFunc;

	std::cout << AAA::BBB::CCC::n1 << ' ' << AAA::BBB::CCC::n2 << '\n';
	//namespace�� ��Ī�ֱ�
	namespace ABC = AAA::BBB::CCC;
	std::cout << ABC::n1 << ' ' << ABC::n2 << '\n';


	simpleFunc();
}

//�� namespace�� �Լ��� ����
void BestComImpl::simpleFunc() {
	std::cout << "BestCom's simpleFunc\n";
}

void ProgComImpl::simpleFunc() {
	std::cout << "ProgCom's simpleFunc\n";
}