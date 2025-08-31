#ifndef ATM_H
#define ATM_H

#include "Account.h"

class ATM {
public:
    void withdrawMoney(Account &acc, double amount);
    void depositMoney(Account &acc, double amount);
    void checkBalance(const Account &acc);
};

#endif
