#include<iostream>
using namespace std;

class FruitSeller {
private:
	const int APPLE_PRICE;
	int numOfApples;
	int myMoney;
public:
	FruitSeller(int price, int num, int money) 
		//const변수 역시 member initializer를 통해 초기화가 가능하다
		:APPLE_PRICE(price), numOfApples(num), myMoney(money){
		/*APPLE_PRICE = price;
		numOfApples = num;
		myMoney = money;*/
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
	FruitBuyer(int money) 
		:myMoney(money), numOfApples(0){
		/*myMoney = money;
		numOfApples = 0;*/
	}
	void BuyApples(FruitSeller& seller, int money) {
		numOfApples += seller.SaleApples(money);//seller객체를 인자로 받아와서 money만큼의 사과를 산다
		//하나의 객체가  또 다른 객체에게 메시지를 전달하는 방법은 함수호출을 기반으로 함(message passing)
		myMoney -= money;
	}
	void ShowBuyResult() {
		cout << "Money remaining: " << myMoney << '\n';
		cout << "Num of Apples: " << numOfApples << '\n';
	}
};

int main(void) {
	FruitSeller seller(1000, 20, 0);

	FruitBuyer buyer(7000);//구매자가 갖고있는 돈
	buyer.BuyApples(seller, 2000);//2000원어치 사과 구매

	cout << "Seller's status:" << '\n';
	seller.ShowSalesResult();
	cout << "Buyer's status:" << '\n';
	buyer.ShowBuyResult();
}