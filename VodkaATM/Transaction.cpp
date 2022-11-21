#pragma once
#include "Transaction.h"

int Transaction::idCount = 0;

Transaction::Transaction() {
	id = ++idCount;
	errorMessage = "No problem";
}
string Transaction::GetDeposit() {
	string ans = string();
	ans += "Transaction ID:\t" + to_string(id) + "\n";
	ans += tnsType + " occured\n";
	ans += "to :\t" + (*myAccount).GetAccNum() + "\n";
	ans += "Transaction Amount:\t" + to_string(value) + "\n";
	ans += "Transaction Fee:\t" + to_string(fee) + "\n";
	ans += "Remark:\t" + errorMessage + "\n";
	return ans;
}
string Transaction::GetWithdrawal() {
	string ans = string();
	ans += "Transaction ID:\t" + to_string(id) + "\n";
	ans += tnsType + " occured\n";
	ans += "from :\t" + (*myAccount).GetAccNum() + "\n";
	ans += "Transaction Amount:\t" + to_string(value) + "\n";
	ans += "Transaction Fee:\t" + to_string(fee) + "\n";
	ans += "Remark:\t" + errorMessage + "\n";
	return ans;
}
string Transaction::GetTransfer() {
	string ans = string();
	ans += "Transaction ID:\t" + to_string(id) + "\n";
	ans += tnsType + " occured\n";
	ans += "from :\t" + (*myAccount).GetAccNum() + "\n";
	ans += "to :\t" + (*transferAccount).GetAccNum() + "\n";
	ans += "Transaction Amount:\t" + to_string(value) + "\n";
	ans += "Transaction Fee:\t" + to_string(fee) + "\n";
	ans += "Remark:\t" + errorMessage + "\n";
	return ans;
}
void Transaction::SetDeposit(Account* account, int value, int fee, string message) {
	tnsType = "Deposit";
	myAccount = account;
	this->value = value;
	this->fee = fee;
	errorMessage = message;
}
void Transaction::SetWithdraw(Account* account, int value, int fee, string message) {
	tnsType = "Withdraw";
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
	if (tnsType == "Withdraw") return GetWithdrawal();
	if (tnsType == "Transfer") return GetTransfer();
}

string Transaction::GetType() {
	return this->tnsType;
}

Account* Transaction::GetMyAccount() {
	return this->myAccount;
}
