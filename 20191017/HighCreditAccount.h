#pragma once
#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount {
	int specialRate; // special 추가 이자
public:
	HighCreditAccount(int ID, int money, char* name, int rate, int special) // 원금, 이자 추가
		:NormalAccount(ID, money, name, rate), specialRate(special)
	{}
	virtual void Deposit(int money) // special 이자 추가
	{
		NormalAccount::Deposit(money);
		Account::Deposit((money*specialRate) / 100);
	}
};