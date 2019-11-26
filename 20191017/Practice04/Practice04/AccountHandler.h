#pragma once
#include "HighCreditAccount.h"

class AccountHandler {
	Account* accArr[100]; // Account ������ ���� ��ü ������ �迭
	int accNum; // ����� Account ����
public:
	AccountHandler() { accNum = 0; }
	void ShowMenu() const // �޴� ���
	{
		std::cout << "----�� ��----" << std::endl;
		std::cout << "1. ���°��� " << std::endl;
		std::cout << "2. �ԡ����� " << std::endl;
		std::cout << "3. �⡡���� " << std::endl;
		std::cout << "4. �������� " << std::endl;
		std::cout << "5. �������� " << std::endl;
	}
	void MakeAccount() // ���� ����
	{
		int temp;
		std::cout << "���� ����" << std::endl;
		std::cout << "1. Normal Account" << std::endl;
		std::cout << "2. HIghCreditAccount" << std::endl;
		std::cin >> temp;
		
		if (temp == NORMAL)
			MakeNormalAccount();
		else
			MakeCreditAccount();
	}
	void DepositMoney() // �Ա�
	{
		int id;
		int money;
		std::cout << "ID : " << std::endl;
		std::cin >> id;
		std::cout << "�Աݾ� : " << std::endl;
		std::cin >> money;
		for (int i = 0; i < accNum; i++) {
			if (accArr[i]->getAccID() == id) {
				accArr[i]->Deposit(money);
				std::cout << "�Ա� �Ϸ�" << std::endl;
				return;
			}
		}
		std::cout << "�������� �ʴ� ID " << std::endl;

	}
	void WithdrawMoney() // ���
	{
		int id;
		int money;
		std::cout << "ID : " << std::endl;
		std::cin >> id;
		std::cout << "��ݾ� : " << std::endl;
		std::cin >> money;
		for (int i = 0; i < accNum; i++) {
			if (accArr[i]->getAccID() == id) {
				accArr[i]->Withdraw(money);
				std::cout << "��� �Ϸ�" << std::endl;
				return;
			}
		}
		std::cout << "�������� �ʴ� ID " << std::endl;
	}
	void ShowAllAccInfo() const // Show Account
	{
		for (int i = 0; i < accNum; i++) {
			accArr[i]->ShowAccInfo();
			std::cout << "-------------" << std::endl;
		}
	}
	~AccountHandler()
	{
		delete[] accArr;
	}
protected:
	void MakeNormalAccount() // Make a Normal Account
	{
		int id;
		char name[NAME_LEN];
		int balance;
		int interRate;
		std::cout << "ID : ";
		std::cin >> id;
		std::cout << "�̸� : ";
		std::cin >> name;
		std::cout << "�Ա� �ݾ� : ";
		std::cin >> balance;
		std::cout << "���� : ";
		std::cin >> interRate;
		accArr[accNum++] = (Account*)new NormalAccount(id, balance, name, interRate);
	}
	void MakeCreditAccount() // Make a Credit Account
	{
		int id;
		char name[NAME_LEN];
		int balance;
		int interRate;
		int creditLevel;
		std::cout << "ID : ";
		std::cin >> id;
		std::cout << "�̸� : ";
		std::cin >> name;
		std::cout << "�Ա� �ݾ� : ";
		std::cin >> balance;
		std::cout << "���� : ";
		std::cin >> interRate;
		std::cout << "�ſ���(1 = A, 2 = B, 3 = C) : ";
		std::cin >> creditLevel;
		switch (creditLevel) {
		case 1:
			accArr[accNum++] = (Account*)new HighCreditAccount(id, balance, name, interRate, LEVEL_A);
			break;
		case 2:
			accArr[accNum++] = (Account*)new HighCreditAccount(id, balance, name, interRate, LEVEL_B);
			break;
		case 3:
			accArr[accNum++] = (Account*)new HighCreditAccount(id, balance, name, interRate, LEVEL_C);
			break;
		}
	}
};