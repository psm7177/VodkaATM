#pragma once
#include <iostream>
#include "ATM.h"
#include "Language.h"
using namespace std;

//int main() {
//    //ATM 积己, Bank 积己, Account 积己
//    Bank kakao = Bank("Kakao");
//    Account* account1 = kakao.CreateAccount("David", 1234, "111111111111", 100000);
//    Account* account2 = kakao.CreateAccount("Jane", 1234, "222222222222", 0);
//    SingleATM atm1 = SingleATM(111111, false, "Kakao", 50000);
//    //Card 积己
//    Card* card1 = atm1.IssueCard(false, account1);
//    //Card Insert 窍扁
//    atm1.InsertCard(card1);
//    //价陛, 免陛, 殿殿
//    atm1.Deposit(1000, string(""), true);
//    atm1.Withdrawal(2000, string(""));
//    atm1.Transfer(account2, 5000, string(""));
//    //Session end 窍扁
//    atm1.CloseSession();
//}

int main() {
    Bank kakao = Bank("Kakao");
    Bank shinhan = Bank("Shinhan");
    Account* account1 = kakao.CreateAccount("David", 1, "111111111111", 100000);
    Account* account2 = shinhan.CreateAccount("Jane", 2, "222222222222");
    Account* account3 = kakao.CreateAccount("Kate", 3, "333333333333", 3000);
    SingleATM atm1 = SingleATM(111111, false, "Kakao", 50000);
    MultiATM atm2 = MultiATM(222222, true, "Shinhan", 0);
    MultiATM atm3 = MultiATM(333333, true, "Shinhan", 2000);

    Card* card1 = atm2.IssueCard(false, account1);
    Card* card2 = atm2.IssueCard(false, account2);
    Card* card3 = atm2.IssueCard(false, account3);

    atm1.InsertCard(card1);
    atm1.Deposit(1000, "", true);
    atm1.CloseSession();

    atm2.InsertCard(card1);
    atm2.Transfer(account2, 5000, "");
    atm2.CloseSession();

    atm3.InsertCard(card2);
    atm3.Withdrawal(4000, "");
    atm3.CloseSession();
}