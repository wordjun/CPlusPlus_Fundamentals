#include<iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0)
		:xpos(x), ypos(y) {}

	void ShowPosition() const {
		cout << "x: " << xpos << ", y: " << ypos << '\n';
	}
	Point& operator++() {//++연산자가 멤버함수의 형태로 오버로딩됨
		xpos++; 
		ypos++;
		return *this;//객체자신을 반환함
		//함수반환형이 참조형 Point&이므로, 객체자신을 참조할수있는 참조의정보(참조값)가 반환된다
	}
	const Point operator++(int) {//후위연산자
		const Point ret(*this);//ret(xpos, ypos)와 동일
		//증가연산
		xpos++, ypos++;
		return ret;
	}

	Point operator*(int times) {
		Point pos(xpos * times, ypos * times);
		return pos;
	}
	friend Point &operator--(Point &ref);//전역함수의 형태로 오버로딩
	friend const Point operator--(Point& ref, int);
	friend Point& operator-(Point& ref);
	friend Point& operator~(Point& ref);
	friend Point operator*(int times, Point& ref);//교환법칙을 성립시키기 위한 오버로딩
};

Point& operator--(Point& ref) {
	ref.xpos--;
	ref.ypos--;
	return ref;
}

//함수 앞의 const는 operator--함수의 반환으로 인해 생성되는 임시객체를 const객체로 생성하겠다는 의미(리턴 시 복사생성자 호출할때)
//객체를 상수화하여 해당 객체에 저장된 값의 변경을 허용하지 않는다는 것이다.
const Point operator--(Point& ref, int) {
	const Point ret(ref);//ret(xpos, ypos)와 동일. const선언은 함수내에서 ret의 변경을 막겠다는 의미.
	ref.xpos--;
	ref.ypos--;
	return ret;//ret객체가 반환되면, 반환의 과정에서 새 객체가 생성(복사생성자)된다. 그리고 함수가 리턴됨가 동시에 소멸된다.
}

Point& operator-(Point& ref) {
	ref.xpos *= -1;
	ref.ypos *= -1;
	return ref;
}

Point& operator~(Point& ref) {
	int temp = ref.xpos;
	ref.xpos = ref.ypos;
	ref.ypos = temp;
	return ref;
}

Point operator*(int times, Point& ref) {
	return ref * times;//이미 오버로딩된 *연산자를 사용.
}
int main() {
	//Point pos(1, 2);
	//++pos;
	//pos.ShowPosition();
	//--pos;
	//pos.ShowPosition();

	//++(++pos);//++(pos.operator++()); -> ++(pos의 참조값) -> (pos의 참조값).operator++();
	//pos.ShowPosition();

	//--(--pos);//--(operator--(pos)); -> --(pos의 참조값) -> operator--(pos의 참조값)
	//pos.ShowPosition();

	//Q10-2
	Point p1(1, 2);
	/*Point p2 = -p1;
	p2.ShowPosition();

	(~p2).ShowPosition();*/
	
	Point cpy;
	cpy = p1--;
	cpy.ShowPosition();
	p1.ShowPosition();

	cpy = --p1;
	cpy.ShowPosition();
	p1.ShowPosition();

	Point p2(5, 10);
	cpy = p2 * 3;
	cpy.ShowPosition();

	cpy = 4 * p2;
	cpy.ShowPosition();
}