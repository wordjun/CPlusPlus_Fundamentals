#include<iostream>
#include<cstring>
#include"RacingCar.h"
#pragma warning(disable:4996)

using namespace std;

void CarClass::InitMembers(char* ID, int fuel) {
	strcpy(gamerID, ID);
	fuelGauge = fuel;
	curSpeed = 0;
}

void CarClass::accelCar() {
	if (fuelGauge <= 0)
		return;
	else
		fuelGauge -= CAR_CONST::FUEL_STEP;

	if (curSpeed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD) {
		curSpeed = CAR_CONST::MAX_SPD;
		return;
	}
	curSpeed += CAR_CONST::ACC_STEP;
}

//void CarClass::breakCar() {
//	if (curSpeed < CAR_CONST::BRK_STEP) {
//		curSpeed = 0;
//		return;
//	}
//	curSpeed -= CAR_CONST::BRK_STEP;
//}

//struct Car {
//	
//	char gamerID[CAR_CONST::ID_LEN];
//	int fuelGauge;
//	int curSpeed;
//	//구조체내부에 함수가 정의돼 있으면 함수를 인라인으로 처리한다.
//	void showCarState();//상태정보 출력
//	void accelCar();//엑셀, 속도증가
//	void breakCar();//브레이크, 속도감소
//};
//
//void Car::showCarState() {
//	cout << "GamerID: " << gamerID << '\n';
//	cout << "Fuel Gauge: " << fuelGauge << '\n';
//	cout << "Current Speed: " << curSpeed << '\n';
//	cout << '\n';
//}
//
//void Car::accelCar() {
//	if (fuelGauge <= 0)
//		return;
//	else
//		fuelGauge -= CAR_CONST::FUEL_STEP;
//
//	if (curSpeed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD) {
//		curSpeed = CAR_CONST::MAX_SPD;
//		return;
//	}
//	curSpeed += CAR_CONST::ACC_STEP;
//}
//
//void Car::breakCar() {
//	if (curSpeed < CAR_CONST::BRK_STEP) {
//		curSpeed = 0;
//		return;
//	}
//	curSpeed -= CAR_CONST::BRK_STEP;
//}
//
//
//int main() {
//	Car c1 = { "car 1", 100, 0 };
//	c1.accelCar();
//	c1.accelCar();
//	c1.showCarState();
//	c1.breakCar();
//	c1.showCarState();
//
//	Car c2 = { "car 2", 100, 0 };
//	c2.accelCar();
//	c2.breakCar();
//	c2.showCarState();
//
//
//	CarClass c3;
//	c3.InitMembers((char*)"car3", 100);
//	c3.accelCar();
//	c3.accelCar();
//	c3.accelCar();
//	c3.showCarState();
//	c3.breakCar();
//	c3.showCarState();
//	return 0;
//
//}