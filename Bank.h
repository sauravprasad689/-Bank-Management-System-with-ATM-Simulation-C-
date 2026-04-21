#ifndef BANK_H
#define BANK_H

// Yeh file Bank class ko define karti hai jo poore system ka main data store hai.
// Accounts, transactions aur file persistence ka control isi class ke paas hai.

#include "Account.h"
#include "Transaction.h"
#include <vector>
#include <string>

// Bank class system ke central operations ko manage karti hai.
class Bank {
private:
    vector<Account> accounts;
    vector<Transaction> transactions;
    string fileName = "accounts.txt";
    string transactionFileName = "transactions.txt";

public:
    // Naya account bank ke accounts list me add karta hai.
    void createAccount(int accNo, string name, double balance);
    // Account delete karta hai aur usse related transactions bhi hata deta hai.
    void deleteAccount(int accNo);
    // Account number ke basis par required account dhoondta hai.
    Account* getAccount(int accNo);
    // Bank ke saare accounts admin ya manager ko dikhata hai.
    void showAllAccounts();
    // Bank ke saare transaction records list karta hai.
    void showAllTransactions();
    // Deposit karne ke saath transaction history bhi update karta hai.
    void depositToAccount(int accNo, double amount);
    // Withdraw karne ke saath transaction history bhi update karta hai.
    void withdrawFromAccount(int accNo, double amount);
    // Pura system data clear karta hai for admin reset.
    void resetSystem();
    // Accounts ko text file me save karta hai taaki data persist rahe.
    void saveToFile();
    // Program start par accounts file se data load karta hai.
    void loadFromFile();
    // Transactions ko alag file me store karta hai.
    void saveTransactionsToFile();
    // Saved transaction history ko memory me load karta hai.
    void loadTransactionsFromFile();
    // Kisi ek account ki transaction history dikhata hai.
    void showTransactionHistory(int accNo);
    // Yeh purane placeholders hain; abhi current flow main.cpp handle karta hai.
     void adminMenu();
    void adminPanel();
    void loginAdmin();
    void run();
};

#endif
