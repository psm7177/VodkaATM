#pragma once
#include "Transaction.h"
#include "BankManager.h"
#include "Language.h"
#include <unordered_map>
using namespace std;
class Bank{
private:
	unordered_map<string, Account*> accountMap;
public:
	string bankName;
	Bank(string name);
	~Bank();
	Account* GetAccount(string accNumber);
	void Deposit(Account* account, int value, int fee);
	void Withdrawal(Account* account, int value, int fee);
	void Transfer(Account* fromAccount, Account* toAccount, int value, int fee);
	Account* CreateAccount(string username, int pw, const char* accountNumber = "", int valance = 0);
	string Query(Transaction* transaction);
};