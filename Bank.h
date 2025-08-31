#ifndef BANK_H
#define BANK_H

#include "Account.h"
#include <vector>

class Bank {
private:
    vector<Account> accounts;

public:
    void createAccount(int accNo, string name, double balance);
    Account* getAccount(int accNo);
    void showAllAccounts();
};

#endif
