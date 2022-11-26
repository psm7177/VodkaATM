#pragma once
class Account;
using namespace std;

class Card {
private:
	Account* account;
public:
	bool isAdmin;
	int id;
	static int cardIdCount;
	Card(bool, Account*);
	Account* GetAccount();
};