#pragma once
#include<string>
#include "Bank.h"
#include "Card.h"
#include <string>
using namespace std;

class Account {
private:
	int valance;
	string userName;
	string accNumber;
	Bank* accBank;
	int accPW;
public:
	 bool changeFunds(int amount) {
		this->availableFunds += amount;
	 }

	 bool CanChangeFunds(int amount) {
		 if (this->availableFunds + amount < 0) {
			 return false;
		 }
		 return true;

	 }
	 Bank* GetBank() {
		 return this->accountBank;
	 }

	int GetValance();
	string AddValance(int value);
	string GetUserName();
	string GetAccNum();
	Bank* GetAccBank();
	string IsValid(Card* card);
};
