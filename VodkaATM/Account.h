class Bank;
#include "Card.h"
#include "Language.h"
#include<string>

using namespace std;
class Account {
private:
	int valance;
	string userName;
	static int accNumberCount;
	string accNumber;
	Bank* accBank;
	int accPW;
public:
	Account(string name, Bank* bank, int pw, string accountNumber = "", int valance = 0);
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
