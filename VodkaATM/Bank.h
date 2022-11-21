#pragma once
#include <list>
#include "Account.h"
class Bank{
private:
	list<Account> accountList;
public:
	string bankName;
	Bank(string name) : bankName(name) {

	};

	bool operator==(const Bank& bank) {
		
	}
	void Deposit(Account* account, int cash) {
		account->changeFunds(cash);
	};

	bool Withdrawal(Account* account, int cash){
		if (account->CanChangeFunds(-cash)){
			account->changeFunds(-cash);
			return true;
		}
		return false;
	};

	bool Transfer(Account* fromAccount, Account* toAccount, int cash) {
		if (fromAccount->CanChangeFunds(-cash)) {
			fromAccount->changeFunds(-cash);
			toAccount->GetBank()->ResponseTransfer(cash);
			return true;
		}
		return false;
	}

	bool ResponseTransfer(int cash) {
		
	}

	string Query(Transaction* transaction) {
		string type = transaction->GetType();
		Account* myAccount = transaction->GetMyAccount();

		if (type == "Deposit") {
			this->Deposit(myAccount,transaction->GetDepositMoney());
		}
		else if (type == "Withdrawal") {
			this->Withdrawal(myAccount, transaction->GetWithdrawalMoney());
		}
		else if (type == "Transfer") {
			this->Transfer(myAccount, transaction->GetTransferAccount(), transaction->GetTransferMoney());
		}
	};
};