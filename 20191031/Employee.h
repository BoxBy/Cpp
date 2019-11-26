#pragma once
#include <string>
#include <iostream>
using namespace std;
namespace RISK_LEVEL //RISK_LEVEL 네임스페이스 정의
{
	enum{RISK_A = 3,	RISK_B = 2,	RISK_C = 1	};
}

class Employee {
	string name;
public:
	Employee(string name);
	void PrintName();
	virtual int getPay() = 0;
	virtual void ShowInfo() = 0;
};

class PermanentWorker : public Employee {
	int salary; // 월급
public:
	PermanentWorker(string name, int salary);
	int getPay();
	void ShowInfo();
};

class TemporaryWorker : public Employee {
	int workTime;
	int payPerHour;
public:
	TemporaryWorker(string name, int pay);
	void AddWorkTime(int workTime);
	int getPay();
	void ShowInfo();
};

class SalesWorker : public PermanentWorker {
	int salesResult;
	double bonusRatio;
public:
	SalesWorker(string name, int salay, double bonusRatio);
	void AddSalesResult(int salesResult);
	int getPay();
	void ShowInfo();
};

class ForeignSalesWorker : public SalesWorker {
	int riskLevel;
public:
	ForeignSalesWorker(string name, int salary, double bonusRatio, int riskLevel);
	int GetRiskPay();
	int getPay();
	void ShowInfo();
};

class EmployeeHandler {
private:
	Employee * emp[10];
	int count;
public:
	EmployeeHandler();
	void AddEmployee(Employee* emp);
	void ShowAllInfo();
	void ShowTotalSalary();
	~EmployeeHandler();
};