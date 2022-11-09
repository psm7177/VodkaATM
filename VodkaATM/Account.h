#pragma once
#include <string>
#include "Bank.h"
#include "Card.h"
using namespace std;

class Account {
private:
	int valance;
	string userName;
	string accNumber;
	Bank* accBank;
	int accPW;
public:
	int GetValance();
	string AddValance(int value);
	string GetUserName();
	string GetAccNum();
	Bank* GetAccBank();
	string IsValid(Card* card);
};
