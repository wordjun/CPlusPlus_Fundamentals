#include<iostream>
using namespace std;

class SinivelCap {
public:
	void Take() const {
		cout << "Äà¹°ÀÌ ³´´Â´Ù.\n";
	}
};

class SneezeCap {
public:
	void Take() const {
		cout << "ÀçÃ¤±â°¡ ¸Ü´Â´Ù.\n";
	}
};

class SnuffleCap {
public:
	void Take() const {
		cout << "ÄÚ°¡ »½ ¶Õ¸°´Ù.\n";
	}
};

class CONTAC600 {//Ä¸½¶È­µÈ ÄÚ°¨±â¾à Å¬·¡½º
private:
	SinivelCap sin;
	SneezeCap sne;
	SnuffleCap snu;
public:
	void Take() const {
		sin.Take();
		sne.Take();
		snu.Take();
	}
};

class ColdPatient {
public:
	void TakeCONTAC600(const CONTAC600& cap) const {
		cap.Take();
	}
};

int main() {
	//Encaps1º¸´Ù °£°áÇØÁü
	CONTAC600 contac;
	ColdPatient p1;
	p1.TakeCONTAC600(contac);
}