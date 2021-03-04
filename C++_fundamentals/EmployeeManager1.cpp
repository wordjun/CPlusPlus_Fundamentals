#include<iostream>
using namespace std;
#pragma warning (disable:4996)

class Employee {//�ش� Ŭ������ ��ü���� �������� ������� Ŭ������ �ƴϴ�.
	//���� �ش� Ŭ������ ��ü������ ���� ���� ���������Լ��� ����Ͽ� ���������� ���ƾ� �Ѵ�.
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
	virtual int GetPay() const = 0;//���������Լ�
	virtual void ShowSalaryInfo() const = 0;//���������Լ�
	//���������Լ�: �Լ��� ��ü�� ���ǵ��� ���� �Լ�(������ 0�� �����ϴ� ���� �ƴ� �����Ϸ����� ��������� ��ü�� �������� �ʾ����� �˸��°�)
	//���� �߸���, Ȥ�� �ǵ����� ���� ��ü������ ���� �� �ְ�, 
	//�� �ΰ��Լ�(getpay, showsalinfo)�� ����Ŭ�������� �������̵��Ҽ��ֵ��� ������� Ʋ�� ��, ���� ������� �ʴ� �Լ����� ���� ��Ȯ�� ����� �� �ְ� �Ǿ���.
};//���: EmployeeŬ����ó�� �ϳ��̻��� ����Լ��� ���������Լ��� ������ Ŭ������ �߻�Ŭ������� �θ���. �������� ������, �׷��� ��ü������ �Ұ����� Ŭ�������� ���Ѵ�.


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

	int GetPay() const {//overriding: �������̵��� ����Ŭ������ �Լ� PermanentWorker::GetPay()�� �������̵��� ����Ŭ���� SalesWorker�� GetPay() �Լ��� ���� ��������.
		//GetPay() from PermanentWorker class called.
		return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
	}

	void ShowSalaryInfo() const {
		ShowYourName();
		//GetPay() from SalesWorker class called.
		cout << "salary: " << GetPay() << "\n\n";
	}
};

namespace RISK_LEVEL {
	enum {
		RISK_A = 30,
		RISK_B = 20,
		RISK_C = 10
	};

}

class ForeignSalesWorker : public SalesWorker {
private:
	int riskLevel;
public:
	ForeignSalesWorker(const char* name, int money, double ratio, int risk)
		:SalesWorker(name, money, ratio), riskLevel(risk){
	}
	
	int GetRiskPay() const {
		return (int)(SalesWorker::GetPay() * (riskLevel / 100.0));//double�� �Ҽ��� �� ���̱� **********
	}
	int GetPay() const {
		return SalesWorker::GetPay() + GetRiskPay();
	}
	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary: " << SalesWorker::GetPay() << '\n';
		cout << "risk pay: " << GetRiskPay() << '\n';
		cout << "sum: " << GetPay() << "\n\n";
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
	////������
	//handler.AddEmployee(new PermanentWorker("PARK", 1500));
	//handler.AddEmployee(new PermanentWorker("LEE", 1700));

	////�ӽ���
	//TemporaryWorker* albamon = new TemporaryWorker("CHOI", 400);
	//albamon->AddWorkTime(5);
	//handler.AddEmployee(albamon);

	////������
	//SalesWorker* seller = new SalesWorker("KIM", 1000, 0.1);
	//seller->AddSalesResult(7000);
	//handler.AddEmployee(seller);

	//Q08-1
	ForeignSalesWorker* fs1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
	fs1->AddSalesResult(7000);
	handler.AddEmployee(fs1);

	ForeignSalesWorker* fs2 = new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
	fs2->AddSalesResult(7000);
	handler.AddEmployee(fs2);

	ForeignSalesWorker* fs3 = new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
	fs3->AddSalesResult(7000);
	handler.AddEmployee(fs3);

	handler.ShowAllSalaryInfo();

	//handler.ShowTotalSalary();
	return 0;
}