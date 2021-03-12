#include<iostream>
#include<cstring>
#pragma warning (disable:4996)
using namespace std;

template<typename T>
class Point {
private:
	T xpos, ypos;
public:
	Point(T x = 0, T y = 0)
		:xpos(x), ypos(y) {}
	void ShowPos() const {
		cout << xpos << ", " << ypos << '\n';
	}
};

template<typename T>
class SimpleDataWrapper {
private:
	T mdata;
public:
	SimpleDataWrapper(T data)
		:mdata(data) {}
	void ShowDataInfo(void) {
		cout << "Data: " << mdata << '\n';
	}
};

template<>//char*���� ���� Ư��ȭ. ���ڿ��� �����ϱ� ����, �̸� �������� �����Ҵ� ����� ������/�Ҹ��ڸ� ���� ����.
//��������¿��� ���ڿ� ���������� ���� ����ϵ��� ����
class SimpleDataWrapper<char*> {
private:
	char* mdata;
public:
	SimpleDataWrapper(const char* data) {
		mdata = new char[strlen(data) + 1];
		strcpy(mdata, data);
	}
	void ShowDataInfo() {
		cout << "String: " << mdata << '\n';
		cout << "Length: " << strlen(mdata) << '\n';
	}
	~SimpleDataWrapper() {
		delete[] mdata;
	}
};

template<>//Point<int>���� ���� Ư��ȭ. ���ڿ��� �����ϱ� ����, �̸� �������� �����Ҵ� ����� ������/�Ҹ��ڸ� ���� ����.
//��������¿��� ���ڿ� ���������� ���� ����ϵ��� ����
class SimpleDataWrapper<Point<int>> {
private:
	Point<int> mdata;
public:
	SimpleDataWrapper(int x, int y) 
	:mdata(x, y) {
	}
	void ShowDataInfo() {
		mdata.ShowPos();
	}
};

int main() {
	SimpleDataWrapper<int> iwrap(170);//int���� ���ؼ� Ư��ȭ�� ������ �����Ƿ� ������ �� ���ø� Ŭ������
	//SimpleDataWrapper<int>�� ��������� �� Ŭ������ ������� ��ü����
	iwrap.ShowDataInfo();

	SimpleDataWrapper<char*> cwrap("Hello world");
	cwrap.ShowDataInfo();

	SimpleDataWrapper<Point<int>> pwrap(3, 7);
	pwrap.ShowDataInfo();
}