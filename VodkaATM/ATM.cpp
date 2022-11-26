#pragma once
#include "ATM.h"

ATM::ATM() {
	int transaction_id = 0;
	cout << "Default ATM Instructor" << endl;
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
	int nline = 9;
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
	if (descriptor == nullptr) {
		cout << GetMain(home) << endl;
		cout << control[0] << endl;
	}
	else {
		cout << GetMain(descriptor->Eng2Kor(home)) << endl;
		cout << control[1] << endl;
	}
}

void ATM::AskLanguage() {
	cout << GetMain("Select language\n\n1.English\n2.한국어") << endl;
	string answer;
	cin >> answer;
	if (answer == "2") {
		Language lang = Language();
		this->descriptor = &lang;
	}
	ShowHomepage();
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
	//End session and show transactions
	return "End Session";
}

string ATM::Deposit(int money, string message) {
	int fee = 0;
	Transaction* newtransaction = new Transaction(transaction_id);
	if (this->insertedCard->GetAccount()->GetAccBank()->bankName == primaryBank) {
		fee += 1000;
	}
	newtransaction->SetDeposit(this->insertedCard->GetAccount(), money, fee, message);
	transaction_id++;
	transactions.push_back(newtransaction);
	all_transactions.push_back(newtransaction);
	string error = this->insertedCard->GetAccount()->GetAccBank()->Query(newtransaction);
	return error;
}
string ATM::Withdraw(int money, string message) {
	int fee = 1000;
	Transaction* newtransaction = new Transaction(transaction_id);
	if (this->insertedCard->GetAccount()->GetAccBank()->bankName == primaryBank) {
		fee += 1000;
	}
	newtransaction->SetWithdraw(this->insertedCard->GetAccount(), money, fee, message);
	transaction_id++;
	transactions.push_back(newtransaction);
	all_transactions.push_back(newtransaction);
	string error = this->insertedCard->GetAccount()->GetAccBank()->Query(newtransaction);
	return error;
}
string ATM::Transfer(Account* dest_account, int money, string message) {
	int fee = 2000;
	Transaction* newtransaction = new Transaction(transaction_id);
	if (this->insertedCard->GetAccount()->GetAccBank()->bankName == primaryBank) {
		fee += 1000;
	}
	if (dest_account->GetAccBank()->bankName == primaryBank) {
		fee += 1000;
	}
	transactions.push_back(newtransaction);
	all_transactions.push_back(newtransaction);
	newtransaction->SetTransfer(this->insertedCard->GetAccount(), dest_account, money, fee, message);
	transaction_id++;
	string error = this->insertedCard->GetAccount()->GetAccBank()->Query(newtransaction);
	return error;
}

Card* SingleATM::IssueCard(bool isadmin, Account* newaccount) {
	if (newaccount->GetAccBank()->bankName == this->primaryBank) {
		Card* newcard = new Card(isadmin, newaccount);
		return newcard;
	}
	else {
		cout << "Not This ATM" << endl;
	}
}

Card* MultiATM::IssueCard(bool isadmin, Account* newaccount) {
	//make account
	Card* newcard = new Card(isadmin, newaccount);
	return newcard;
}

string ATM::TransactionHistory() {
	string ret = "";
	for (auto i = this->transactions.begin(); i != this->transactions.end(); i++) {
		Transaction* t = *i;
		ret += t->GetInfo();
		ret += "\n";
	}
	return ret;
}

string ATM::RunSession() {
	string Errormessage = "";
	if (bilingual) AskLanguage();
	return Errormessage;
}

string ATM::VerifyCard(int pw) {
	if (this->insertedCard->GetAccount()->CheckPW(pw)) {
		return "Login";
	}
	return "Wrong password";
}
string ATM::TransactionHistory() {
	string ret = "";
	for (auto i = this->transactions.begin(); i != this->transactions.end(); i++) {
		Transaction* t = *i;
		ret += t->GetInfo();
		ret += "\n";
	}
	return ret;
}