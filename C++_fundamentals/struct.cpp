#include<iostream>
using namespace std;
#define NAME_SIZE 32

//관련있는 변수들을 모아 하나의 새로운 타입을 만들어주는 기능.
//형태: struct 구조체명{};

//어떤 의미로, 목적으로 만들었는지 명시하는 게 좋다
struct Coordinates {
	int x;
	int y;
};

//구조체변수타입임을 명시하기 위한 구조체 naming
//배열과 구조체의 공통점: 데이터의 집합이다
//						연속된 메모리 블럭에 할당됨
//구조체멤버들은 연속된 메모리 블럭으로 잡힘.
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
	//구조체 멤버에 접근할땐 .을 이용해 접근한다
	//문자열의 경우 단순대입연산자로는 불가능
	//strcpy_s함수 필요(두번째 매개변수인 문자열을 첫번째 매개변수에 복사)
	strcpy_s(tStudent1.stdName, "Jessie");
	tStudent1.English = 94;
	tStudent1.Mathematics = 88;

	//문자열의 끝은 항상 NULL로 끝나야 함.
	//쓰레기값이 들어간 상태에서 각 배열요소에 값을 대입하게 되면 그 값이 출력되고
	//넣어주지 않은 부분은 쓰레기값 그대로 출력이 된다.
	//출력할때 문자열의 끝을 인식할 수 없기 때문.
	//tStudent1.stdName[0] = 'a';
	cout << tStudent1.stdName << '\n';

	flag = strcmp(tStudent1.stdName, "Jessie");
	cout << flag << '\n';

	//string concatenation
	strcat_s(tStudent1.stdName, " concatenating string\n");
	cout << tStudent1.stdName << '\n';

	//string comparation: 같으면 0, 다르면 1 리턴
	flag = strcmp(tStudent1.stdName, "Jessie");
	cout << flag << '\n';
	return 0;
}