#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
using namespace std;

class Transaction {
public:
    string type;       // Deposit, Withdrawal, Transfer, LoanReq
    double amount;
    string dateTime;
    int fromAcc;
    int toAcc;

    Transaction(string t="", double amt=0, string dt="", int from=-1, int to=-1);
};

#endif
