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
	//���������
	Book(const Book& ref) 
	: price(ref.price) {
		title = new char[strlen(ref.title) + 1];
		isbn = new char[strlen(ref.isbn) + 1];
		strcpy(title, ref.title);
		strcpy(isbn, ref.isbn);
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
	//���Կ�����
	Book& operator=(const Book& ref) {
		//�޸� ���� ������ ����
		delete[] title;
		delete[] isbn;
		title = new char[strlen(ref.title) + 1];
		isbn = new char[strlen(ref.isbn) + 1];
		strcpy(title, ref.title);
		strcpy(isbn, ref.isbn);
		price = ref.price;
		return *this;
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
	//copy constructor
	EBook(const EBook& ref)
		:Book(ref) {
		DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy(DRMKey, ref.DRMKey);
	}
	void ShowEBookInfo() const {
		ShowBookInfo();
		cout << "����Ű: " << DRMKey << '\n';
	}
	~EBook() {
		delete[] DRMKey;
	}
	//���Կ�����
	EBook& operator=(const EBook& ref) {
		//�޸� ���� ����
		delete[] DRMKey;
		//��������� baseŬ����(Book)�� ���Կ����� ȣ��
		Book::operator=(ref);
		DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy(DRMKey, ref.DRMKey);
		return *this;
	}
};

int main(void) {
	EBook ebook1("���� C++", "555-12345-890-0", 20000, "dfagph3ir");
	EBook ebook2 = ebook1;//copy constructor

	ebook2.ShowEBookInfo();
	cout << '\n';
	EBook ebook3("empty", "empty", 0, "empty");
	ebook3 = ebook2;//���Կ����� ȣ��
	ebook1.ShowEBookInfo();
	ebook2.ShowEBookInfo();
	ebook3.ShowEBookInfo();
	return 0;
}