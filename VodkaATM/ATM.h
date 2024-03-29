#pragma once
#include "Language.h"
#include "Transaction.h"
#include "Card.h"
#include "Bank.h"
#include "BankManager.h"
#include <unordered_map>
#include <stdlib.h>
#include <time.h>
#include <list>

class ATM {
protected:
	int serialNumber;
	bool bilingual;
	string primaryBank;

	int transaction_id;
	list<Transaction*> all_transactions;
	list<Transaction*> transactions;
	Card* insertedCard;

	int sessionCount;
	int cash;
	static unordered_map<int, Card*> allCard;

	bool isPrimary();

	static string control[2];
	void ClearOutput();
	string GetMain(string s);
	void ShowHomepage();
	void ShowUI(string s);
	void AskLanguage();

public:
	ATM();
	static list<Bank*> Banks;
	virtual string InsertCard(Card* mycard) = 0; // Card insertion
	string CloseSession(); // Session ends
	string VerifyCard(int pw); // Verify Card with password
	string Deposit(int money, string message, bool isit_cash); // Deposit cash, make transaction
	string Withdrawal(int money, string message); // Withdraw cash, make transaction
	string Transfer(Account* dest_account, int money, string message, bool isit_cash); // Transfer cash, maake transaction
	string Transfer(Account* source_account, Account* dest_account, int money, string message, bool isit_cash); // Transfer cash, maake transaction
	//virtual Card* IssueCard(string bankname, string accnum); // make card
	string GetTransactionHistory(bool isAdmin); // Show Transaction History
	void ShowTransactionHistory(bool isAdmin);
	string RunSession(); // return error message, session start
	string RunAdminSession(string& input);
};

class MultiATM : public ATM {
public:
	MultiATM(int serial, bool bilingual, string primaryBank, int initialMoney); //Done
	string InsertCard(Card* mycard); //Done
	Card* IssueCard(bool isadmin, Account* newaccoun); //Done
};

class SingleATM : public ATM {
public:
	SingleATM(int serial, bool bilingual, string primaryBank, int initialMoney); //Done
	string InsertCard(Card* mycard); //Done
	Card* IssueCard(bool isadmin, Account* newaccoun); //Done
};