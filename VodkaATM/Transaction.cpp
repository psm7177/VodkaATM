#pragma once
#include "Transaction.h"

Transaction::Transaction(int id) {
	this->id = id;
	errorMessage = "No problem";
}
string Transaction::GetDeposit() {
	string ans = string();
	ans += "Transaction ID: " + to_string(id) + "\n";
	ans += tnsType + " occured\n";
	if (myAccount == nullptr) ans += "to : \n";
	else ans += "to : " + (*myAccount).GetAccNum() + "\n";
	ans += "Transaction Amount: " + to_string(value) + "\n";
	ans += "Transaction Fee: " + to_string(fee) + "\n";
	ans += "Remark: " + errorMessage + "\n";
	return ans;
}
string Transaction::GetWithdrawal() {
	string ans = string();
	ans += "Transaction ID: " + to_string(id) + "\n";
	ans += tnsType + " occured\n";
	if (myAccount == nullptr) ans += "from : \n";
	else ans += "from : " + (*myAccount).GetAccNum() + "\n";
	ans += "Transaction Amount: " + to_string(value) + "\n";
	ans += "Transaction Fee: " + to_string(fee) + "\n";
	ans += "Remark: " + errorMessage + "\n";
	return ans;
}
string Transaction::GetTransfer() {
	string ans = string();
	ans += "Transaction ID: " + to_string(id) + "\n";
	ans += tnsType + " occured\n";
	if (myAccount == nullptr) ans += "from : \n";
	else ans += "from : " + (*myAccount).GetAccNum() + "\n";
	if (transferAccount == nullptr) ans += "to : \n";
	else ans += "to : " + (*transferAccount).GetAccNum() + "\n";
	ans += "Transaction Amount: " + to_string(value) + "\n";
	ans += "Transaction Fee: " + to_string(fee) + "\n";
	ans += "Remark: " + errorMessage + "\n";
	return ans;
}
void Transaction::SetDeposit(Account* account, int value, int fee, string message) {
	tnsType = "Deposit";
	myAccount = account;
	this->value = value;
	this->fee = fee;
	errorMessage = message;
}
void Transaction::SetWithdrawal(Account* account, int value, int fee, string message) {
	tnsType = "Withdrawal";
	myAccount = account;
	this->value = value;
	this->fee = fee;
	errorMessage = message;
}
void Transaction::SetTransfer(Account* account, Account* transferAccount, int value, int fee, string message) {
	tnsType = "Transfer";
	this->transferAccount = transferAccount;
	myAccount = account;
	this->value = value;
	this->fee = fee;
	errorMessage = message;
}
string Transaction::GetInfo() {
	if (tnsType == "Deposit") return GetDeposit();
	if (tnsType == "Withdrawal") return GetWithdrawal();
	if (tnsType == "Transfer") return GetTransfer();
}

string Transaction::GetType() {
	return this->tnsType;
}

Account* Transaction::GetMyAccount() {
	return this->myAccount;
}

Account* Transaction::GetTransferAccount() {
	return this->transferAccount;
}

int Transaction::GetValue() {
	return this->value;
}

int Transaction::GetFee() {
	return this->fee;
}

void Transaction::SetErrorMessage(string e) {
	this->errorMessage = e;
}