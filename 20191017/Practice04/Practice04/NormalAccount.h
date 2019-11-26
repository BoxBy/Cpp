#pragma once
#include "Account.h"

class NormalAccount : public Account {
	int interRate; // 이자율 %단위
public:
	NormalAccount(int ID, int money, char* name, int rate) // 원금 추가
		:Account(ID, money, name), interRate(rate)
	{}
	virtual void Deposit(int money) // 이자 추가
	{
		Account::Deposit(money);
		Account::Deposit((money*interRate) / 100);
	}
};
