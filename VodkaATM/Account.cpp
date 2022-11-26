#pragma once
#include "Account.h"

int Account::accNumberCount = 0;
Account::Account(string name, Bank* bank, int pw, string accountNumber, int valance) {
	this->userName = name;
	this->accBank = bank;
	this->accPW = pw;
	this->valance = valance;

	if (accountNumber == "") {
		char accnum[15];
		snprintf(accnum, 12, "%012d", ++this->accNumberCount);
		this->accNumber = string(accnum);
	}
	else {
		this->accNumber = accountNumber;
	}
}

bool Account::CheckPW(int pw) {
	if (this->accPW == pw) return true;
	else return false;
}
int Account::GetValance() {
	return this->valance;
}
string Account::AddValance(int value) {
	int tmp = valance + value;
	if (tmp < 0) return string(Language::Eng2Kor("Not enough valance"));
	valance = tmp;
	return string(Language::Eng2Kor("Done"));
}
string Account::GetUserName() {
	return this->userName;
}
string Account::GetAccNum() {
	return this->accNumber;
}
Bank* Account::GetAccBank() {
	return this->accBank;
}

void Account::ChangeValance(int amount) {
	this->valance += amount;
}

bool Account::CanChangeFunds(int amount) {
	if (this->valance + amount < 0) {
		return false;
	}
	return true;
}

Bank* Account::GetBank() {
	return this->accBank;
}