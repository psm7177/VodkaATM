#pragma once
#include "Card.h"

int Card::cardIdCount = 0;

Card::Card(bool isadmin, Account* accountaddress) {
    this->isAdmin = isadmin;
    this->account = accountaddress;
    this->id = ++cardIdCount;
}

Account* Card::GetAccount() {
    return account;
}
