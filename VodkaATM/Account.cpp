#pragma once
#include "Account.h"

int Account::GetValance() {
	return valance;
}
string Account::AddValance(int value) {
	int tmp = valance + value;
	if (tmp < 0) return string("Not enough valance");
	valance = tmp;
	return string("Done");
}
string Account::GetUserName() {
	return userName;
}
string Account::GetAccNum() {
	return accNumber;
}
Bank* Account::GetAccBank() {
	return accBank;
}
string Account::IsValid(Card* card) {
	Account* ca = card->GetAccount();
	if (userName != ca->userName) return "Mismatch: User Name";
	if (accNumber != ca->accNumber) return "Mismatch: Account Number";
	if (accBank != ca->accBank) return "Mismatch: Bank";
	if (accPW != ca->accPW) return "Wrong Password";
	return "Valid";
}
