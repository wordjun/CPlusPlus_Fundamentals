#include<iostream>
using namespace std;
#define NAME_SIZE 32
#define ADDRESS_SIZE 128
#define PHONE_SIZE 14
#define STUDENT_MAX 100

struct _tagStudent {
	char stdName[NAME_SIZE];
	char stdAddress[ADDRESS_SIZE];
	char stdPhoneNum[PHONE_SIZE];
	int stdId;
	int English;
	int Mathematics;
	int Science;
	int Total;
	float fAvg;
};

enum MENU {
	REGISTER = 1,
	DELETE,
	SEARCH,
	PRINT,
	QUIT
};

int main() {
	_tagStudent tStudentArr[STUDENT_MAX] = {};
	int menu;
	int numOfStd = 0;
	char tempName[NAME_SIZE] = {};
	while (1) {
		system("cls");

		//Menu
		cout << "1. Register a student\n";
		cout << "2. Delete a student\n";
		cout << "3. Search for a student\n";
		cout << "4. Print student(s)\n";
		cout << "5. Quit program\n";
		cin >> menu;

		//입력실패 시 예외처리
		if (cin.fail()) {
			cin.clear();//empty error buffer

			//입력버퍼에 \n이 남아 있으므로 입력버퍼를 검색해 \n을 지워준다
			//첫번째엔 검색하고자하는 버퍼크기를 지정.
			//넉넉하게 1024바이트정도 지정
			//두번째는 찾고자하는 문자를 넣어줌
			//입력버퍼 처음부터 \n이 있는 곳까지 찾아서 그부분을 모두
			//지워줘서 다시 입력받을 수 있도록 해줌
			cin.ignore(1024, '\n');
			continue;
		}

		if (menu == QUIT)
			break;

		switch (menu) {
		case REGISTER:
			system("cls");
			if (numOfStd >= STUDENT_MAX)
				break;

			cout << "==================STUDENT REGISTRATION==================\n";
			cout << "\nEnter the name: ";
			//cin >> tStudentArr[numOfStd].stdName;
			cin.ignore(1024, '\n');
			cin.getline(tStudentArr[numOfStd].stdName, NAME_SIZE);

			//cin과 cin.getline을 같이 사용하게 되면 enter가 입력버퍼에 들어가게 되므로
			//그냥 진행되는 경우가 발생함.

			//cin.ignore(1024, '\n');//입력버퍼 비우고 다시 다음 입력 준비
			//cin으로 입력받을 시 공백을 문자열 끝으로 인식
			cout << "\nEnter the address: ";
			cin.getline(tStudentArr[numOfStd].stdAddress, ADDRESS_SIZE);

			cout << "\nEnter the phone number: ";
			cin.getline(tStudentArr[numOfStd].stdPhoneNum, PHONE_SIZE);

			cout << "\nEnglish: ";
			cin >> tStudentArr[numOfStd].English;

			cout << "\nMathematics: ";
			cin >> tStudentArr[numOfStd].Mathematics;

			cout << "\nScience: ";
			cin >> tStudentArr[numOfStd].Science;

			tStudentArr[numOfStd].Total = tStudentArr[numOfStd].English
				+ tStudentArr[numOfStd].Mathematics + tStudentArr[numOfStd].Science;

			tStudentArr[numOfStd].fAvg = tStudentArr[numOfStd].Total / 3.f;

			++numOfStd;

			cout << "Student registered.\n";
			break;
		case DELETE:
			system("cls");
			cout << "==================STUDENT DELETE==================\n\n";
			cout << "\nEnter the name: ";
			cin.ignore(1024, '\n');
			cin.getline(tempName, NAME_SIZE);

			for (int i = 0; i < numOfStd; i++) {
				if (!strcmp(tStudentArr[i].stdName, tempName)) {
					for (int j = i; j < numOfStd - 1; j++) {
						tStudentArr[j] = tStudentArr[j + 1];
					}
					--numOfStd;
					cout << "Student deleted.\n";
				}
			}
			break;
		case SEARCH:
			system("cls");
			cout << "==================STUDENT SEARCH==================\n\n";
			cout << "\nEnter the name: ";
			cin.ignore(1024, '\n');
			cin.getline(tempName, NAME_SIZE);

			for (int i = 0; i < numOfStd; i++) {
				if (!strcmp(tStudentArr[i].stdName, tempName)) {
					cout << "Name: " << tStudentArr[i].stdName << '\n';
					cout << "Address: " << tStudentArr[i].stdAddress << '\n';
					cout << "Phone No.: " << tStudentArr[i].stdPhoneNum << '\n';
					cout << "English: " << tStudentArr[i].English << '\n';
					cout << "Mathematics: " << tStudentArr[i].Mathematics << '\n';
					cout << "Science: " << tStudentArr[i].Science << '\n';
					cout << "Total: " << tStudentArr[i].Total << '\n';
					cout << "Average: " << tStudentArr[i].fAvg << '\n';
				}
			}
			break;
		case PRINT:
			system("cls");
			cout << "==================STUDENT INFO==================\n\n";
			for (int i = 0; i < numOfStd; i++) {
				cout << "Name: " << tStudentArr[i].stdName << '\n';
				cout << "Address: " << tStudentArr[i].stdAddress << '\n';
				cout << "Phone No.: " << tStudentArr[i].stdPhoneNum << '\n';
				cout << "English: " << tStudentArr[i].English << '\n';
				cout << "Mathematics: " << tStudentArr[i].Mathematics << '\n';
				cout << "Science: " << tStudentArr[i].Science << '\n';
				cout << "Total: " << tStudentArr[i].Total << '\n';
				cout << "Average: " << tStudentArr[i].fAvg << '\n\n';
			}
			break;
		case QUIT:
			break;
		default:
			cout << "Wrong Menu.\n";
			break;
		}
		system("pause");
	}
	return 0;
}