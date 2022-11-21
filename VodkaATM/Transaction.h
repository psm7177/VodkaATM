#pragma once
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