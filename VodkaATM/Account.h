#pragma once
#include<string>
#include "Bank.h"
using namespace std;
class Account {
private:
	int availableFunds;
	string username;
	string accountNumber;
	Bank* accountBank;
	int accountPassword;
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

};