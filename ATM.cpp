// Yeh file ATM class ke simple wrapper functions implement karti hai.
// Iska kaam Account class ke methods ko direct call karna hai.

#include "ATM.h"
#include <iostream>
using namespace std;

// Withdraw request ko account object par execute karta hai.
void ATM::withdrawMoney(Account &acc, double amount) {
    acc.withdraw(amount);
}

// Deposit request ko account object par execute karta hai.
void ATM::depositMoney(Account &acc, double amount) {
    acc.deposit(amount);
}

// Balance check ke time account ki details screen par show hoti hain.
void ATM::checkBalance(const Account &acc) {
    acc.display();
}
