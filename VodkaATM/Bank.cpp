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

void Bank::Deposit(Account* account, int value, int fee) {
	if (!account->CanChangeFunds(value - fee)) {
		throw "error"; // TODO: Write error Message
	}

	account->ChangeValance(value - fee);
}

void Bank::Withdrawal(Account* account, int value, int fee) {
	if (!account->CanChangeFunds(-value - fee)) {
		throw "error"; // TODO: Write error Message
	}

	account->ChangeValance(value - fee);
}

void Bank::Transfer(Account* fromAccount, Account* toAccount, int value, int fee) {
	if (!fromAccount->CanChangeFunds(-value - fee)) {
		throw "error";
	}
	if (!toAccount->CanChangeFunds(value)) {
		throw "error";
	}
	fromAccount->ChangeValance(-value - fee);
	toAccount->ChangeValance(value);

}

string Bank::Query(Transaction* transaction) {
	string type = transaction->GetType();
	Account* myAccount = transaction->GetMyAccount();
	int fee = transaction->GetFee();
	try {
		if (type == "Deposit") {
			this->Deposit(myAccount, transaction->GetValue(), fee);
		}
		else if (type == "Withdrawal") {
			this->Withdrawal(myAccount, transaction->GetValue(), fee);
		}
		else if (type == "Transfer") {
			this->Transfer(myAccount, transaction->GetTransferAccount(), transaction->GetValue(), fee);
		}
		return "Well done"; //
	}
	catch (string e) {
		return e;
	}
}
	