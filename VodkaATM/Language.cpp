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
	if (s == "Transaction ID: ") {
		return "�ŷ� ���̵�: ";
	}
	if (s == " occured\n") {
		return " \n";
	}
	if (s == "Transaction ID: ") {
		return "�ŷ� ���̵�: ";
	}
}
