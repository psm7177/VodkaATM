#pragma once
#include "Language.h"

string Language::Eng2Kor(string s) {
	if (s == "Welcome\n\nTo start, please insert your debit card") {
		return "반갑습니다\n\n거래를 시작하시려면 카드를 넣어주세요";
	}
	if (s == "1. Print Transaction History.\n2. Exit") {
		return "1. 거래 기록 출력\n2. 거래 중지";
	}
	if (s == "Get printed output.txt.\nPress any key to continue.") {
		return "output.txt 출력 완료\n아무 키를 눌려 계속";
	}
	if (s == "Not valid card") {
		return "등록되지 않은 카드입니다";
	}
	if (s == "Input your password") {
		return "비밀번호를 입력하세요";
	}
	if (s == "Wrong password 1/3") {
		return "잘못된 비밀번호 1/3";
	}
	if (s == "Wrong password 2/3") {
		return "잘못된 비밀번호 2/3";
	}
	if (s == "1. Deposit\n2. Withdrawal\n3. Transfer") {
		return "1. 입금\n2. 출금\n3. 이체";
	}
	if (s == "1. Cash Transfer\n2. Account Transfer") {
		return "1. 무통장입금\n2. 계좌이체";
	}
	if (s == "1. Cash\n2. Check") {
		return "1. 현금\n2. 수표";
	}
	if (s == "Amount of Money") {
		return "금액";
	}
	if (s == "Input source bank name") {
		return "보내실 은행 이름";
	}
	if (s == "Input source account number") {
		return "보내실 계좌 번호";
	}
	if (s == "Input bank name to transfer") {
		return "받으실 은행 이름";
	}
	if (s == "Input account number to tranfer") {
		return "받으실 계좌 번호";
	}
	if (s == "\n1. Next transaction\n2. Exit") {
		return "\n1. 다음 거래\n2. 나가기";
	}
	if (s == "1. Print receipt\n2. Do not") {
		return "1. 명세서 출력\n2. 출력하지 않음";
	}
	if (s == "") {
		return "";
	}
	if (s == "") {
		return "";
	}
	if (s == "") {
		return "";
	}
	if (s == "") {
		return "";
	}
	if (s == "") {
		return "";
	}
	if (s == "") {
		return "";
	}
	if (s == "") {
		return "";
	}
	if (s == "") {
		return "";
	}
	if (s == "") {
		return "";
	}
	if (s == "") {
		return "";
	}
}
