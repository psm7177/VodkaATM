#pragma once
#include "Account.h"
using namespace std;

class Card {
private:
	bool isAdmin;
	Account* account;
public:
	Account* GetAccount();
};