#include<iostream>
using namespace std;

int main() {
	int n1, n2;
	cout << "enter two numbers: ";
	cin >> n1 >> n2;

	//try블록 내에서 예외발생시, 예외가 발생한 지점 이후의 나머지 try영역은 건너뛴다
	try {//try블록을 만나면 그 안에 삽입된 코드가 실행됨.
		if (n2 == 0)//예외발생
			throw n2;//밑에 두줄 건너뛰고  catch로 jump
		//예외가 발생하지 않아 아래 두줄 실행하고 나면
		//catch블록은 건너뛰고 end of main실행
		cout << "quotient: " << n1 / n2 << '\n';
		cout << "remainder: " << n1 % n2 << '\n';
	}
	catch (int expn) {//throw에서 던진 n2의 값이 catch에서 받아진다
		cout << "dividend cannot be zero.\n";
		cout << "restart program\n";
	}
	cout << "End of main\n";
}