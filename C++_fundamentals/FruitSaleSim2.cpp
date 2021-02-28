#include<iostream>
using namespace std;

class FruitSeller {
private:
	const int APPLE_PRICE;
	int numOfApples;
	int myMoney;
public:
	FruitSeller(int price, int num, int money) 
		//const���� ���� member initializer�� ���� �ʱ�ȭ�� �����ϴ�
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
		numOfApples += seller.SaleApples(money);//seller��ü�� ���ڷ� �޾ƿͼ� money��ŭ�� ����� ���
		//�ϳ��� ��ü��  �� �ٸ� ��ü���� �޽����� �����ϴ� ����� �Լ�ȣ���� ������� ��(message passing)
		myMoney -= money;
	}
	void ShowBuyResult() {
		cout << "Money remaining: " << myMoney << '\n';
		cout << "Num of Apples: " << numOfApples << '\n';
	}
};

int main(void) {
	FruitSeller seller(1000, 20, 0);

	FruitBuyer buyer(7000);//�����ڰ� �����ִ� ��
	buyer.BuyApples(seller, 2000);//2000����ġ ��� ����

	cout << "Seller's status:" << '\n';
	seller.ShowSalesResult();
	cout << "Buyer's status:" << '\n';
	buyer.ShowBuyResult();
}