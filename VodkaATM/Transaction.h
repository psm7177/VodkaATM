#pragma once
#include "Account.h"
#include <string>
using namespace std;

#include "Bank.h"
class Transaction {
private:
	string type;
	int id;
	int depositMoney;
	Account* myAccount;
	Account* transferAccount;
	Bank* myBank;
	int transferMoney;
	Bank* transferBank;
	int withdrawalMoney;
public:
	string GetType() {
		return this->type;
	};
	Account* GetMyAccount() {
		return this->myAccount;
	};
	Account* GetTransferAccount() {
		return this->transferAccount;
	}
	int GetDepositMoney() {
		return this->depositMoney;
	}
	int GetWithdrawalMoney() {
		return this->withdrawalMoney;
	}
	int GetTransferMoney() {
		return this->transferMoney;
	}

};
private:
	static int idCount;
	int id;
	string tnsType;
	Account* myAccount;
	int value;
	int fee;
	Account* transferAccount;
	string errorMessage;
	string GetDeposit();
	string GetWithdrawal();
	string GetTransfer();
public:
	Transaction();
	void SetDeposit(Account* account, int value, int fee, string message);
	void SetWithdraw(Account* account, int value, int fee, string message);
	void SetTransfer(Account* account, Account* transferAccount, int value, int fee, string message);
	string GetInfo();
};
