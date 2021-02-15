#include<iostream>

//다형성
//오버라이딩과 밀접한 연관이 있는 OOP의 특징 중 하나
//같은 메소드 호출 시 실제 수행되는 내용은 해당 객체가 무엇이냐에 따라 달라진다는 것.
//예) 그림 그릴 때 삼각형 객체에게 Draw함수호출하는 것과 정사각형 객체에게 Draw함수호출하는것은
//둘 다 Draw라는 루틴을 통해서 진행되지만 그리는 그림은 서로 다르게 된다는 것.(실제 수행은 다르게 나타남)
//따라서 둘 다 같은 부모를 상속받아야 함

class Shape {
public:
	void Draw() {
		//구현은 자식에서 한다
	}
};

class Triangle :Shape {
public:
	void Draw() {
		std::cout << "Draw Triangle\n";
	}
};

class Rectangle :Shape {
public:
	void Draw() {
		std::cout << "Draw Rectangle\n";
	}
};

void main() {
	Triangle t1;
	Rectangle r1;

	t1.Draw(), r1.Draw();
}