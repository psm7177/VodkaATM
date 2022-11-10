#pragma once
#include "ATM.h"

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

ATM::ATM(int serial, bool isMulti, bool bilingual, string primaryBank, int initialMoney) {
	this->serialNumber = serial;
	this->isMulti = isMulti;
	this->bilingual = bilingual;
	this->primaryBank = primaryBank;

	this->descriptor = nullptr;

	this->transactions = list<Transaction>();
	this->insertedCard = nullptr;
	this->sessionCount = 0;
	this->cash = initialMoney;

	if (bilingual) AskLanguage();
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