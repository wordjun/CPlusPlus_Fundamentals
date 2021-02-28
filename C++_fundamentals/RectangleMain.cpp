#include"Rectangle.h"
#include"Point.h"
#include<iostream>
using namespace std;

int main(void) {
	/*Point p1;
	if (!p1.InitMembers(-2, 4))
		cout << "POINT Initialization failed.\n";

	cout << '\n';

	if (!p1.InitMembers(2, 4))
		cout << "POINT Initialization failed.\n";

	cout << '\n';

	Point p2;
	if (p2.InitMembers(5, 9))
		cout << "POINT Initialization failed.\n";

	cout << '\n';

	Rectangle r1;
	if(!r1.InitMembers(p1, p2))
		cout<< "RECTANGLE Initialization failed.\n";

	cout << '\n';

	if (!r1.InitMembers(p2, p1))
		cout << "RECTANGLE Initialization failed.\n";*/

	Rectangle rec1(1, 1, 5, 5);
	rec1.ShowRectInfo();
	return 0;
}