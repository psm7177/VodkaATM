#pragma once
#include "Account.h"

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
string Account::IsValid(Card* card) {
	Account* ca = card->GetAccount();
	if (userName != ca->userName) return "Mismatch: User Name";
	if (accNumber != ca->accNumber) return "Mismatch: Account Number";
	if (accBank != ca->GetAccBank()) return "Mismatch: Bank";
	if (accPW != ca->accPW) return "Wrong Password";
	return "Valid";
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