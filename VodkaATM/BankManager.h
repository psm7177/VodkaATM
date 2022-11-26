#pragma once
#include <unordered_map>
#include "Language.h"
class Bank;

using namespace std;

class BankManager {
public:
    static BankManager instance();
    void AddBank(string name, Bank* bank);
    Bank* GetBank(string name);
private:
    BankManager() {}
    unordered_map<string, Bank*> bankMap;
    static BankManager* instance_;
};