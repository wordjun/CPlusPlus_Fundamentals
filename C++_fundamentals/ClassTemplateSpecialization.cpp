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

template<>//char*형에 대해 특수화. 문자열을 저장하기 위함, 이를 목적으로 동적할당 기반의 생성자/소멸자를 별도 정의.
//데이터출력에선 문자열 길이정보도 같이 출력하도록 정의
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

template<>//Point<int>형에 대해 특수화. 문자열을 저장하기 위함, 이를 목적으로 동적할당 기반의 생성자/소멸자를 별도 정의.
//데이터출력에선 문자열 길이정보도 같이 출력하도록 정의
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
	SimpleDataWrapper<int> iwrap(170);//int형에 대해선 특수화가 돼있지 않으므로 컴파일 시 템플릿 클래스인
	//SimpleDataWrapper<int>가 만들어지고 이 클래스를 기반으로 객체생성
	iwrap.ShowDataInfo();

	SimpleDataWrapper<char*> cwrap("Hello world");
	cwrap.ShowDataInfo();

	SimpleDataWrapper<Point<int>> pwrap(3, 7);
	pwrap.ShowDataInfo();
}