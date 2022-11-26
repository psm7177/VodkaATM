#pragma once
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
	string Deposit(Account* account, int value, int fee);
	string Withdrawal(Account* account, int value, int fee);
	string Transfer(Account* fromAccount, Account* toAccount, int value, int fee);
	Account* CreateAccount(string username, int pw);
	string Query(Transaction* transaction);
};