#include "BankingCommonDecl.h"

class Account {
	int accID; // 계좌 번호
	int balance; // 잔액
	char* cusName; // 고객 이름
public:
	Account();
	Account(int ID, int money, char* name) // Constructor
	{
		accID = ID;
		balance = money;
		cusName = new char[NAME_LEN];
		strcpy_s(cusName,NAME_LEN, name);
	}
	Account(const Account& account) // 복사생성자
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
	virtual void Deposit(int money) // money 입금
	{
		balance += money;
	}
	int Withdraw(int money) // money 출금, return money, 잔액 부족시 return 0;
	{
		if (balance < money)
			return 0;
		else
			balance -= money;
		return money;
	}
	void ShowAccInfo() const // Account 정보 출력
	{
		std::cout << "계좌번호 : " << accID << std::endl;
		std::cout << "이　　름 : " << cusName << std::endl;
		std::cout << "잔　　액 : " << balance << std::endl;

	}
	~Account() // Destructor
	{
		delete[] cusName;
	}
};