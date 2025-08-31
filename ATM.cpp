#include "ATM.h"
#include <iostream>
using namespace std;

void ATM::withdrawMoney(Account &acc, double amount) {
    acc.withdraw(amount);
}

void ATM::depositMoney(Account &acc, double amount) {
    acc.deposit(amount);
}

void ATM::checkBalance(const Account &acc) {
    acc.display();
}
