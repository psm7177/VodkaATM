#pragma once
#include "Card.h"

Card::Card(bool isadmin, Account* accountaddress) {
    this->isAdmin = isadmin;
    this->account = accountaddress;
}

Account* Card::GetAccount() {
	return account;
}
