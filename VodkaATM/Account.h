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
	Account(string name, Bank* bank, int pw);
	void ChangeValance(int amount);

	bool CanChangeFunds(int amount);
	Bank* GetBank();
	int GetValance();
	string AddValance(int value);
	string GetUserName();
	string GetAccNum();
	Bank* GetAccBank();
	bool CheckPW(int pw);
};
