#pragma once
#include "HighCreditAccount.h"

class AccountHandler {
	Account* accArr[100]; // Account 지정을 위한 객체 포인터 배열
	int accNum; // 저장된 Account 갯수
public:
	AccountHandler() { accNum = 0; }
	void ShowMenu() const // 메뉴 출력
	{
		std::cout << "----메 뉴----" << std::endl;
		std::cout << "1. 계좌개설 " << std::endl;
		std::cout << "2. 입　　금 " << std::endl;
		std::cout << "3. 출　　금 " << std::endl;
		std::cout << "4. 계좌정보 " << std::endl;
		std::cout << "5. 종　　료 " << std::endl;
	}
	void MakeAccount() // 계좌 개설
	{
		int temp;
		std::cout << "계좌 종류" << std::endl;
		std::cout << "1. Normal Account" << std::endl;
		std::cout << "2. HIghCreditAccount" << std::endl;
		std::cin >> temp;
		
		if (temp == NORMAL)
			MakeNormalAccount();
		else
			MakeCreditAccount();
	}
	void DepositMoney() // 입금
	{
		int id;
		int money;
		std::cout << "ID : " << std::endl;
		std::cin >> id;
		std::cout << "입금액 : " << std::endl;
		std::cin >> money;
		for (int i = 0; i < accNum; i++) {
			if (accArr[i]->getAccID() == id) {
				accArr[i]->Deposit(money);
				std::cout << "입금 완료" << std::endl;
				return;
			}
		}
		std::cout << "존재하지 않는 ID " << std::endl;

	}
	void WithdrawMoney() // 출금
	{
		int id;
		int money;
		std::cout << "ID : " << std::endl;
		std::cin >> id;
		std::cout << "출금액 : " << std::endl;
		std::cin >> money;
		for (int i = 0; i < accNum; i++) {
			if (accArr[i]->getAccID() == id) {
				accArr[i]->Withdraw(money);
				std::cout << "출금 완료" << std::endl;
				return;
			}
		}
		std::cout << "존재하지 않는 ID " << std::endl;
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
		std::cout << "이름 : ";
		std::cin >> name;
		std::cout << "입금 금액 : ";
		std::cin >> balance;
		std::cout << "이율 : ";
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
		std::cout << "이름 : ";
		std::cin >> name;
		std::cout << "입금 금액 : ";
		std::cin >> balance;
		std::cout << "이율 : ";
		std::cin >> interRate;
		std::cout << "신용등급(1 = A, 2 = B, 3 = C) : ";
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