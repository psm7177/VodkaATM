#pragma once
using namespace std;
class Bank{
public:
	string Deposit(Account* account, int value, int fee);
	string Withdrawal(Account* account, int value, int fee);

	string Transfer(Account* fromAccount, Account* toAccount, int value, int fee);

	//bool ResponseTransfer(int cash);

	string Query(Transaction* transaction);
};