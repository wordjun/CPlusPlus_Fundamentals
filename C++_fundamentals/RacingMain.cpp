#include "RacingCar.h"

int main() {
	CarClass c1;
	c1.InitMembers((char*)"Mercedes", 100);
	c1.accelCar();
	c1.accelCar();
	c1.accelCar();
	c1.showCarState();
	c1.breakCar();
	c1.showCarState();
	return 0;
}