#pragma once
#include "Account.h"

Account::Account(string name, Bank* bank, int pw) {
	this->userName = name;
	this->accBank = bank;
	this->accPW = pw;
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
	if (tmp < 0) return string("Not enough valance");
	valance = tmp;
	return string("Done");
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