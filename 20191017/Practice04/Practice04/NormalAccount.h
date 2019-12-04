#pragma once
#include "Account.h"

class NormalAccount : public Account {
	int interRate; // ������ %����
public:
	NormalAccount(int ID, int money, char* name, int rate) // ���� �߰�
		:Account(ID, money, name), interRate(rate)
	{}
	virtual void Deposit(int money) // ���� �߰�
	{
		Account::Deposit(money);
		Account::Deposit((money*interRate) / 100);
	}
};