#pragma once
#include "Bank.h"

Bank::Bank(string name) {
    this->bankName = name;
    BankManager::instance()->AddBank(name, this);
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
    string accNum = acc->GetAccNum();
    if (this->accountMap.find(accNum) != this->accountMap.end()) {
        delete    acc;
        throw string(Language::Eng2Kor("exist same account number in ") + this->bankName);
    }
    this->accountMap[accNum] = acc;
    return acc;
}

void Bank::Deposit(Account* account, int value, int fee) {
    int amount = value - fee;
    if (!account->CanChangeFunds(amount)) {
        throw string(Language::Eng2Kor("low money error") + account->GetAccNum()); // TODO: Write error Message
    }

    account->ChangeValance(amount);
}

void Bank::Withdrawal(Account* account, int value, int fee) {
    int amount = -value - fee;
    if (!account->CanChangeFunds(amount)) {
        throw string(Language::Eng2Kor("low money error") + account->GetAccNum()); // TODO: Write error Message
    }

    account->ChangeValance(amount);
}

void Bank::Transfer(Account* fromAccount, Account* toAccount, int value, int fee) {
    if (fromAccount == nullptr) {
        //cash transfer
        if (!toAccount->CanChangeFunds(value - fee)) {
            throw string(Language::Eng2Kor("low money error in ") + toAccount->GetAccNum());
        }
        toAccount->ChangeValance(value - fee);
        return;
    }
    if (!fromAccount->CanChangeFunds(-value - fee)) {
        throw string(Language::Eng2Kor("low money error in ") + fromAccount->GetAccNum());
    }
    if (!toAccount->CanChangeFunds(value)) {
        throw string(Language::Eng2Kor("low money error in ") + toAccount->GetAccNum());
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
        return Language::Eng2Kor("Well done");
    }
    catch (string e) {
        transaction->SetErrorMessage(e);
        throw e;
    }
}