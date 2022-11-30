#pragma once
#include "Transaction.h"
#include "Language.h"

Transaction::Transaction(int id) {
	this->id = id;
	errorMessage = "No problem";
}
string Transaction::GetDeposit() {
	string ans = string();
	if (Language::onoff) {
		ans += "거래 아이디: " + to_string(id) + "\n";
		ans += Language::Eng2Kor(tnsType) + "\n";
		if (myAccount == nullptr) ans += "입금 계좌: \n";
		else ans += "입금 계좌 : " + (*myAccount).GetAccNum() + "\n";
		ans += "거래량: " + to_string(value) + "\n";
		ans += "거래 수수료: " + to_string(fee) + "\n";
		ans += "잔액 : " + to_string(myValance) + "\n";
		ans += "특이사항: " + errorMessage + "\n";
	}
	else {
		ans += "Transaction ID: " + to_string(id) + "\n";
		ans += tnsType + " occured\n";
		if (myAccount == nullptr) ans += "to : \n";
		else ans += "to : " + (*myAccount).GetAccNum() + "\n";
		ans += "Transaction Amount: " + to_string(value) + "\n";
		ans += "Transaction Fee: " + to_string(fee) + "\n";
		ans += "Valance : " + to_string(myValance) + "\n";
		ans += "Remark: " + errorMessage + "\n";
	}
	return ans;
}
string Transaction::GetWithdrawal() {
	string ans = string();
	if (Language::onoff) {
		ans += "거래 아이디: " + to_string(id) + "\n";
		ans += Language::Eng2Kor(tnsType) + "\n";
		if (myAccount == nullptr) ans += "출금 계좌 : \n";
		else ans += "출금 계좌 : " + (*myAccount).GetAccNum() + "\n";
		ans += "거래량: " + to_string(value) + "\n";
		ans += "거래 수수료: " + to_string(fee) + "\n";
		ans += "잔액 : " + to_string(myValance) + "\n";
		ans += "특이사항: " + errorMessage + "\n";
	}
	else {
		ans += "Transaction ID: " + to_string(id) + "\n";
		ans += tnsType + " occured\n";
		if (myAccount == nullptr) ans += "from : \n";
		else ans += "from : " + (*myAccount).GetAccNum() + "\n";
		ans += "Transaction Amount: " + to_string(value) + "\n";
		ans += "Transaction Fee: " + to_string(fee) + "\n";
		ans += "Valance : " + to_string(myValance) + "\n";
		ans += "Remark: " + errorMessage + "\n";
	}
	return ans;
}
string Transaction::GetTransfer() {
	string ans = string();
	if (Language::onoff) {
		ans += "거래 아이디: " + to_string(id) + "\n";
		ans += Language::Eng2Kor(tnsType) + "\n";
		if (myAccount == nullptr) ans += "보낼 계좌 : \n";
		else ans += "보낼 계좌 : " + (*myAccount).GetAccNum() + "\n";
		if (transferAccount == nullptr) ans += "받을 계좌 : \n";
		else ans += "받을 계좌 : " + (*transferAccount).GetAccNum() + "\n";
		ans += "거래량: " + to_string(value) + "\n";
		ans += "거래 수수료: " + to_string(fee) + "\n";
		ans += "송금 계좌 잔액 : " + to_string(myValance) + "\n";
		ans += "입금 계좌 잔액 : " + to_string(transferValance) + "\n";
		ans += "특이사항: " + errorMessage + "\n";
	}
	else {
		ans += "Transaction ID: " + to_string(id) + "\n";
		ans += tnsType + " occured\n";
		if (myAccount == nullptr) ans += "from : \n";
		else ans += "from : " + (*myAccount).GetAccNum() + "\n";
		if (transferAccount == nullptr) ans += "to : \n";
		else ans += "to : " + (*transferAccount).GetAccNum() + "\n";
		ans += "Transaction Amount: " + to_string(value) + "\n";
		ans += "Transaction Fee: " + to_string(fee) + "\n";
		ans += "Valance(from) : " + to_string(myValance) + "\n";
		ans += "Valance(to) : " + to_string(transferValance) + "\n";
		ans += "Remark: " + errorMessage + "\n";
	}
	return ans;
}
void Transaction::SetValance(Account* account) {
	if (account != nullptr) myValance = account->GetValance();
}
void Transaction::SetValance(Account* account, Account* transferAccount) {
	if (account != nullptr) myValance = account->GetValance();
	if (transferAccount != nullptr) transferValance = transferAccount->GetValance();
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