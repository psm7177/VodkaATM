#pragma once
#include "Account.h"
#include <string>
using namespace std;

class Transaction {
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
	string GetType();
	Account* GetMyAccount();
	Account* GetTransferAccount();
	int GetValue();
	int GetFee();
};
