#include "BankManager.h"
BankManager* BankManager ::instance_ = nullptr;

BankManager* BankManager::instance(){
    if (instance_ == nullptr) {
        instance_ = new BankManager();
    }
    return instance_;
}

void BankManager::AddBank(string name, Bank* bank) {
    this->bankMap[name] = bank;
}

Bank* BankManager::GetBank(string name) {
    return this->bankMap[name];
}