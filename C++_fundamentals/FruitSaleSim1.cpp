#include<iostream>
using namespace std;

class FruitSeller {
private:
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;
public:
	void InitMembers(int price, int num, int money) {
		APPLE_PRICE = price;
		numOfApples = num;
		myMoney = money;
	}
	int SaleApples(int money) {
		int num = money / APPLE_PRICE;
		numOfApples -= num;
		myMoney += money;
		return num;
	}
	void ShowSalesResult() {
		cout << "Num. of Apples left: " << numOfApples << '\n';
		cout << "Sales Profit: " << myMoney << '\n';
	}
};

class FruitBuyer {
	int myMoney;
	int numOfApples;
public:
	void InitMembers(int money) {
		myMoney = money;
		numOfApples = 0;
	}
	void BuyApples(FruitSeller& seller, int money) {
		numOfApples += seller.SaleApples(money);//seller��ü�� ���ڷ� �޾ƿͼ� money��ŭ�� ����� ���
		//�ϳ��� ��ü��  �� �ٸ� ��ü���� �޽����� �����ϴ� ����� �Լ�ȣ���� ������� ��(message passing)
		myMoney -= money;
	}
	void ShowBuyResult() {
		cout << "Money remaining: " << myMoney << '\n';
		cout<<"Num of Apples: "<<numOfApples<<'\n';
	}
};

int main(void) {
	FruitSeller seller;
	seller.InitMembers(1000, 20, 0);

	FruitBuyer buyer;
	buyer.InitMembers(5000);
	buyer.BuyApples(seller, 2000);

	cout << "Seller's status:" << '\n';
	seller.ShowSalesResult();
	cout << "Buyer's status:" << '\n';
	buyer.ShowBuyResult();
}