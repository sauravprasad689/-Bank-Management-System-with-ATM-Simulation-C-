// Yeh file Transaction class ka constructor implement karti hai.
// Isme transaction object banate waqt values assign hoti hain.

#include "Transaction.h"

// Yeh helper enum value ko file aur screen ke liye text me convert karta hai.
string transactionTypeToString(TransactionType type) {
    switch (type) {
        case TransactionType::Deposit:
            return "Deposit";
        case TransactionType::Withdrawal:
            return "Withdrawal";
        case TransactionType::Transfer:
            return "Transfer";
        case TransactionType::LoanReq:
            return "LoanReq";
        default:
            return "Unknown";
    }
}

// Yeh helper saved text ko enum value me badalta hai.
TransactionType stringToTransactionType(const string& typeText) {
    if (typeText == "Deposit") {
        return TransactionType::Deposit;
    }

    if (typeText == "Withdrawal") {
        return TransactionType::Withdrawal;
    }

    if (typeText == "Transfer") {
        return TransactionType::Transfer;
    }

    if (typeText == "LoanReq") {
        return TransactionType::LoanReq;
    }

    return TransactionType::Unknown;
}

// Constructor incoming transaction data ko object fields me save karta hai.
Transaction::Transaction(TransactionType t, double amt, string dt, int from, int to) {
    type = t;
    amount = amt;
    dateTime = dt;
    fromAcc = from;
    toAcc = to;
}
