class Bank;
#include "Card.h"
#include<string>

using namespace std;
class Account {
private:
	int valance;
	string userName;
	string accNumber;
	Bank* accBank;
	int accPW;
public:
	void ChangeValance(int amount);

	bool CanChangeFunds(int amount);
	Bank* GetBank();
	int GetValance();
	string AddValance(int value);
	string GetUserName();
	string GetAccNum();
	Bank* GetAccBank();
	string IsValid(Card* card);
};
