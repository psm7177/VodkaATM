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
	if (s == "1. Print Transaction History.\n2. Exit") {
		return "1. �ŷ� ��� ���\n2. �ŷ� ����";
	}
	if (s == "Get printed output.txt.\nPress any key to continue.") {
		return "output.txt ��� �Ϸ�\n�ƹ� Ű�� ���� ���";
	}
	if (s == "Press any key to continue") {
		return "�ƹ� Ű�� ���� ���";
	}
	if (s == "Not valid card") {
		return "��ϵ��� ���� ī���Դϴ�";
	}
	if (s == "Input your password") {
		return "��й�ȣ�� �Է��ϼ���";
	}
	if (s == "Wrong password 1/3") {
		return "�߸��� ��й�ȣ 1/3";
	}
	if (s == "Wrong password 2/3") {
		return "�߸��� ��й�ȣ 2/3";
	}
	if (s == "Wrong password 3/3 \nLimit exceeded. \nPress any key.") {
		return "�߸��� ��й�ȣ 3/3 \n�ѵ��� �ʰ��Ͽ����ϴ�.\n�ƹ� Ű�� �Է��ϼ���.";
	}
	
	if (s == "1. Deposit\n2. Withdrawal\n3. Transfer") {
		return "1. �Ա�\n2. ���\n3. ��ü";
	}
	if (s == "1. Cash Transfer\n2. Account Transfer") {
		return "1. �������Ա�\n2. ������ü";
	}
	if (s == "1. Cash\n2. Check") {
		return "1. ����\n2. ��ǥ";
	}
	if (s == "Amount of Money") {
		return "�ݾ�";
	}
	if (s == "Input source bank name") {
		return "������ ���� �̸�";
	}
	if (s == "Input source account number") {
		return "������ ���� ��ȣ";
	}
	if (s == "Input bank name to transfer") {
		return "������ ���� �̸�";
	}
	if (s == "Input account number to tranfer") {
		return "������ ���� ��ȣ";
	}
	if (s == "\n1. Next transaction\n2. Exit") {
		return "\n1. ���� �ŷ�\n2. ������";
	}
	if (s == "1. Print receipt\n2. Do not") {
		return "1. ���� ���\n2. ������� ����";
	}
	if (s == "Transaction ID: ") {
		return "�ŷ� ���̵�: ";
	}
	if (s == "Withdrawal") {
		return "���";
	}
	if (s == "Transfer") {
		return "��ü";
	}
	if (s == "exist same account number in ") {
		return "�Ȱ��� ���� ��ȣ�� �����մϴ�.";
	}
	if (s == "low money error") {
		return "ATM �ܾ��� �����մϴ�.";
	}
	if (s == "low money error in ") {
		return "���� �ܾ��� �ʹ� �����ϴ�.";
	}
	if (s == "Well done") {
		return "�ùٸ��� ����Ǿ����ϴ�.";
	}
	if (s == "Not enough valance") {
		return "�ܾ��� �����մϴ�";
	}
	if (s == "Done") {
		return "�Ϸ�";
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
	return s;
}
