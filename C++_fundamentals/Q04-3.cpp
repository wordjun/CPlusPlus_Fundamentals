#include<iostream>
using namespace std;
#pragma warning(disable:4996)

namespace COMP_POS {
	enum  POSITION {
		CLERK,
		SENIOR,
		ASSIST,
		MANAGER
	};
}

class NameCard {
	
private:
	char* name;
	char* company;
	char* phoneNum;
	int position;
public:
	NameCard(const char*, const char*, const char*, int);
	
	void ShowNameCardInfo() const {
		cout << "Name: " << name << '\n';
		cout << "Company: " << company << '\n';
		cout << "Phone Number: " << phoneNum << '\n';
		switch (position) {
		case COMP_POS::CLERK:
			cout << "Position: Clerk\n";
			break;
		case COMP_POS::SENIOR:
			cout << "Position: Senior\n";
			break;
		case COMP_POS::ASSIST:
			cout << "Position: Assist\n";
			break;
		}
		cout << '\n';
	}

	~NameCard() {
		delete[] name;
		delete[] company;
		delete[] phoneNum;
	}
};

int main() {
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard manAssist("Kim", "soGoodComp", "010-5555-6666", COMP_POS::ASSIST);
	manClerk.ShowNameCardInfo();
	manSenior.ShowNameCardInfo();
	manAssist.ShowNameCardInfo();

	return 0;
}

NameCard::NameCard(const char* _name, const char* _company, const char* _phoneNum, int _position) {
	//성명
	int len = strlen(_name) + 1;
	name = new char[len];
	strcpy(name, _name);

	//회사이름
	len = strlen(_company) + 1;
	company = new char[len];
	strcpy(company, _company);

	//전화번호
	len = strlen(_phoneNum) + 1;
	phoneNum = new char[len];
	strcpy(phoneNum, _phoneNum);

	//직급
	position = _position;
}