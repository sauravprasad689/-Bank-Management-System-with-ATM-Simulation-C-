#include "Account.h"
#include <iostream>
using namespace std;

Account::Account(int accNo, string name, double initialBalance) {
    accountNumber = accNo;
    holderName = name;
    balance = initialBalance;
}

void Account::deposit(double amount) {
    balance += amount;
    cout << "Deposited: " << amount << " | New Balance: " << balance << endl;
}

bool Account::withdraw(double amount) {
    if (amount > balance) {
        cout << "Insufficient Balance!" << endl;
        return false;
    }
    balance -= amount;
    cout << "Withdrawn: " << amount << " | Remaining Balance: " << balance << endl;
    return true;
}

void Account::display() const {
    cout << "Account No: " << accountNumber
         << " | Holder: " << holderName
         << " | Balance: " << balance << endl;
}

int Account::getAccountNumber() const {
    return accountNumber;
}
