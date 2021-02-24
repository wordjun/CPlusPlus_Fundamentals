#pragma once
#ifndef _CALCULATOR_H

#endif // !_CALCULATOR_H
#include<iostream>
class Calculator {
private:
	int addCnt;
	int subCnt;
	int mulCnt;
	int divCnt;
public:
	void Init();
	float Add(float n1, float n2);
	float Sub(float n1, float n2);
	float Mul(float n1, float n2);
	float Div(float n1, float n2);
	void ShowOpCount();
};

inline void Calculator::ShowOpCount() {
	std::cout << "Add: " << addCnt << " Sub: " << subCnt << " Mul: " << mulCnt << " Div: " << divCnt << '\n';
}