#include<iostream>
using namespace std;
#pragma warning (disable:4996)

class Book {
private:
	char* title;
	char* isbn;
	int price;
public:
	Book(const char* title, const char* isbn, int _price)
		:price(_price) {
		this->title = new char[strlen(title) + 1];
		this->isbn = new char[strlen(isbn) + 1];

		strcpy(this->title, title);
		strcpy(this->isbn, isbn);
	}
	void ShowBookInfo() const {
		cout << "����: " << title << '\n';
		cout << "ISBN: " << isbn << '\n';
		cout << "����: " << price << '\n';
	}
	~Book() {
		delete[] title;
		delete[] isbn;
	}
};

class EBook : public Book {
private:
	char* DRMKey;
public:
	EBook(const char* title, const char* isbn, int _price, const char* DRMKey)
		:Book(title, isbn, _price) {
		this->DRMKey = new char[strlen(DRMKey) + 1];
		strcpy(this->DRMKey, DRMKey);
	}
	void ShowEBookInfo() const {
		ShowBookInfo();
		cout << "����Ű: " << DRMKey << '\n';
	}
	~EBook() {
		delete[] DRMKey;
	}
};

int main(void) {
	Book book("���� C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();

	cout << '\n';

	EBook ebook("���� C++ ebook", "555-12345-890-1", 10000, "8fah92gn74jk");
	ebook.ShowEBookInfo();
}