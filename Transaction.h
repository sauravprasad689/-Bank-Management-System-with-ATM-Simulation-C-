#ifndef TRANSACTION_H
#define TRANSACTION_H

// Yeh file transaction record ka structure define karti hai.
// Har deposit ya withdrawal ko simple data form me store kiya jata hai.

#include <string>
using namespace std;

// Enum se transaction type fixed values me safe tarike se store hota hai.
enum class TransactionType {
    Deposit,
    Withdrawal,
    Transfer,
    LoanReq,
    Unknown
};

// Helper function enum ko readable string me convert karta hai.
string transactionTypeToString(TransactionType type);

// Helper function saved string ko wapas enum me convert karta hai.
TransactionType stringToTransactionType(const string& typeText);

// Transaction class ek banking event ka record hold karti hai.
class Transaction {
public:
    TransactionType type;
    double amount;
    string dateTime;
    int fromAcc;
    int toAcc;

    // Constructor transaction ki saari important details store karta hai.
    Transaction(TransactionType t=TransactionType::Unknown, double amt=0, string dt="", int from=-1, int to=-1);
};

#endif
