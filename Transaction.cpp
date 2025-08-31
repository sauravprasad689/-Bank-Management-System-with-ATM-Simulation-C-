#include "Transaction.h"

Transaction::Transaction(string t, double amt, string dt, int from, int to) {
    type = t;
    amount = amt;
    dateTime = dt;
    fromAcc = from;
    toAcc = to;
}
