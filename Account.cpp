// Yeh file Account class ke basic account operations implement karti hai.
// Yahan balance update aur account details display ka logic rakha gaya hai.

#include "Account.h"
#include <iostream>
using namespace std;

// Constructor naya account object banate waqt initial values store karta hai.
Account::Account(int accNo, string name, double initialBalance) {
    accountNumber = accNo;
    holderName = name;
    balance = initialBalance;
}

// Deposit function balance me diya gaya amount add karta hai.
void Account::deposit(double amount) {
    // Negative ya zero deposit allow nahi hai.
    if (amount <= 0) {
        cout << "Invalid Deposit Amount! Please enter a positive amount." << endl;
        return;
    }

    balance += amount;
    cout << "Deposited: " << amount << " | New Balance: " << balance << endl;
}

// Withdraw function pehle check karta hai ki balance enough hai ya nahi.
bool Account::withdraw(double amount) {
    // Negative ya zero withdraw allow nahi hai.
    if (amount <= 0) {
        cout << "Invalid Withdrawal Amount! Please enter a positive amount." << endl;
        return false;
    }

    // Agar amount zyada ho to transaction reject kar dete hain.
    if (amount > balance) {
        cout << "Insufficient Balance!" << endl;
        return false;
    }

    // Valid withdraw hone par balance update hota hai.
    balance -= amount;
    cout << "Withdrawn: " << amount << " | Remaining Balance: " << balance << endl;
    return true;
}

// Display function account ki summary user ko dikhata hai.
void Account::display() const {
    cout << "Account No: " << accountNumber
         << " | Holder: " << holderName
         << " | Balance: " << balance << endl;
}

// Yeh function sirf account number return karta hai for lookup.
int Account::getAccountNumber() const {
    return accountNumber;
}

// Yeh function holder ka naam return karta hai.
string Account::getHolderName() const {
    return holderName;
}

// Yeh function current balance return karta hai.
double Account::getBalance() const {
    return balance;
}
