#pragma once
#include "Language.h"

bool Language::onoff = false;

string Language::Eng2Kor(string s) {
	if (!onoff) {
		return s;
	}
	if (s == "Welcome\n\nTo start, please insert your debit card") {
		return "�ݰ����ϴ�\n\n�ŷ��� �����Ͻ÷��� ī�带 �־��ּ���";
	}
	if (s == "Deposit") {
		return "�Ա�";
	}
	if (s == "Withdrawal") {
		return "���";
	}
	if (s == "Transfer") {
		return "��ü";
	}
}
