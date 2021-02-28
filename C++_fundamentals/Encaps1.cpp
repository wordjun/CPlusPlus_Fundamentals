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

class ColdPatient {
public:
	void TakeSinivelCap(const SinivelCap& cap) const {
		cap.Take();
	}

	void TakeSneezeCap(const SneezeCap& cap) const {
		cap.Take();
	}

	void TakeSnuffleCap(const SnuffleCap& cap) const {
		cap.Take();
	}
};

int main() {
	SinivelCap scap;
	SneezeCap zcap;
	SnuffleCap ncap;

	ColdPatient p1;
	p1.TakeSinivelCap(scap);
	p1.TakeSneezeCap(zcap);
	p1.TakeSnuffleCap(ncap);
}