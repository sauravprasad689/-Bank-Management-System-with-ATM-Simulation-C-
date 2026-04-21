#ifndef ACCOUNT_H
#define ACCOUNT_H

// Yeh file ek single bank account ka structure define karti hai.
// Isme account ka basic data aur account-level operations declared hain.

#include <string>
using namespace std;

// Account class ek customer ka individual account represent karti hai.
class Account {
private:
    int accountNumber;
    string holderName;
    double balance;

public:
    // Constructor account ka starting data set karta hai.
    Account(int accNo, string name, double initialBalance);
    // Deposit balance badhata hai taaki paise account me add ho saken.
    void deposit(double amount);
    // Withdraw balance kam karta hai aur fail hone par false return karta hai.
    bool withdraw(double amount);
    // Display account ki current details screen par dikhata hai.
    void display() const;
    // Getter account number deta hai taaki search aur matching ho sake.
    int getAccountNumber() const;
    // Getter holder name deta hai taaki data directly use ho sake.
    string getHolderName() const;
    // Getter current balance deta hai taaki parsing ki zaroorat na pade.
    double getBalance() const;
};

#endif
