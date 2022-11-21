#include "Bank.h"

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

};