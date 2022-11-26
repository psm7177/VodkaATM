#pragma once
class Account;
using namespace std;

class Card {
private:
	bool isAdmin;
	Account* account;
public:
	Card(bool, Account*);
	Account* GetAccount();
};