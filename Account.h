#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
using namespace std;

class Account {
private:
    int accountNumber;
    string holderName;
    double balance;

public:
    Account(int accNo, string name, double initialBalance);
    void deposit(double amount);
    bool withdraw(double amount);
    void display() const;
    int getAccountNumber() const;
};

#endif
