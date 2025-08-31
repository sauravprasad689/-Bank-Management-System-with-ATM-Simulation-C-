#include "Bank.h"
#include <iostream>
using namespace std;

void Bank::createAccount(int accNo, string name, double balance) {
    accounts.push_back(Account(accNo, name, balance));
    cout << "Account Created Successfully!" << endl;
}

Account* Bank::getAccount(int accNo) {
    for (auto &acc : accounts) {
        if (acc.getAccountNumber() == accNo) {
            return &acc;
        }
    }
    cout << "Account Not Found!" << endl;
    return nullptr;
}

void Bank::showAllAccounts() {
    for (auto &acc : accounts) {
        acc.display();
    }
}
