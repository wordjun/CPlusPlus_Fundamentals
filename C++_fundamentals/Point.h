#pragma once
#ifndef __POINT_H_
#define __POINT_H_
//����ü �ߺ� ���Ƿ� ���� �߻��ϴ� ���� ����
/*
main���� point.h�� pointOperation.h�� �����Ѵٰ� ����.
�ٵ� pointOperation.h������ point.h�� �����Ѵٰ� ���� ��,
main�Լ����� ��������� point.h�� �� 2�� �����ϴ� ���� �ȴ�.
��ó����� �̸� �������� ������ �����Ϸ��� ������ ����Ű�� �ȴ�.
point����ü�� ���ǰ� 2�� �����ϰ� �Ǹ� �����޽����� �߻���Ų��.
���� __POINT_H_�� �������� �ʾҴٸ� #endif�� ������ ������ �� ���̿� �ִ�
�ڵ带 ���Խ�Ű��� ���̴�.

��� ������Ͽ� �ش� ��ũ�θ� ����Ͽ� ������� �ߺ����Ǹ� �̿��� ������ �� �ִ�.
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
