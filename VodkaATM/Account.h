#pragma once
#include<string>
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
	 bool ChangeValance(int amount) {
		this->valance += amount;
	 }

	 bool CanChangeFunds(int amount) {
		 if (this->valance + amount < 0) {
			 return false;
		 }
		 return true;

	 }
	 Bank* GetBank() {
		 return this->accBank;
	 }
	int GetValance();
	string AddValance(int value);
	string GetUserName();
	string GetAccNum();
	Bank* GetAccBank();
	string IsValid(Card* card);
};
