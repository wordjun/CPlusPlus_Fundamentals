#include<iostream>
using namespace std;

class SinivelCap {
public:
	void Take() const {
		cout << "�๰�� ���´�.\n";
	}
};

class SneezeCap {
public:
	void Take() const {
		cout << "��ä�Ⱑ �ܴ´�.\n";
	}
};

class SnuffleCap {
public:
	void Take() const {
		cout << "�ڰ� �� �ո���.\n";
	}
};

class CONTAC600 {//ĸ��ȭ�� �ڰ���� Ŭ����
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
	//Encaps1���� ��������
	CONTAC600 contac;
	ColdPatient p1;
	p1.TakeCONTAC600(contac);
}