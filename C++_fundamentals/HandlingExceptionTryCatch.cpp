#include<iostream>
using namespace std;

int main() {
	int n1, n2;
	cout << "enter two numbers: ";
	cin >> n1 >> n2;

	//try��� ������ ���ܹ߻���, ���ܰ� �߻��� ���� ������ ������ try������ �ǳʶڴ�
	try {//try����� ������ �� �ȿ� ���Ե� �ڵ尡 �����.
		if (n2 == 0)//���ܹ߻�
			throw n2;//�ؿ� ���� �ǳʶٰ�  catch�� jump
		//���ܰ� �߻����� �ʾ� �Ʒ� ���� �����ϰ� ����
		//catch����� �ǳʶٰ� end of main����
		cout << "quotient: " << n1 / n2 << '\n';
		cout << "remainder: " << n1 % n2 << '\n';
	}
	catch (int expn) {//throw���� ���� n2�� ���� catch���� �޾�����
		cout << "dividend cannot be zero.\n";
		cout << "restart program\n";
	}
	cout << "End of main\n";
}