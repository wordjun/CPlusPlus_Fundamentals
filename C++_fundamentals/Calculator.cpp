#include"Calculator.h"

void Calculator::Init() {
	this->addCnt = 0;
	this->subCnt = 0;
	this->mulCnt = 0;
	this->divCnt = 0;
}

float Calculator::Add(float n1, float n2) {
	this->addCnt++;
	return n1 + n2;
}

float Calculator::Sub(float n1, float n2) {
	this->subCnt++;
	return n1 - n2;
}
float Calculator::Mul(float n1, float n2) {
	this->mulCnt++;
	return n1 * n2;
}
float Calculator::Div(float n1, float n2) {
	this->divCnt++;
	return n1 / n2;
}