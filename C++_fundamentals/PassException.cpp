#include<iostream>
using namespace std;

void Divide(int n1, int n2) {
	if (n2 == 0)
		throw n2;//���ܵ����� ����
	cout << "quotient: " << n1 / n2 << '\n';
	cout << "remainder: " << n1 % n2 << '\n';
}

int main() {
	int n1, n2;
	cout << "enter two numbers: ";
	cin >> n1 >> n2;

	try {
		Divide(n1, n2);//�Լ�ȣ��
		cout << "Finished division\n";
	}
	catch (int expn) {
		cout << "dividend cannot be "<< expn<<'\n';
		cout << "restart program\n";
	}
}