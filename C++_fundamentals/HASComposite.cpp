#include<iostream>
#include<cstring>
using namespace std;

class Gun {
private:
	int bullet;//ÀåÀüµÈ ÃÑ¾Ë ¼ö
public:
	Gun(int bnum)
		:bullet(bnum) {}
	void Shot() {
		cout << "BBANG\n";
		bullet--;
	}
	int getBullets() const {
		return bullet;
	}
};

class Police {
private:
	int handcuffs;
	Gun* pistol;
public:
	Police(int bnum, int bcuff) 
	:handcuffs(bcuff) {
		if (bnum > 0)
			pistol = new Gun(bnum);
		else
			pistol = NULL;
	}
	void putHandCuff() {
		cout << "Snap\n";
		handcuffs--;
	}
	void Shot() {
		if (pistol == NULL)
			cout << "Hut BBANG\n";
		else
			pistol->Shot();
	}
	void ShowInfo() const {
		cout << "bullets: " << pistol->getBullets() << '\n';
		cout << "handcuffs: " << handcuffs << '\n';
	}
	~Police() {
		if (pistol != NULL)
			delete pistol;
	}
	Police& operator=(const Police& ref) {
		//memory leak ¹æÁö
		if (pistol != NULL)
			delete pistol;
		if (ref.pistol != NULL)
			pistol = new Gun(*(ref.pistol));
			//pistol = new Gun(ref.pistol->getBullets());
		else
			pistol = NULL;

		cout << "Police operator=(ref) called:\n";
		handcuffs = ref.handcuffs;
		return *this;
	}
};

int main() {
	Police pman1(0, 3);//ÃÑ¾Ë°³¼ö, ¼ö°©°³¼ö
	pman1.Shot();//ÃÑ¾ËÀÌ ¾ø´Ù¸é Çê»§
	pman1.putHandCuff();
	Police pman2(4, 7);
	pman1 = pman2;
	pman1.Shot();
	pman1.ShowInfo();
	pman2.ShowInfo();
}