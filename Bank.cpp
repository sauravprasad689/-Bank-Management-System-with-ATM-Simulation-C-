// Yeh file Bank class ka core logic implement karti hai.
// Yahan account management, transaction tracking aur file persistence sambhala jata hai.

#include "Bank.h"
#include "Utils.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
using namespace std;

// Yeh helper check karta hai ki target file pehle se exist karti hai ya nahi.
static bool fileExists(const string& name) {
    ifstream file(name);
    bool exists = file.good();
    file.close();
    return exists;
}

// Yeh helper temp file ko safe tarike se original file se replace karta hai.
// Isse direct overwrite ki jagah backup flow use hota hai aur data loss ka chance kam hota hai.
static bool replaceFileSafely(const string& targetFileName, const string& tempFileName) {
    string backupFileName = targetFileName + ".bak";

    // Purana backup ho to pehle hata dete hain taaki rename clean ho.
    if (fileExists(backupFileName)) {
        remove(backupFileName.c_str());
    }

    // Existing file ko backup naam par move karte hain.
    if (fileExists(targetFileName)) {
        if (rename(targetFileName.c_str(), backupFileName.c_str()) != 0) {
            cout << "Error creating backup for file: " << targetFileName << endl;
            remove(tempFileName.c_str());
            return false;
        }
    }

    // Temp file successfully likhne ke baad hi usse original naam dete hain.
    if (rename(tempFileName.c_str(), targetFileName.c_str()) != 0) {
        cout << "Error replacing original file: " << targetFileName << endl;

        // Agar replace fail ho jaye to backup ko wapas restore karne ki koshish karte hain.
        if (fileExists(backupFileName)) {
            rename(backupFileName.c_str(), targetFileName.c_str());
        }

        remove(tempFileName.c_str());
        return false;
    }

    // Successful replace ke baad backup file ki zaroorat nahi rehti.
    if (fileExists(backupFileName)) {
        remove(backupFileName.c_str());
    }

    return true;
}

// Naya account bank ki in-memory list me add karta hai.
void Bank::createAccount(int accNo, string name, double balance) {
    // Duplicate account number allow nahi hai.
    for (const auto& acc : accounts) {
        if (acc.getAccountNumber() == accNo) {
            cout << "Account Number Already Exists! Please use a different account number." << endl;
            return;
        }
    }

    accounts.push_back(Account(accNo, name, balance));
    cout << "Account Created Successfully!" << endl;
}

// Account delete karta hai aur related transaction history bhi clean karta hai.
void Bank::deleteAccount(int accNo) {
    bool accountFound = false;

    // Pehle matching account vector se remove kiya jata hai.
    for (auto it = accounts.begin(); it != accounts.end(); ++it) {
        if (it->getAccountNumber() == accNo) {
            accounts.erase(it);
            accountFound = true;
            break;
        }
    }

    if (!accountFound) {
        cout << "Account Not Found! Delete Failed." << endl;
        return;
    }

    // Deleted account ke saare transaction records bhi hata dete hain.
    for (auto it = transactions.begin(); it != transactions.end();) {
        if (it->fromAcc == accNo || it->toAcc == accNo) {
            it = transactions.erase(it);
        } else {
            ++it;
        }
    }

    saveToFile();
    saveTransactionsToFile();
    cout << "Account Deleted Successfully!" << endl;
}

// Account number ke basis par object ka address return karta hai.
Account* Bank::getAccount(int accNo) {
    for (auto &acc : accounts) {
        if (acc.getAccountNumber() == accNo) {
            return &acc;
        }
    }
    cout << "Account Not Found!" << endl;
    return nullptr;
}

// Sabhi accounts ko list form me show karta hai.
void Bank::showAllAccounts() {
    if (accounts.empty()) {
        cout << "No accounts found!" << endl;
        return;
    }

    for (auto &acc : accounts) {
        acc.display();
    }
}

// Sabhi transactions ko admin ya manager ke liye show karta hai.
void Bank::showAllTransactions() {
    if (transactions.empty()) {
        cout << "No transactions found!" << endl;
        return;
    }

    for (const auto& transaction : transactions) {
        cout << "Type: " << transactionTypeToString(transaction.type)
             << " | Amount: " << transaction.amount
             << " | Date: " << transaction.dateTime
             << " | Account No: " << transaction.fromAcc << endl;
    }
}

// Deposit ke baad transaction record aur files dono update hoti hain.
void Bank::depositToAccount(int accNo, double amount) {
    Account* acc = getAccount(accNo);

    if (acc == nullptr) {
        return;
    }

    // Invalid amount par transaction history create nahi honi chahiye.
    if (amount <= 0) {
        cout << "Invalid Deposit Amount! Please enter a positive amount." << endl;
        return;
    }

    acc->deposit(amount);
    // Har successful deposit ka history record banaya jata hai.
    transactions.push_back(Transaction(TransactionType::Deposit, amount, nowDateTime(), accNo, -1));
    saveToFile();
    saveTransactionsToFile();
}

// Withdraw ke baad sirf successful case me transaction save hota hai.
void Bank::withdrawFromAccount(int accNo, double amount) {
    Account* acc = getAccount(accNo);

    if (acc == nullptr) {
        return;
    }

    // Invalid amount par withdraw attempt aur history save nahi honi chahiye.
    if (amount <= 0) {
        cout << "Invalid Withdrawal Amount! Please enter a positive amount." << endl;
        return;
    }

    if (acc->withdraw(amount)) {
        // Date-time save karke baad me history trace karna easy hota hai.
        transactions.push_back(Transaction(TransactionType::Withdrawal, amount, nowDateTime(), accNo, -1));
        saveToFile();
        saveTransactionsToFile();
    }
}

// Reset poori working memory clear karta hai aur empty files likh deta hai.
void Bank::resetSystem() {
    accounts.clear();
    transactions.clear();
    saveToFile();
    saveTransactionsToFile();
    cout << "System data reset successfully!" << endl;
}

// Accounts ko simple text file format me save karta hai.
void Bank::saveToFile() {
    string tempFileName = fileName + ".tmp";
    ofstream file(tempFileName);

    // File open fail ho to user ko error dikhaya jata hai.
    if (!file.is_open()) {
        cout << "Error opening file for saving!" << endl;
        return;
    }

    // Pehle temp file me data likhte hain taaki original file turant affect na ho.
    for (const auto& acc : accounts) {
        file << acc.getAccountNumber() << "|"
             << acc.getHolderName() << "|"
             << acc.getBalance() << endl;
    }

    // Write fail ho to temp file delete karke save stop kar dete hain.
    if (!file) {
        cout << "Error writing account data to file!" << endl;
        file.close();
        remove(tempFileName.c_str());
        return;
    }

    // Rename se pehle stream close karna zaroori hai.
    file.close();

    if (!file) {
        cout << "Error closing account file after saving!" << endl;
        remove(tempFileName.c_str());
        return;
    }

    replaceFileSafely(fileName, tempFileName);
}

// Saved accounts ko program start par memory me wapas load karta hai.
void Bank::loadFromFile() {
    ifstream file(fileName);

    // Agar file abhi tak nahi bani to silently skip kar dete hain.
    if (!file.is_open()) {
        return;
    }

    accounts.clear();
    string line;

    // Har line ko parse karke ek Account object banaya jata hai.
    while (getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        stringstream ss(line);
        string accNoText, name, balanceText;

        getline(ss, accNoText, '|');
        getline(ss, name, '|');
        getline(ss, balanceText);

        if (!accNoText.empty() && !name.empty() && !balanceText.empty()) {
            accounts.push_back(Account(stoi(accNoText), name, stod(balanceText)));
        }
    }

    // Read complete hone ke baad file ko cleanly close kar dete hain.
    file.close();
}

// Transactions ko alag text file me store karta hai.
void Bank::saveTransactionsToFile() {
    string tempFileName = transactionFileName + ".tmp";
    ofstream file(tempFileName);

    if (!file.is_open()) {
        cout << "Error opening transaction file for saving!" << endl;
        return;
    }

    // Same file format rakhte hue pehle temp file me transaction data likha ja raha hai.
    for (const auto& transaction : transactions) {
        file << transactionTypeToString(transaction.type) << "|"
             << transaction.amount << "|"
             << transaction.dateTime << "|"
             << transaction.fromAcc << endl;
    }

    if (!file) {
        cout << "Error writing transaction data to file!" << endl;
        file.close();
        remove(tempFileName.c_str());
        return;
    }

    file.close();

    if (!file) {
        cout << "Error closing transaction file after saving!" << endl;
        remove(tempFileName.c_str());
        return;
    }

    replaceFileSafely(transactionFileName, tempFileName);
}

// Transaction history file se records load karke vector me store karta hai.
void Bank::loadTransactionsFromFile() {
    ifstream file(transactionFileName);

    if (!file.is_open()) {
        return;
    }

    transactions.clear();
    string line;

    // Pipe-separated values ko todkar Transaction objects ban rahe hain.
    while (getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        stringstream ss(line);
        string type, amountText, dateTime, fromAccText;

        getline(ss, type, '|');
        getline(ss, amountText, '|');
        getline(ss, dateTime, '|');
        getline(ss, fromAccText);

        if (!type.empty() && !amountText.empty() && !dateTime.empty() && !fromAccText.empty()) {
            transactions.push_back(Transaction(stringToTransactionType(type), stod(amountText), dateTime, stoi(fromAccText), -1));
        }
    }

    file.close();
}

// Yeh function ek specific account ki history filter karke dikhata hai.
void Bank::showTransactionHistory(int accNo) {
    bool found = false;

    for (const auto& transaction : transactions) {
        if (transaction.fromAcc == accNo) {
            cout << "Type: " << transactionTypeToString(transaction.type)
                 << " | Amount: " << transaction.amount
                 << " | Date: " << transaction.dateTime
                 << " | Account No: " << transaction.fromAcc << endl;
            found = true;
        }
    }

    // Agar koi match na mile to clear message diya jata hai.
    if (!found) {
        cout << "No transactions found for this account!" << endl;
    }
}
