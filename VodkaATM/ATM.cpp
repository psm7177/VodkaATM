#pragma once
#include <fstream>
#include "ATM.h"

unordered_map<int, Card*> ATM::allCard = unordered_map<int, Card*>();

ATM::ATM() {
	int transaction_id = 0;
	all_transactions = list<Transaction*>();
	cout << "Default ATM Constructor" << endl;
}

string ATM::control[2] = {
	"\n\
����������������������������������������       Cash/Check Slot\n\
�� 1���� 2���� 3���� 4���� 5��      ��������������������������������\n\
����������������������������������������      ��������������������������������\n\
����������������������������������������       Card Reader\n\
�� 6���� 7���� 8���� 9���� 0��      ��������������������������������\n\
����������������������������������������      ��������������������������������\n\
������������������  ������������������       Receipt Printer\n\
��   OK  ��  �� Cancel��      ��������������������������������\n\
������������������  ������������������      ��������������������������������",
		"\n\
����������������������������������������       ����/��ǥ ���Ա�\n\
�� 1���� 2���� 3���� 4���� 5��      ��������������������������������\n\
����������������������������������������      ��������������������������������\n\
����������������������������������������       ī�� ���Ա�\n\
�� 6���� 7���� 8���� 9���� 0��      ��������������������������������\n\
����������������������������������������      ��������������������������������\n\
������������������  ������������������       ������ ���\n\
��  Ȯ�� ��  ��  ��� ��      ��������������������������������\n\
������������������  ������������������      ��������������������������������\
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
	string ans = "�� ";
	int count = 2;
	for (int i = 0; i < len; ++i) {
		if (s[i] == '\n') {
			for (count; count < lim - 2; ++count) {
				ans += ' ';
			}
		}
		if (count == lim - 2) {
			ans += "��\n�� ";
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
	ans += "��\n";
	string hline = "������������������������������������������������������������������������������������\n";
	string line = "��                                        ��\n";
	string tline = "������������������������������������������������������������������������������������\n";
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
	ShowUI("Select language\n\n1.English\n2.�ѱ���");
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

string Check_bills(int money, bool isit_cash) {
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
	if (count > limit) return "Too many bills";
	else return "";
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

	string error = Check_bills(money, isit_cash);
	if (error == "Too many bills") return error;

	newtransaction->SetDeposit(this->insertedCard->GetAccount(), money, fee, message);
	transaction_id++;
	transactions.push_back(newtransaction);
	all_transactions.push_back(newtransaction);
	error = this->insertedCard->GetAccount()->GetAccBank()->Query(newtransaction);
	return error;
}

string ATM::Withdrawal(int money, string message) {
	if (this->cash < money) {
		return "low money error";
	}
	this->cash -= money;
	int fee = 1000;
	Transaction* newtransaction = new Transaction(transaction_id);
	if (!isPrimary()) {
		fee += 1000;
	}

	string error = Check_bills(money - fee, true);
	if (error == "Too many bills") return error;

	newtransaction->SetWithdrawal(this->insertedCard->GetAccount(), money, fee, message);
	transaction_id++;
	transactions.push_back(newtransaction);
	all_transactions.push_back(newtransaction);
	error = this->insertedCard->GetAccount()->GetAccBank()->Query(newtransaction);
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

	string error;
	if (dest_account != nullptr) {
		error = Check_bills(money, isit_cash);
		if (error == "Too many bills") return error;
	}

	transactions.push_back(newtransaction);
	all_transactions.push_back(newtransaction);
	newtransaction->SetTransfer(source_account, dest_account, money, fee, message);
	transaction_id++;
	error = this->insertedCard->GetAccount()->GetAccBank()->Query(newtransaction);
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

string ATM::RunSession() {
	if (bilingual) AskLanguage();
	ShowHomepage();
	int input_int;
	cin >> input_int;
	try {
		InsertCard(allCard[input_int]);
	}
	catch (...) {
		ShowUI("Not valid card");
	}

	ShowUI("Input your password");
	for (int i = 0; i < 3; ++i) {
		cin >> input_int;
		string message = VerifyCard(input_int);
		if (message == "Login") break;
		else {
			if (i == 2) return CloseSession();
			ShowUI("Wrong password " + to_string(i + 1) + "/3");
		}
	}

	for (int i = 0; i < 3; ++i) {
		int transfer_type = 1;
		int money;
		int input_int3;
		ShowUI("1. Deposit\n2. Withdrawal\n3. Transfer\n4. Exit");
		cin >> input_int;
		if (input_int == 4) {
			return CloseSession();
		}
		if (input_int == 3) {
			ShowUI("1. Cash Transfer\n2. Account Transfer");
			cin >> transfer_type;
		}
		ShowUI("1. Cash\n2. Check");
		cin >> input_int3;
		bool is_cash = input_int3 == 1 ? true : false;
		ShowUI("Amount of Money");
		cin >> money;
		string message;
		switch (input_int) {
		case 1:
			message = Deposit(money, "", is_cash);
			break;
		case 2:
			message = Withdrawal(money, "");
			break;
		case 3:
			string bank_name;
			string acc_num;
			ShowUI("Input bank name to transfer");
			cin >> bank_name;
			ShowUI("Input account number to tranfer");
			cin >> acc_num;
			if (transfer_type == 1) {
				message = Transfer(BankManager::instance().GetBank(bank_name)->GetAccount(acc_num), \
					money, "", is_cash);
			}
			else {
				message = Transfer(this->insertedCard->GetAccount(),\
					BankManager::instance().GetBank(bank_name)->GetAccount(acc_num), \
					money, "", is_cash);
			}
			break;
		}
		ShowUI(message + "\n1. Next transaction\n2. Exit");
		cin >> input_int;
		if (input_int == 2) return CloseSession();
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