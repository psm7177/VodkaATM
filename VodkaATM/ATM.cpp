#pragma once
#include <fstream>
#include "ATM.h"
using namespace std;

unordered_map<int, Card*> ATM::allCard = unordered_map<int, Card*>();

ATM::ATM() {
	int transaction_id = 0;
	all_transactions = list<Transaction*>();
	cout << "Default ATM Constructor" << endl;
}

string ATM::control[2] = {
	"\n\
┌──┐┌──┐┌──┐┌──┐┌──┐       Cash/Check Slot\n\
│ 1││ 2││ 3││ 4││ 5│      ┌──────────────┐\n\
└──┘└──┘└──┘└──┘└──┘      └──────────────┘\n\
┌──┐┌──┐┌──┐┌──┐┌──┐       Card Reader\n\
│ 6││ 7││ 8││ 9││ 0│      ┌──────────────┐\n\
└──┘└──┘└──┘└──┘└──┘      └──────────────┘\n\
┌───────┐  ┌───────┐       Receipt Printer\n\
│   OK  │  │ Cancel│      ┌──────────────┐\n\
└───────┘  └───────┘      └──────────────┘",
		"\n\
┌──┐┌──┐┌──┐┌──┐┌──┐       현금/수표 투입구\n\
│ 1││ 2││ 3││ 4││ 5│      ┌──────────────┐\n\
└──┘└──┘└──┘└──┘└──┘      └──────────────┘\n\
┌──┐┌──┐┌──┐┌──┐┌──┐       카드 투입구\n\
│ 6││ 7││ 8││ 9││ 0│      ┌──────────────┐\n\
└──┘└──┘└──┘└──┘└──┘      └──────────────┘\n\
┌───────┐  ┌───────┐       영수증 출력\n\
│  확인 │  │  취소 │      ┌──────────────┐\n\
└───────┘  └───────┘      └──────────────┘\
		"
};
void ATM::ClearOutput() {
	for (int i = 0; i < 50; ++i) { cout << endl; }
}
string ATM::GetMain(string s) {
	int lim = 43;
	int len = s.length();
	int idxn = 0;
	int idxb = 0;
	for (int i = 0; i < len; ++i) {
		if (s[i] == ' ') {
			idxb = i;
		}
		if (s[i] == '\n') {
			idxn = i;
		}
		if (i - idxn > lim - 4) {
			s[idxb] = '\n';
			idxn = idxb;
		}
	}
	string ans = "│ ";
	int count = 2;
	for (int i = 0; i < len; ++i) {
		if (s[i] == '\n') {
			for (count; count < lim - 2; ++count) {
				ans += ' ';
			}
		}
		if (count == lim - 2) {
			ans += "│\n│ ";
			count = 2;
		}
		else {
			ans += s[i];
			++count;
		}
	}
	for (count; count < lim - 2; ++count) {
		ans += ' ';
	}
	ans += "│\n";
	string hline = "┌────────────────────────────────────────┐\n";
	string line = "│                                        │\n";
	string tline = "└────────────────────────────────────────┘\n";
	int nline = 20;
	while (ans.length() < (lim + 2) * nline) {
		if ((ans.length() / (lim + 2)) % 2 == 0) {
			ans += line;
		}
		if (ans.length() < (lim + 2) * (nline - 2)) {
			ans = line + ans + line;
		}
		else {
			ans = hline + ans + tline;
		}
	}
	return ans;
}
void ATM::ShowHomepage() {
	string home = "Welcome\n\nTo start, please insert your debit card";
	ShowUI(home);
}
void ATM::ShowUI(string s) {
	ClearOutput();
	if (descriptor == nullptr) {
		cout << GetMain(s) << endl;
		cout << control[0] << endl;
	}
	else {
		cout << GetMain(descriptor->Eng2Kor(s)) << endl;
		cout << control[1] << endl;
	}
}

void ATM::AskLanguage() {
	ShowUI("Select language\n\n1.English\n2.한국어");
	string answer;
	cin >> answer;
	if (answer == "2") {
		Language lang = Language();
		this->descriptor = &lang;
	}
}

MultiATM::MultiATM(int serial, bool bilingual, string primaryBank, int initialMoney) {
	this->serialNumber = serial;
	//this->isMulti = isMulti;
	this->bilingual = bilingual;
	this->primaryBank = primaryBank;
	this->descriptor = nullptr;
	this->transactions = list<Transaction*>();
	this->insertedCard = nullptr;
	this->sessionCount = 0;
	this->cash = initialMoney;
}


SingleATM::SingleATM(int serial, bool bilingual, string primaryBank, int initialMoney) {
	this->serialNumber = serial;
	//this->isMulti = isMulti;
	this->bilingual = bilingual;
	this->primaryBank = primaryBank;

	this->descriptor = nullptr;
	this->transactions = list<Transaction*>();
	this->insertedCard = nullptr;
	this->sessionCount = 0;
	this->cash = initialMoney;
}

string SingleATM::InsertCard(Card* mycard) {
	this->insertedCard = mycard;
	Account* myaccount = mycard->GetAccount();
	Bank* myBank = myaccount->GetAccBank();
	if (myBank->bankName == primaryBank) {
		return "Card Verifyed";
	}
	else {
		return "Card Rejected";
	}
}

string MultiATM::InsertCard(Card* mycard) {
	this->insertedCard = mycard;
	Account* myaccount = mycard->GetAccount();
	Bank* myBank = myaccount->GetAccBank();
	return "Card Verifyed";
}


string ATM::CloseSession() {
	ShowTransactionHistory(this->insertedCard->isAdmin);
	this->transactions = list<Transaction*>();
	this->insertedCard = nullptr;
	//End session and show transactions
	return "End Session";
}

void Check_bills(int money, bool isit_cash) {
	int count = 0;
	int limit;
	if (isit_cash) limit = 50;
	else limit = 30;
	while (money > 50000) {
		money -= 50000;
		++count;
	}
	while (money > 10000) {
		money -= 10000;
		++count;
	}
	while (money > 5000) {
		money -= 5000;
		++count;
	}
	while (money > 1000) {
		money -= 1000;
		++count;
	}
	if (count > limit) throw "Too many bills";
}

string ATM::Deposit(int money, string message, bool isit_cash) {
	int fee = 0;
	Transaction* newtransaction = new Transaction(transaction_id);
	if (!isPrimary()) {
		fee += 1000;
	}
	if (isit_cash) {
		this->cash += money;
	}

	Check_bills(money, isit_cash);

	newtransaction->SetDeposit(this->insertedCard->GetAccount(), money, fee, message);
	string error = this->insertedCard->GetAccount()->GetAccBank()->Query(newtransaction);
	transaction_id++;
	transactions.push_back(newtransaction);
	all_transactions.push_back(newtransaction);
	return error;
}

string ATM::Withdrawal(int money, string message) {
	if (money > 500000) {
		throw string("Too large money");
	}
	if (this->cash < money) {
		throw string("low money error");
	}
	this->cash -= money;
	int fee = 1000;
	Transaction* newtransaction = new Transaction(transaction_id);
	if (!isPrimary()) {
		fee += 1000;
	}

	Check_bills(money - fee, true);

	newtransaction->SetWithdrawal(this->insertedCard->GetAccount(), money, fee, message);
	string error = this->insertedCard->GetAccount()->GetAccBank()->Query(newtransaction);
	transaction_id++;
	transactions.push_back(newtransaction);
	all_transactions.push_back(newtransaction);
	return error;
}
string ATM::Transfer(Account* dest_account, int money, string message, bool isit_cash) {
	return Transfer(nullptr, dest_account, money, message, isit_cash);
}
string ATM::Transfer(Account* source_account, Account* dest_account, int money, string message, bool isit_cash) {
	int fee = 2000;
	Transaction* newtransaction = new Transaction(transaction_id);
	if (!isPrimary()) {
		fee += 1000;
	}
	if (dest_account->GetAccBank()->bankName != primaryBank) {
		fee += 1000;
	}

	if (dest_account != nullptr) {
		Check_bills(money, isit_cash);
	}

	newtransaction->SetTransfer(source_account, dest_account, money, fee, message);
	string error = this->insertedCard->GetAccount()->GetAccBank()->Query(newtransaction);
	transactions.push_back(newtransaction);
	all_transactions.push_back(newtransaction);
	transaction_id++;
	return error;
}

Card* SingleATM::IssueCard(bool isadmin, Account* newaccount) {
	if (newaccount->GetAccBank()->bankName == this->primaryBank) {
		Card* newcard = new Card(isadmin, newaccount);
		allCard[newcard->id] = newcard;
		return newcard;
	}
	else {
		cout << "Not This ATM" << endl;
	}
}

Card* MultiATM::IssueCard(bool isadmin, Account* newaccount) {
	//make account
	Card* newcard = new Card(isadmin, newaccount);
	allCard[newcard->id] = newcard;
	return newcard;
}

string ATM::GetTransactionHistory(bool isAdmin) {
	list<Transaction*> transactionList = isAdmin ? this->all_transactions : this->transactions;

	string ret = "";
	for (auto i = transactionList.begin(); i != transactionList.end(); i++) {
		Transaction* t = *i;
		ret += t->GetInfo();
		ret += "\n";
	}
	return ret;
}

void ATM::ShowTransactionHistory(bool isAdmin) {
	string history = this->GetTransactionHistory(isAdmin);
	if (isAdmin) {
		ofstream fout("output.txt");
		fout << history << endl;
		fout.close();
	}
	else {
		ShowUI(history + "\nPress any key to continue");
		string asdf;
		cin >> asdf;
	}

}

string ATM::RunAdminSession(string& input) {
	while (true)
	{
		ShowUI("1. Print Transaction History.\n2. Exit");
		cin >> input;
		if (input == "Cancel") return CloseSession();
		switch (stoi(input))
		{
		case 1:
			ShowTransactionHistory(this->insertedCard->isAdmin);
			ShowUI("Get printed output.txt.\n Press any key to continue.");
			cin >> input;
			break;
		case 2:
			return CloseSession();
			break;
		}
	}
}

string ATM::RunSession() {
	if (bilingual) AskLanguage();
	ShowHomepage();
	string input;
	cin >> input;
	if (input == "Cancel") return CloseSession();
	try {
		InsertCard(allCard[stoi(input)]);
	}
	catch (...) {
		ShowUI("Not valid card");
	}
	if (this->insertedCard->isAdmin) {
		return RunAdminSession(input);
	}
	ShowUI("Input your password");
	for (int i = 0; i < 3; ++i) {
		cin >> input;
		if (input == "Cancel") return CloseSession();
		string message = VerifyCard(stoi(input));
		if (message == "Login") break;
		else {
			if (i == 2) return CloseSession();
			ShowUI("Wrong password " + to_string(i + 1) + "/3");
		}
	}
	for (int i = 0; i < 3; ++i) {
		string transfer_type;
		string money;
		string input2;
		ShowUI("1. Deposit\n2. Withdrawal\n3. Transfer");
		cin >> input;
		if (input == "Cancel") return CloseSession();
		if (stoi(input) == 3) {
			ShowUI("1. Cash Transfer\n2. Account Transfer");
			cin >> transfer_type;
			if (transfer_type == "Cancel") return CloseSession();
		}
		ShowUI("1. Cash\n2. Check");
		cin >> input2;
		if (input2 == "Cancel") return CloseSession();
		bool is_cash = stoi(input2) == 1 ? true : false;
		ShowUI("Amount of Money");
		cin >> money;
		if (money == "Cancel") return CloseSession();
		string message;
		try {
			switch (stoi(input)) {
			case 1:
				message = Deposit(stoi(money), "", is_cash);
				break;
			case 2:
				message = Withdrawal(stoi(money), "");
				break;
			case 3:
				string sbank_name;
				string sacc_name;
				ShowUI("Input source bank name");

				string bank_name;
				string acc_num;
				ShowUI("Input bank name to transfer");
				cin >> bank_name;
				if (bank_name == "Cancel") return CloseSession();
				ShowUI("Input account number to tranfer");
				cin >> acc_num;
				if (acc_num == "Cancel") return CloseSession();
				if (stoi(transfer_type) == 1) {
					message = Transfer(BankManager::instance().GetBank(bank_name)->GetAccount(acc_num), \
						stoi(money), "", is_cash);
				}
				else {
					message = Transfer(this->insertedCard->GetAccount(), \
						BankManager::instance().GetBank(bank_name)->GetAccount(acc_num), \
						stoi(money), "", is_cash);
				}
				break;
			}
		}
		catch (string e) {
			ShowUI(e);
			return CloseSession();
		}
		ShowUI(message + "\n1. Next transaction\n2. Exit");
		cin >> input;
		if (input == "Cancel") return CloseSession();
		if (stoi(input) == 2) return CloseSession();
	}
	return CloseSession();
}

string ATM::VerifyCard(int pw) {
	if (this->insertedCard->GetAccount()->CheckPW(pw)) {
		return "Login";
	}
	return "Wrong password";
}

bool ATM::isPrimary() {
	return this->insertedCard->GetAccount()->GetAccBank()->bankName == this->primaryBank;
}