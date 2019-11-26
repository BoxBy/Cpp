#pragma once
#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount {
	int specialRate; // special �߰� ����
public:
	HighCreditAccount(int ID, int money, char* name, int rate, int special) // ����, ���� �߰�
		:NormalAccount(ID, money, name, rate), specialRate(special)
	{}
	virtual void Deposit(int money) // special ���� �߰�
	{
		NormalAccount::Deposit(money);
		Account::Deposit((money*specialRate) / 100);
	}
};