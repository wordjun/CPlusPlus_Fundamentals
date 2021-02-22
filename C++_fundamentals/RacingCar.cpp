#include<iostream>
using namespace std;

#define ID_LEN 20
#define MAX_SPD 200
#define FUEL_STEP 2
#define ACC_STEP 20
#define BRK_STEP 10

struct Car {
	char gamerID[ID_LEN];
	int fuelGauge;
	int curSpeed;
};

void showCarState(const Car& car) {
	cout << "GamerID: " << car.gamerID << '\n';
	cout << "Fuel Gauge: " << car.fuelGauge << '\n';
	cout << "Current Speed: " << car.curSpeed << '\n';
}

void accelCar(Car& car) {
	if (car.fuelGauge <= 0)
		return;
	else
		car.fuelGauge -= FUEL_STEP;

	if (car.curSpeed + ACC_STEP >= MAX_SPD) {
		car.curSpeed = MAX_SPD;
		return;
	}
	car.curSpeed += ACC_STEP;
}

void breakCar(Car& car) {
	if (car.curSpeed < BRK_STEP) {
		car.curSpeed = 0;
		return;
	}
	car.curSpeed -= BRK_STEP;
}


int main() {
	Car c1 = { "car 1", 100, 0 };
	accelCar(c1);
	accelCar(c1);
	showCarState(c1);
	breakCar(c1);
	showCarState(c1);
}