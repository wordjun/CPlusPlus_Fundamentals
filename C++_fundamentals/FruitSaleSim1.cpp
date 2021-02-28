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
		numOfApples += seller.SaleApples(money);//seller객체를 인자로 받아와서 money만큼의 사과를 산다
		//하나의 객체가  또 다른 객체에게 메시지를 전달하는 방법은 함수호출을 기반으로 함(message passing)
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