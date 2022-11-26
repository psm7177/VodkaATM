#pragma once
#include "Transaction.h"
#include "BankManager.h"
#include "Bank.h"

Bank::Bank(string name) { 
	this->bankName = name;
	BankManager::instance().AddBank(name, this);
}

Bank::~Bank() {
	// delete account
	for (auto i = this->accountMap.begin(); i != this->accountMap.end(); i++) {
		delete i->second;
	}
}

Account* Bank::GetAccount(string accNumber) {
	return this->accountMap[accNumber];
}

Account* Bank::CreateAccount(string username, int pw, const char* accountNumber, int valance) {
	Account* acc = new Account(username, this, pw, accountNumber, valance);
	this->accountMap[acc->GetAccNum()] = acc;
	return acc;
}

string Bank::Deposit(Account* account, int value, int fee) {
	if (!account->CanChangeFunds(value - fee)) {
		return "error"; // TODO: Write error Message
	}

	account->ChangeValance(value - fee);
	return nullptr;
}

string Bank::Withdrawal(Account* account, int value, int fee) {
	if (!account->CanChangeFunds(-value - fee)) {
		return "error"; // TODO: Write error Message
	}

	account->ChangeValance(value - fee);
	return nullptr;
}

string Bank::Transfer(Account* fromAccount, Account* toAccount, int value, int fee) {
	if (!fromAccount->CanChangeFunds(-value - fee)) {
		return "error";
	}
	if (!toAccount->CanChangeFunds(value)) {
		return "error";
	}
	fromAccount->ChangeValance(-value - fee);
	toAccount->ChangeValance(value);

	return nullptr;
}

string Bank::Query(Transaction* transaction) {
	string type = transaction->GetType();
	Account* myAccount = transaction->GetMyAccount();
	int fee = transaction->GetFee();
	if (type == "Deposit") {
		return this->Deposit(myAccount, transaction->GetValue(), fee);
	}
	else if (type == "Withdrawal") {
		return this->Withdrawal(myAccount, transaction->GetValue(), fee);
	}
	else if (type == "Transfer") {
		return this->Transfer(myAccount, transaction->GetTransferAccount(), transaction->GetValue(), fee);
	}

}