#pragma once
#include "Language.h"

bool Language::onoff = false;

string Language::Eng2Kor(string s) {
	if (!onoff) {
		return s;
	}
	if (s == "Welcome\n\nTo start, please insert your debit card") {
		return "반갑습니다\n\n거래를 시작하시려면 카드를 넣어주세요";
	}
	if (s == "Deposit") {
		return "입금";
	}
	if (s == "Withdrawal") {
		return "출금";
	}
	if (s == "Transfer") {
		return "이체";
	}
}
