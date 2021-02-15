#include<iostream>
#include<time.h>
using namespace std;
//Compiler: 컴파일->빌드->실행 (translate from high to low)
//High-level language: 인간이 이해할 수 있는 수준 
//Low-level Language: 컴퓨터가 알아들을 수 있는 수준
//.exe: a binary file made of 0s and 1s
//Build by Ctrl+Shift+B

//enum: 숫자에 이름을 붙여주는 기능
enum NUM
{//아무것도 부여하지 않을 경우 0부터 1씩 차례로 값이 부여됨
	NUM_0,
	NUM_1,
	NUM_2
};

//#: 전처리기(컴파일 시간에 값이 정해짐)
#define ABSOLUT 100

enum SRP {
	//가위1, 바위2, 보3
	SRP_S = 1,
	SRP_R,//2
	SRP_P,//3
	QUIT
};

string srp[4];

int player = 0;
void Computer();

int main() {
	////std: a namespace. 
	////namespace: 이름 중복을 허용하지 않기 때문에 이를 피하기 위함
	////C++ 표준기능의 대부분은 std라는 namespace 안에 존재. 이름 중복을 방지
	////cout: print string on console
	//std::cout << "Hello world." << '\n';
	//bool flag = false;
	//int randNum = 0;
	//srand((unsigned int)time(0));
	//if (!flag) {
	//	cout << "flag is false.\n";
	//	cout << rand() % 100 << '\n';
	//	cout << (rand() % 10000 / 1000.f) << '\n';
	//}
	//cout << NUM_1 << '\n';

	////열거체 타입의 변수를 선언
	////단, 열거체 타입 변수는 무조건 4B를 차지.
	//NUM eNum = (NUM)10;
	//cout << "eNum: " << eNum << '\n';
	//cout << sizeof(eNum) << '\n';

	srp[SRP_S] = "SCISSOR";
	srp[SRP_R] = "ROCK";
	srp[SRP_P] = "PAPER";

	system("cls");

	srand((unsigned int)time(0));

	
	
	while (true) {
		cout << "1. Scissor\n";
		cout << "2. Rock\n";
		cout << "3. Paper\n";
		cout << "4. Quit\n";

		cin >> player;
		if(player >=1 && player <= 3)
			Computer();
		else if(player == 4) {
			cout << "QUITTING GAME.\n";
			break;
		}
		else {
			cout << "WRONG NUMBER ENTERED\n";
		}
	}
	return 0;
}

void Computer() {
	unsigned int computer;
	computer = rand() % 3 + 1;
	int winner = player - computer;
	//player - computer
	//ROCK - PAPER = 2 - 3 = -1, winner: computer
	//SCISSOR - PAPER = 1 - 3 = -2, winner: player
	//PAPER - ROCK = 3 - 2 = 1, winner: player
	//SCISSOR - ROCK = 1 - 2 = -1, winner: computer
	//ROCK - SCISSOR = 2 - 1 = 1, winner: player
	//PAPER - SCISSOR = 3 - 1 = 2, winner: computer

	//conclusion:
	//if winner == -1 || winner == 2, computer wins.
	//if winner == -2 || winner == 1, player wins.
	//if winner == 0, then draw

	cout << "PLAYER: " << srp[player] << ", COMPUTER: " << srp[computer] << '\n';
	if (!winner) {
		cout << "DRAW.\n\n";
	}
	else {
		if (winner == -1 || winner == 2) {
			cout << "COMPUTER WINS\n";
		}
		else 
			cout << "PLAYER WINS\n";
	}
}