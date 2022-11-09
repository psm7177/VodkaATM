#pragma once
class Account;
using namespace std;

class Card {
private:
	bool isAdmin;
	Account* account;
public:
	Account* GetAccount();
};