#include<iostream>
using namespace std;
#define NAME_SIZE 32

//�����ִ� �������� ��� �ϳ��� ���ο� Ÿ���� ������ִ� ���.
//����: struct ����ü��{};

//� �ǹ̷�, �������� ��������� ����ϴ� �� ����
struct Coordinates {
	int x;
	int y;
};

//����ü����Ÿ������ ����ϱ� ���� ����ü naming
//�迭�� ����ü�� ������: �������� �����̴�
//						���ӵ� �޸� ���� �Ҵ��
//����ü������� ���ӵ� �޸� ������ ����.
struct _tagStudent {
	char stdName[NAME_SIZE];//32
	int stdId;//4
	int English;//4
	int Mathematics;//4
	int Science;//4
	int Total;//4
	float fAvg;//2
};//total 54Bytes

int main() {
	_tagStudent tStudent1 = {};
	_tagStudent tStudentArr[100] = {};
	bool flag;
	//����ü ����� �����Ҷ� .�� �̿��� �����Ѵ�
	//���ڿ��� ��� �ܼ����Կ����ڷδ� �Ұ���
	//strcpy_s�Լ� �ʿ�(�ι�° �Ű������� ���ڿ��� ù��° �Ű������� ����)
	strcpy_s(tStudent1.stdName, "Jessie");
	tStudent1.English = 94;
	tStudent1.Mathematics = 88;

	//���ڿ��� ���� �׻� NULL�� ������ ��.
	//�����Ⱚ�� �� ���¿��� �� �迭��ҿ� ���� �����ϰ� �Ǹ� �� ���� ��µǰ�
	//�־����� ���� �κ��� �����Ⱚ �״�� ����� �ȴ�.
	//����Ҷ� ���ڿ��� ���� �ν��� �� ���� ����.
	//tStudent1.stdName[0] = 'a';
	cout << tStudent1.stdName << '\n';

	flag = strcmp(tStudent1.stdName, "Jessie");
	cout << flag << '\n';

	//string concatenation
	strcat_s(tStudent1.stdName, " concatenating string\n");
	cout << tStudent1.stdName << '\n';

	//string comparation: ������ 0, �ٸ��� 1 ����
	flag = strcmp(tStudent1.stdName, "Jessie");
	cout << flag << '\n';
	return 0;
}