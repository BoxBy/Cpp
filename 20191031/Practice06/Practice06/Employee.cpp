#include "Employee.h"

Employee::Employee(string name) { this->name = name; }

void Employee::PrintName() {	cout << "Name : " << name << endl; }

PermanentWorker::PermanentWorker(string name, int salary) : Employee(name) {	this->salary = salary; }

int PermanentWorker::getPay() {	return salary; }

void PermanentWorker::ShowInfo()
{
	Employee::PrintName();
	cout << "Salary : " << salary << endl;
}

TemporaryWorker::TemporaryWorker(string name, int pay) : Employee(name)
{	payPerHour = pay;
	workTime = 0;
}

void TemporaryWorker::AddWorkTime(int workTime) {
	this->workTime += workTime; }

int TemporaryWorker::getPay()
{	return workTime * payPerHour; }

void TemporaryWorker::ShowInfo()
{
	Employee::PrintName();
	cout << "workTime * payPerHour : " << getPay() << endl;
}

SalesWorker::SalesWorker(string name, int salay, double bonusRatio) : PermanentWorker(name, salay)
{
	this->bonusRatio = 0.1 * bonusRatio;
}

void SalesWorker::AddSalesResult(int salesResult){	this->salesResult = salesResult; }

int SalesWorker::getPay()
{ 	return PermanentWorker::getPay() + salesResult *  bonusRatio; }

void SalesWorker::ShowInfo()
{
	Employee::PrintName();
	cout << "Pay : " << getPay() << endl;
}

ForeignSalesWorker::ForeignSalesWorker(string name, int salary, double bonusRatio, int riskLevel) : SalesWorker(name, salary, bonusRatio)
{
	this->riskLevel = riskLevel;
}

int ForeignSalesWorker::GetRiskPay()
{
	return SalesWorker::getPay() * riskLevel * 0.1;
}

int ForeignSalesWorker::getPay()
{
	return PermanentWorker::getPay() + GetRiskPay();
}

void ForeignSalesWorker::ShowInfo()
{
	Employee::PrintName();
	cout << "Salary : " << PermanentWorker::getPay() << endl;
	cout << "Risk pay : " << GetRiskPay() << endl;
	cout << "Total : " << getPay() << endl;
}

EmployeeHandler::EmployeeHandler()
{
	count = 0;
}

void EmployeeHandler::AddEmployee(Employee * emp)
{
	this->emp[count++] = emp;
}

void EmployeeHandler::ShowAllInfo()
{
	for (int i = 0; i < count; i++)
		emp[i]->ShowInfo();
}

void EmployeeHandler::ShowTotalSalary()
{
	int temp = 0;
	for (int i = 0; i < count; i++)
		temp += emp[i]->getPay();
	cout << "TotalSalary : " << temp << endl;
}

EmployeeHandler::~EmployeeHandler()
{
	for(int i = 0; i < count; i++)
		delete emp[i];
	delete[] emp;
}
