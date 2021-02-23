#pragma once
//헤더파일의 중복포함 문제를 해결하기 위한 매크로 선언
#ifndef __CAR_H__
#define __CAR_H__

#include<iostream>
using namespace std;

namespace CAR_CONST {
	enum {
		ID_LEN = 20,
		MAX_SPD = 200,
		FUEL_STEP = 2,
		ACC_STEP = 10,
		BRK_STEP = 10
	};
}

class CarClass {
private:
	char gamerID[CAR_CONST::ID_LEN];
	int fuelGauge;
	int curSpeed;

public:
	void InitMembers(char* ID, int fuel);
	void showCarState();
	void accelCar();
	void breakCar();
};

//컴파일과정에서 함수의 호출 문이 있는 곳에 함수의 몸체부분이 삽입돼야 하므로 inline함수는 헤더파일에 정의한다.
//breakCar()함수는 인라인 함수이므로, 해당함수의 호출문장은 컴파일러에 의해 breakCar()함수의 몸체로 대체돼야 한다.
//따라서 인라인 함수는 클래스의 선언과 동일한 파일에 저장돼 컴파일러가 동시에 참조할 수 있게 해야 한다.

inline void CarClass::breakCar() {
	if (curSpeed < CAR_CONST::BRK_STEP) {
		curSpeed = 0;
		return;
	}
	curSpeed -= CAR_CONST::BRK_STEP;
}

inline void CarClass::showCarState() {
	cout << "GamerID: " << gamerID << '\n';
	cout << "Fuel Gauge: " << fuelGauge << '\n';
	cout << "Current Speed: " << curSpeed << '\n';
	cout << '\n';
}

#endif // !__CAR_H__
