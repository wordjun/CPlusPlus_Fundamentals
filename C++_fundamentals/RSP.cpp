#include<iostream>
#include<time.h>
using namespace std;
//Compiler: ������->����->���� (translate from high to low)
//High-level language: �ΰ��� ������ �� �ִ� ���� 
//Low-level Language: ��ǻ�Ͱ� �˾Ƶ��� �� �ִ� ����
//.exe: a binary file made of 0s and 1s
//Build by Ctrl+Shift+B

//enum: ���ڿ� �̸��� �ٿ��ִ� ���
enum NUM
{//�ƹ��͵� �ο����� ���� ��� 0���� 1�� ���ʷ� ���� �ο���
	NUM_0,
	NUM_1,
	NUM_2
};

//#: ��ó����(������ �ð��� ���� ������)
#define ABSOLUT 100

enum SRP {
	//����1, ����2, ��3
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
	////namespace: �̸� �ߺ��� ������� �ʱ� ������ �̸� ���ϱ� ����
	////C++ ǥ�ر���� ��κ��� std��� namespace �ȿ� ����. �̸� �ߺ��� ����
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

	////����ü Ÿ���� ������ ����
	////��, ����ü Ÿ�� ������ ������ 4B�� ����.
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