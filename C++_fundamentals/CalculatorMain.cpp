#include"Calculator.h"

int main() {
	Calculator cal1;
	cal1.Init();
	std::cout << cal1.Add(3.2, 2.4) << '\n';
	std::cout << cal1.Div(3.5, 1.7) << '\n';
	std::cout << cal1.Sub(2.2, 1.5) << '\n';
	std::cout << cal1.Div(4.9, 1.2) << '\n';
	cal1.ShowOpCount();
	return 0;
}