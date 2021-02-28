#pragma once
#ifndef __POINT_H_
#define __POINT_H_
//구조체 중복 정의로 인해 발생하는 오류 방지
/*
main에서 point.h와 pointOperation.h를 포함한다고 가정.
근데 pointOperation.h에서도 point.h를 포함한다고 했을 떄,
main함수에선 결과적으로 point.h를 총 2번 포함하는 셈이 된다.
전처리기는 이를 문제삼지 않으나 컴파일러가 문제를 일으키게 된다.
point구조체의 정의가 2번 등장하게 되면 에러메시지를 발생시킨다.
따라서 __POINT_H_를 정의하지 않았다면 #endif가 나오기 전까지 그 사이에 있는
코드를 포함시키라는 뜻이다.

모든 헤더파일에 해당 매크로를 사용하여 헤더파일 중복정의를 미연에 방지할 수 있다.
*/
class Point {
private: 
	int x;
	int y;
public:
	Point(const int& xpos, const int& ypos);
	//bool InitMembers(int xpos, int ypos);
	int getX() const;
	int getY() const;
	bool setX(int xpos);
	bool setY(int ypos);
};
#endif // !__POINT_H_
