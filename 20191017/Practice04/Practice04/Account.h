#include "BankingCommonDecl.h"

class Account {
	int accID; // ���� ��ȣ
	int balance; // �ܾ�
	char* cusName; // �� �̸�
public:
	Account();
	Account(int ID, int money, char* name) // Constructor
	{
		accID = ID;
		balance = money;
		cusName = new char[NAME_LEN];
		strcpy_s(cusName,NAME_LEN, name);
	}
	Account(const Account& account) // ���������
	{
		accID = account.accID;
		balance = account.balance;
		cusName = new char[NAME_LEN];
		strcpy_s(cusName, NAME_LEN, account.cusName);
	}
	int getAccID() const // getID
	{
		return accID;
	}
	virtual void Deposit(int money) // money �Ա�
	{
		balance += money;
	}
	int Withdraw(int money) // money ���, return money, �ܾ� ������ return 0;
	{
		if (balance < money)
			return 0;
		else
			balance -= money;
		return money;
	}
	void ShowAccInfo() const // Account ���� ���
	{
		std::cout << "���¹�ȣ : " << accID << std::endl;
		std::cout << "�̡����� : " << cusName << std::endl;
		std::cout << "�ܡ����� : " << balance << std::endl;

	}
	~Account() // Destructor
	{
		delete[] cusName;
	}
};