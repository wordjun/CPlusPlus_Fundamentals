#include<iostream>
using namespace std;
#pragma warning (disable:4996)

class Employee {//해당 클래스는 객체생성 목적으로 만들어진 클래스가 아니다.
	//따라서 해당 클래스의 객체생성을 막기 위해 순수가상함수를 사용하여 문법적으로 막아야 한다.
private:
	char name[100];
public:
	Employee(const char* name) {
		strcpy(this->name, name);
	}
	void ShowYourName() const {
		cout << "name: " << name << '\n';
	}
	/*virtual int GetPay() const {
		return 0;
	}
	virtual void ShowSalaryInfo() const {
	}*/
	virtual int GetPay() const = 0;//순수가상함수
	virtual void ShowSalaryInfo() const = 0;//순수가상함수
	//순수가상함수: 함수의 몸체가 정의되지 않은 함수(실제로 0을 대입하는 것이 아닌 컴파일러에게 명시적으로 몸체를 정의하지 않았음을 알리는것)
	//따라서 잘못된, 혹은 의도하지 않은 객체생성을 막을 수 있고, 
	//위 두개함수(getpay, showsalinfo)는 유도클래스에서 오버라이딩할수있도록 만들어진 틀일 뿐, 실제 실행되지 않는 함수임을 보다 명확히 명시할 수 있게 되었다.
};//결론: Employee클래스처럼 하나이상의 멤버함수를 순수가상함수로 선언한 클래스를 추상클래스라고 부른다. 완전하지 않으며, 그래서 객체생성이 불가능한 클래스임을 뜻한다.

class PermanentWorker : public Employee {
private:
	//char name[100];
	int salary;
public:
	PermanentWorker(const char* name, int money)
		:Employee(name), salary(money) {
	}

	int GetPay() const {
		return salary;
	}

	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary: " << GetPay() << "\n\n";
	}
};

class TemporaryWorker : public Employee {
private:
	int workTime;
	int payPerHour;
public:
	TemporaryWorker(const char* name, int pay)
		:Employee(name), workTime(0), payPerHour(pay) {
		
	}
	void AddWorkTime(int time) {
		workTime += time;
	}
	int GetPay() const {
		return workTime * payPerHour;
	}
	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary: " << GetPay() << "\n\n";
	}
};

class SalesWorker : public PermanentWorker {
private:
	int salesResult;
	double bonusRatio;
public:
	SalesWorker(const char* name, int money, double ratio)
		:PermanentWorker(name, money), salesResult(0), bonusRatio(ratio) {
		
	}
	void AddSalesResult(int value) {
		salesResult += value;
	}

	int GetPay() const {//overriding: 오버라이딩된 기초클래스의 함수 PermanentWorker::GetPay()는 오버라이딩한 유도클래스 SalesWorker의 GetPay() 함수에 의해 가려진다.
		//GetPay() from PermanentWorker class called.
		return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
	}

	void ShowSalaryInfo() const {
		ShowYourName();
		//GetPay() from SalesWorker class called.
		cout << "salary: " << GetPay() << "\n\n";
	}
};

class EmployeeHandler {
private:
	Employee* empList[50];
	int empNum;
public:
	EmployeeHandler() :
		empNum(0) {}
	void AddEmployee(Employee* emp) {
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const {
		for (int i = 0; i < empNum; i++)
			empList[i]->ShowSalaryInfo();
	}
	void ShowTotalSalary() const {
		int sum = 0;
		for (int i = 0; i < empNum; i++)
			sum += empList[i]->GetPay();
		cout << "salary sum: " << sum << '\n';
	}
	~EmployeeHandler() {
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};

int main() {
	EmployeeHandler handler;
	//정규직
	handler.AddEmployee(new PermanentWorker("PARK", 1500));
	handler.AddEmployee(new PermanentWorker("LEE", 1700));

	//임시직
	TemporaryWorker* albamon = new TemporaryWorker("CHOI", 400);
	albamon->AddWorkTime(5);
	handler.AddEmployee(albamon);

	//영업직
	SalesWorker* seller = new SalesWorker("KIM", 1000, 0.1);
	seller->AddSalesResult(7000);
	handler.AddEmployee(seller);

	handler.ShowAllSalaryInfo();

	handler.ShowTotalSalary();
	return 0;
}