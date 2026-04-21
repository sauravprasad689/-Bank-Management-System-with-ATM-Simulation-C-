#ifndef ATM_H
#define ATM_H

// Yeh file ATM helper class ko declare karti hai.
// ATM class account operations ko simple wrapper ke through call karti hai.

#include "Account.h"

// ATM class customer-facing basic actions ko trigger karti hai.
class ATM {
public:
    // Withdraw request ko selected account tak forward karta hai.
    void withdrawMoney(Account &acc, double amount);
    // Deposit request ko selected account tak forward karta hai.
    void depositMoney(Account &acc, double amount);
    // Balance check ke liye account details dikhata hai.
    void checkBalance(const Account &acc);
};

#endif
