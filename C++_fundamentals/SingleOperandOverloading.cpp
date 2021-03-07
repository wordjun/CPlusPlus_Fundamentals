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
	Point& operator++() {//++�����ڰ� ����Լ��� ���·� �����ε���
		xpos++; 
		ypos++;
		return *this;//��ü�ڽ��� ��ȯ��
		//�Լ���ȯ���� ������ Point&�̹Ƿ�, ��ü�ڽ��� �����Ҽ��ִ� ����������(������)�� ��ȯ�ȴ�
	}
	const Point operator++(int) {//����������
		const Point ret(*this);//ret(xpos, ypos)�� ����
		//��������
		xpos++, ypos++;
		return ret;
	}

	Point operator*(int times) {
		Point pos(xpos * times, ypos * times);
		return pos;
	}
	friend Point &operator--(Point &ref);//�����Լ��� ���·� �����ε�
	friend const Point operator--(Point& ref, int);
	friend Point& operator-(Point& ref);
	friend Point& operator~(Point& ref);
	friend Point operator*(int times, Point& ref);//��ȯ��Ģ�� ������Ű�� ���� �����ε�
};

Point& operator--(Point& ref) {
	ref.xpos--;
	ref.ypos--;
	return ref;
}

//�Լ� ���� const�� operator--�Լ��� ��ȯ���� ���� �����Ǵ� �ӽð�ü�� const��ü�� �����ϰڴٴ� �ǹ�(���� �� ��������� ȣ���Ҷ�)
//��ü�� ���ȭ�Ͽ� �ش� ��ü�� ����� ���� ������ ������� �ʴ´ٴ� ���̴�.
const Point operator--(Point& ref, int) {
	const Point ret(ref);//ret(xpos, ypos)�� ����. const������ �Լ������� ret�� ������ ���ڴٴ� �ǹ�.
	ref.xpos--;
	ref.ypos--;
	return ret;//ret��ü�� ��ȯ�Ǹ�, ��ȯ�� �������� �� ��ü�� ����(���������)�ȴ�. �׸��� �Լ��� ���ϵʰ� ���ÿ� �Ҹ�ȴ�.
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
	return ref * times;//�̹� �����ε��� *�����ڸ� ���.
}
int main() {
	//Point pos(1, 2);
	//++pos;
	//pos.ShowPosition();
	//--pos;
	//pos.ShowPosition();

	//++(++pos);//++(pos.operator++()); -> ++(pos�� ������) -> (pos�� ������).operator++();
	//pos.ShowPosition();

	//--(--pos);//--(operator--(pos)); -> --(pos�� ������) -> operator--(pos�� ������)
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