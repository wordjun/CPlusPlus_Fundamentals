#include<iostream>
using namespace std;

class AAA {
private:
	int num;
public:
	AAA() :
		num(0) {
		//Ŭ������ �ܺο��� �� �����ڸ� ������� ��ü�� �����ؾ� ��.
	}

	//�Լ� ������ 18�࿡ ���ǵ� private�����ڸ� ���� AAA��ü�� ���� �� ��ȯ��.
	AAA& CreateInitObj(int n) const {
		//�����Ҵ�->�� ������ ������ ��ü�� ������ ���·� ��ȯ�ϰ� ����(AAA&)
		//���� �Ҵ�� �޸� ������ ������ �����Ͽ�, �����ڸ� ���� ������ �����ϴ�
		AAA* ptr = new AAA(n);//18�࿡ ���ǵ� ������ ���
		return *ptr;
	}

	
private:
	AAA(int n)
		:num(n) {

	}
};