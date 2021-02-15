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

		//�Է½��� �� ����ó��
		if (cin.fail()) {
			cin.clear();//empty error buffer

			//�Է¹��ۿ� \n�� ���� �����Ƿ� �Է¹��۸� �˻��� \n�� �����ش�
			//ù��°�� �˻��ϰ����ϴ� ����ũ�⸦ ����.
			//�˳��ϰ� 1024����Ʈ���� ����
			//�ι�°�� ã�����ϴ� ���ڸ� �־���
			//�Է¹��� ó������ \n�� �ִ� ������ ã�Ƽ� �׺κ��� ���
			//�����༭ �ٽ� �Է¹��� �� �ֵ��� ����
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

			//cin�� cin.getline�� ���� ����ϰ� �Ǹ� enter�� �Է¹��ۿ� ���� �ǹǷ�
			//�׳� ����Ǵ� ��찡 �߻���.

			//cin.ignore(1024, '\n');//�Է¹��� ���� �ٽ� ���� �Է� �غ�
			//cin���� �Է¹��� �� ������ ���ڿ� ������ �ν�
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