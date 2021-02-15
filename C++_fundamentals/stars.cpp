#include<iostream>
using namespace std;

int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j <= i; j++) {
			cout << '*';
		}
		cout << '\n';
	}
	cout << '\n';

	for (int i = 5; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			cout << '*';
		}
		cout << '\n';
	}

	/*
	   *   
	  ***
	 *****
	*******
	index(i): 0->1->2->3
	space: 3->2->1->0
	stars: 1->3->5->7
	   */
	cout << '\n';
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3-i; j++) {//space
			cout << " ";
		}

		for (int j = 0; j < (i * 2) + 1;j++ ) {//stars
			cout << '*';
		}
		cout << '\n';
	}
	cout << '\n';

	/*
		*
	   ***
	  ***** 
	 ******* 
	  *****
	   ***
	    * 
	
	index: 0, 1, 2, 3, 4, 5, 6
	space: 3, 2, 1, 0, 1, 2, 3
	stars: 1, 3, 5, 7, 5, 3, 1
	*/
	int line = 50;
	//for (int i = 0; i < line; i++) {
	//	
	//	if (i > 3) {//for i = 4, 5, 6
	//		int newIndex = (-2 * i) + 13;
	//		for (int j = 0; j < i - 3; j++) {
	//			cout << ' ';
	//		}
	//		for (int j = newIndex; j > 0 ; j--) {
	//			cout << '*';
	//		}
	//		cout << '\n';
	//	}
	//	else {//for i = 0, 1, 2, 3
	//		for (int j = 0; j < 3 - i; j++) {
	//			cout << ' ';
	//		}
	//		for (int j = 0; j < i * 2 + 1; j++) {
	//			cout << '*';
	//		}
	//		cout << '\n';
	//	}
	//}
	cout << '\n';
	int count = 0;
	for (int i = 0; i < line; i++) {
		count = i;
		if (i > line/2) {//i = 4, 5, 6
			count = line - 1 - i;//count = 2, 1, 0
		}
		for (int j = 0; j < line/2 - count; j++) {
			cout << ' ';
		}

		for (int j = 0; j < (count * 2) + 1; j++)
			cout << '*';
		cout << '\n';
	}

	return 0;
}