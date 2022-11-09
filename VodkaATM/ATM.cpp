#pragma once
#include "Language.h"
#include "Transaction.h"
#include "Card.h"
#include <stdlib.h>
#include <time.h>
#include <list>

class ATM {
private:
	int serialNumber;
	bool isMulti;
	bool bilingual;
	string primaryBank;

	Language* descriptor;
	list<Transaction> transactions;
	Card* insertedCard;

	int sessionCount;
	int cash;
public:
	ATM(int serial, bool isMulti, bool bilingual,string primaryBank,int initialMoney) {
		this->serialNumber = serial;
		this->isMulti = isMulti;
		this->bilingual = bilingual;
		this->primaryBank = primaryBank;

		this->descriptor = nullptr;

		this->transactions = list<Transaction>();
		this->insertedCard = nullptr;
		this->sessionCount = 0;
		this->cash = initialMoney;
	}
};