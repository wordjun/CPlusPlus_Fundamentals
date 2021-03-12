#include<iostream>
using namespace std;

template<typename T>
void ShowStaticValue() {
	static T num = 0;
	num += 1;
	cout << num << ' ';
}

template<typename T>
class SimpleStaticMem {
private:
	static T mem;
public:
	void AddMem(int num) {
		mem += num;
	}
	void ShowMem() {
		cout << mem << '\n';
	}
};

template<typename T>
T SimpleStaticMem<T>::mem = 0;//initialization of static member 'mem'

//specialization
template<>
long SimpleStaticMem<long>::mem = 5.5;
//as a result of changing 'T's to 'long's, 
//we must use template<> instead of template<typename T>

int main() {
	ShowStaticValue<int>();
	ShowStaticValue<int>();
	ShowStaticValue<int>();

	cout << '\n';

	ShowStaticValue<float>();
	ShowStaticValue<float>();
	ShowStaticValue<float>();

	//result shows that static variable "T num" is maintained for each template functions.
	cout << '\n';

	/*************************************************************************************/

	SimpleStaticMem<int> i1;
	SimpleStaticMem<int> i2;
	i1.AddMem(2);
	i2.AddMem(3);
	i1.ShowMem();//result shows that static member variables are maintained among the same template class instances.
	cout << '\n';
	//result of specialization
	SimpleStaticMem<long> l1;
	l1.ShowMem();
}