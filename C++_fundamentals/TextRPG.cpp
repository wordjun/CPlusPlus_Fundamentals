#include<time.h>
#include<iostream>
using namespace std;

enum MAIN_MENU {
	MM_NONE,
	MM_MAP,
	MM_STORE,
	MM_INVENTORY,
	MM_EXIT
};

enum MAP_TYPE {
	MT_NONE,
	MT_EASY,
	MT_NORMAL,
	MT_HARD,
	MT_BACK
};

enum PLAYER_JOB {
	JOB_NONE,
	JOB_SWORDSMAN,
	JOB_ARCHER,
	JOB_MAGE,
	JOB_END
};

enum BATTLE {
	BATTLE_NONE,
	BATTLE_ATTACK,
	BATTLE_BAIL
};

#define NAME_SIZE 32

struct _tagInventory {
	int gold;
};

struct _tagPlayer {
	char Name[NAME_SIZE];
	//문자열 비교가 정수 비교보다 더 오래걸리므로 enum타입을 통해 비교한다
	char jobName[NAME_SIZE];

	PLAYER_JOB pJob;

	int attackMin;
	int attackMax;
	int armorMin;
	int armorMax;
	int HP;
	int HPMax;
	int MP;
	int MPMax;
	int EXP;
	int Level;
	_tagInventory inventory;
};



struct _tagMonster {
	char Name[NAME_SIZE];
	int attackMin;
	int attackMax;
	int armorMin;
	int armorMax;
	int HP;
	int HPMax;
	int MP;
	int MPMax;
	int Level;
	int goldMin;
	int goldMax;
	int EXP;
};

int main() {
	srand((unsigned int)time(0));
	_tagPlayer tPlayer = {};
	cout << "Enter name: ";
	//null이 들어갈 공간을 위해 NAME_SIZE-1
	cin.getline(tPlayer.Name, NAME_SIZE-1);
	int job = JOB_NONE;
	while (job == JOB_NONE) {
		
		system("cls");
		cout << "1. Swordsman\n";
		cout << "2. Archer\n";
		cout << "3. Mage\n";
		cout << "Choose your option: ";
		cin >> job;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		else if (job <= JOB_NONE || job >= JOB_END)
			job = JOB_NONE;
	}

	//initialize player
	tPlayer.Level = 1;
	tPlayer.EXP = 0;
	tPlayer.pJob = (PLAYER_JOB)job;
	tPlayer.inventory.gold = 10000;

	switch (tPlayer.pJob) {
	case JOB_SWORDSMAN:
		strcpy_s(tPlayer.jobName, "Swordsman");
		tPlayer.attackMin = 5;
		tPlayer.attackMax = 10;
		tPlayer.armorMin = 15;
		tPlayer.armorMax = 20;
		tPlayer.HP = 500;
		tPlayer.HPMax = 500;
		tPlayer.MP = 100;
		tPlayer.MPMax = 100;
		break;
	case JOB_ARCHER:
		strcpy_s(tPlayer.jobName, "Archer");
		tPlayer.attackMin = 10;
		tPlayer.attackMax = 15;
		tPlayer.armorMin = 10;
		tPlayer.armorMax = 15;
		tPlayer.HP = 400;
		tPlayer.HPMax = 400;
		tPlayer.MP = 200;
		tPlayer.MPMax = 200;
		break;
	case JOB_MAGE:
		strcpy_s(tPlayer.jobName, "Mage");
		tPlayer.attackMin = 15;
		tPlayer.attackMax = 20;
		tPlayer.armorMin = 5;
		tPlayer.armorMax = 10;
		tPlayer.HP = 300;
		tPlayer.HPMax = 300;
		tPlayer.MP = 300;
		tPlayer.MPMax = 300;
		break;
	}

	_tagMonster tMonsterArr[MT_BACK - 1] = {};

	strcpy_s(tMonsterArr[0].Name, "Goblin");
	tMonsterArr[0].attackMin = 20;
	tMonsterArr[0].attackMax = 30;
	tMonsterArr[0].armorMin = 2;
	tMonsterArr[0].armorMax = 5;
	tMonsterArr[0].HP = 100;
	tMonsterArr[0].HPMax = 100;
	tMonsterArr[0].MP = 10;
	tMonsterArr[0].MPMax = 10;
	tMonsterArr[0].Level = 10;
	tMonsterArr[0].EXP = 1000;
	tMonsterArr[0].goldMin = 500;
	tMonsterArr[0].goldMax = 1500;

	strcpy_s(tMonsterArr[1].Name, "Troll");
	tMonsterArr[1].attackMin = 80;
	tMonsterArr[1].attackMax = 130;
	tMonsterArr[1].armorMin = 60;
	tMonsterArr[1].armorMax = 90;
	tMonsterArr[1].HP = 2000;
	tMonsterArr[1].HPMax = 2000;
	tMonsterArr[1].MP = 100;
	tMonsterArr[1].MPMax = 100;
	tMonsterArr[1].Level = 5;
	tMonsterArr[1].EXP = 7000;
	tMonsterArr[1].goldMin = 6000;
	tMonsterArr[1].goldMax = 8000;

	strcpy_s(tMonsterArr[2].Name, "Dragon");
	tMonsterArr[2].attackMin = 250;
	tMonsterArr[2].attackMax = 500;
	tMonsterArr[2].armorMin = 200;
	tMonsterArr[2].armorMax = 400;
	tMonsterArr[2].HP = 30000;
	tMonsterArr[2].HPMax = 30000;
	tMonsterArr[2].MP = 20000;
	tMonsterArr[2].MPMax = 20000;
	tMonsterArr[2].Level = 10;
	tMonsterArr[2].EXP = 30000;
	tMonsterArr[2].goldMin = 20000;
	tMonsterArr[2].goldMax = 50000;

	


	while (true) {
		system("cls");
		cout << "=====MENU=====\n";
		cout << "1. Map\n";
		cout << "2. Store\n";
		cout << "3. Inventory\n";
		cout << "4. Quit\n";
		cout << "Choose your option: ";

		int menu;
		cin >> menu;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		if (menu == MM_EXIT) {
			break;
		}

		switch (menu) {
		case MM_MAP:
			system("cls");
			cout << "=====DIFFICULTY=====\n";
			cout << "1. EASY\n";
			cout << "2. NORMAL\n";
			cout << "3. HARD\n";
			cout << "Choose your option: ";

			cin >> menu;

			if (cin.fail()) {
				cin.clear();
				cin.ignore(1024, '\n');
				continue;
			}

			//선택한 메뉴에서 1을 뺀 값이 monsterArr의 인덱스가 됨
			//해당 맵의 몬스터를 생성
			_tagMonster tMonster = tMonsterArr[menu - 1];

			while (1) {
				system("cls");
				switch (menu) {
				case MT_EASY:
					cout << "********************EASY********************\n";
					break;
				case MT_NORMAL:
					cout << "********************NORMAL********************\n";
					break;
				case MT_HARD:
					cout << "********************HARD********************\n";
					break;
				}
				cout << "===================PLAYER INFO===================\n";
				//print player's info
				cout << "Name: " << tPlayer.Name
					<< "\tJob: " << tPlayer.jobName << '\n';
				cout << "Level: " << tPlayer.Level
					<< "\tExperience Point: " << tPlayer.EXP << '\n';
				cout << "Attack Point: " << tPlayer.attackMin<<" - "
					<<tPlayer.attackMax
					<< "\tArmor: " << tPlayer.armorMin
					<< " - " << tPlayer.armorMax << '\n';
				cout << "Health Point: " << tPlayer.HP << " / " << tPlayer.HPMax
					<< "\tMana Point: " << tPlayer.MP << " / " << tPlayer.MPMax << '\n';
				cout << tPlayer.Name <<"currently has: " << tPlayer.inventory.gold << "G\n";

				cout << "\n===================MONSTER INFO===================\n";
				//print monster's info
				cout << "Name: " << tMonster.Name
					<< "\tLevel: " << tMonster.Level
					<< "\tExperience Point: " << tMonster.EXP << '\n';
				cout << "Attack Point: " << tMonster.attackMin << " - "
					<< tMonster.attackMax
					<< "\tArmor: " << tMonster.armorMin
					<< " - " << tMonster.armorMax << '\n';
				cout << "Health Point: " << tMonster.HP << " / " << tMonster.HPMax
					<< "\tMana Point: " << tMonster.MP << " / " << tMonster.MPMax << '\n';
				cout << "Gainable gold: " << tMonster.goldMin <<" - " << tMonster.goldMax
					<<"\tGainable EXP: " << tMonster.EXP <<"\n\n";


				
				cout << "1. Attack\n";
				cout << "2. Run away\n";
				cout << "Choose your option: ";

				cin >> menu;

				if (cin.fail()) {
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}
				else if (menu == BATTLE_BAIL)
					break;

				int attack = 0, armor = 0, damage = 0;

				switch (menu) {
				case BATTLE_ATTACK:
					//최소 5, 최대 10일때, 그 사이값이 나와야 함
					// (10 - 5 + 1) + 5 = 11;
					//10-5 = 5 + 1 = 6 -> 0~5사이의 값
					//거기에 + 5하면 5 ~ 10 사이의 값
					attack = rand() % (tPlayer.attackMax - tPlayer.attackMin + 1) + 
						tPlayer.attackMin;
					armor = rand() % (tMonster.armorMax - tMonster.armorMin + 1) +
						tMonster.armorMin;
					damage = attack - armor;
					damage = damage < 1 ? 1 : damage;

					//몬스터 체력 감소
					tMonster.HP -= damage;
					cout << tPlayer.Name << " dealt " << tMonster.Name
						<< " with " << damage << " amount of damage.\n";

					//routine for monster's death
					if (tMonster.HP <= 0) {
						cout << tMonster.Name << " is down.\n";

						tPlayer.EXP += tMonster.EXP;
						int gold = (rand() % 
							(tMonster.goldMax - tMonster.goldMin + 1) + tMonster.goldMin);
						tPlayer.inventory.gold += gold;
						cout << "You've gained " << tMonster.EXP << " experience points.\n";
						cout << "You've gained " << gold << "Gs.\n";
						tMonster.HP = tMonster.HPMax;
						tMonster.MP = tMonster.MPMax;
						system("pause");
						break;
					}
					//routine for monster when it's not dead (monster's turn to attack player)
					attack = rand() % (tMonster.attackMax - tMonster.attackMin + 1) +
						tMonster.attackMin;
					armor = rand() % (tPlayer.armorMax - tPlayer.armorMin + 1) +
						tPlayer.armorMin;
					damage = attack - armor;
					damage = damage < 1 ? 1 : damage;

					//플레이어 체력 감소
					tMonster.HP -= damage;
					cout << tMonster.Name << " dealt " << tPlayer.Name
						<< " with " << damage << " amount of damage.\n";

					//routine for player's death
					if (tPlayer.HP <= 0) {
						cout << tPlayer.Name << " is down.\n";

						//사망 시 보유중이었던 경험치 및 골드가 날라감
						int exp = tPlayer.EXP * 0.1f;
						int gold = tPlayer.inventory.gold * 0.1f;

						tPlayer.EXP -= exp;
						tPlayer.inventory.gold -= gold;

						cout << "You've lost " << exp << " experience points.\n";
						cout << "You've lost " << gold << " Gs.\n";
						
						tPlayer.HP = tPlayer.HPMax;
						tPlayer.MP = tPlayer.MPMax;
					}
					system("pause");
					break;
				}
			}
			break;
		case MM_STORE:
			break;
		case MM_INVENTORY:
			break;
		default:
			break;
		}
	}
}