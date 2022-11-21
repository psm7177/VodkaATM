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

	static string control[2];
	void ClearOutput();
	string GetMain(string s);
	void ShowHomepage();
	void AskLanguage();
public:
	ATM(int serial, bool isMulti, bool bilingual, string primaryBank, int initialMoney);
};