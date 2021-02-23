#pragma once
//��������� �ߺ����� ������ �ذ��ϱ� ���� ��ũ�� ����
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

//�����ϰ������� �Լ��� ȣ�� ���� �ִ� ���� �Լ��� ��ü�κ��� ���Եž� �ϹǷ� inline�Լ��� ������Ͽ� �����Ѵ�.
//breakCar()�Լ��� �ζ��� �Լ��̹Ƿ�, �ش��Լ��� ȣ�⹮���� �����Ϸ��� ���� breakCar()�Լ��� ��ü�� ��ü�ž� �Ѵ�.
//���� �ζ��� �Լ��� Ŭ������ ����� ������ ���Ͽ� ����� �����Ϸ��� ���ÿ� ������ �� �ְ� �ؾ� �Ѵ�.

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
