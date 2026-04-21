// Yeh file poore bank management system ka console flow chalati hai.
// Flow simple hai: main menu se Admin, Manager ya Customer role choose hota hai.
// Admin sensitive kaam karta hai, Manager monitoring karta hai, aur Customer apne account actions karta hai.

#include <iostream>
#include <fstream>
#include <limits>
#include <cstdio>
#include "Bank.h"
#include "ATM.h"
using namespace std;

// Yeh struct admin login ke username aur password ko ek saath hold karti hai.
struct AdminCredentials {
    string username;
    string password;
};

// Yeh constants default admin setup ko easy aur readable banate hain.
const string ADMIN_FILE_NAME = "admin.txt";
const string DEFAULT_ADMIN_USERNAME = "admin";
const string DEFAULT_ADMIN_PASSWORD = "1234";

// Yeh helper admin file ke liye bhi safe replace logic use karta hai.
static bool adminFileExists(const string& name) {
    ifstream file(name);
    bool exists = file.good();
    file.close();
    return exists;
}

// Temp file + backup flow se credentials save karne par purana data safe rehta hai.
static bool replaceAdminFileSafely(const string& targetFileName, const string& tempFileName) {
    string backupFileName = targetFileName + ".bak";

    if (adminFileExists(backupFileName)) {
        remove(backupFileName.c_str());
    }

    if (adminFileExists(targetFileName)) {
        if (rename(targetFileName.c_str(), backupFileName.c_str()) != 0) {
            cout << "Error creating backup for admin file!" << endl;
            remove(tempFileName.c_str());
            return false;
        }
    }

    if (rename(tempFileName.c_str(), targetFileName.c_str()) != 0) {
        cout << "Error replacing admin file!" << endl;

        if (adminFileExists(backupFileName)) {
            rename(backupFileName.c_str(), targetFileName.c_str());
        }

        remove(tempFileName.c_str());
        return false;
    }

    if (adminFileExists(backupFileName)) {
        remove(backupFileName.c_str());
    }

    return true;
}

// Admin credentials ko file me save karta hai taaki next run me reuse ho saken.
void saveAdminCredentials(const AdminCredentials& adminCredentials) {
    string tempFileName = ADMIN_FILE_NAME + ".tmp";
    ofstream file(tempFileName);

    if (!file.is_open()) {
        cout << "Error opening admin file for saving!" << endl;
        return;
    }

    // Credentials pehle temp file me save hote hain taaki original file safe rahe.
    file << adminCredentials.username << endl;
    file << adminCredentials.password << endl;

    if (!file) {
        cout << "Error writing admin credentials to file!" << endl;
        file.close();
        remove(tempFileName.c_str());
        return;
    }

    file.close();

    if (!file) {
        cout << "Error closing admin file after saving!" << endl;
        remove(tempFileName.c_str());
        return;
    }

    replaceAdminFileSafely(ADMIN_FILE_NAME, tempFileName);
}

// Program start par admin credentials load karta hai; missing file ho to default bana deta hai.
void loadAdminCredentials(AdminCredentials& adminCredentials) {
    ifstream file(ADMIN_FILE_NAME);

    if (!file.is_open()) {
        adminCredentials.username = DEFAULT_ADMIN_USERNAME;
        adminCredentials.password = DEFAULT_ADMIN_PASSWORD;
        saveAdminCredentials(adminCredentials);
        return;
    }

    getline(file, adminCredentials.username);
    getline(file, adminCredentials.password);

    // Read complete hone ke baad file close kar di jaati hai.
    file.close();

    // Agar file corrupt ya empty ho to system safe default par wapas aa jata hai.
    if (adminCredentials.username.empty() || adminCredentials.password.empty()) {
        adminCredentials.username = DEFAULT_ADMIN_USERNAME;
        adminCredentials.password = DEFAULT_ADMIN_PASSWORD;
        saveAdminCredentials(adminCredentials);
    }
}

// Admin ko username aur password update karne ka option deta hai.
void changeAdminCredentials(AdminCredentials& adminCredentials) {
    cout << "Enter New Username: ";
    cin >> adminCredentials.username;
    cout << "Enter New Password: ";
    cin >> adminCredentials.password;

    saveAdminCredentials(adminCredentials);
    cout << "Admin credentials updated successfully!" << endl;
}

// Reset ke baad admin login ko default credentials par le aata hai.
void resetAdminCredentials(AdminCredentials& adminCredentials) {
    adminCredentials.username = DEFAULT_ADMIN_USERNAME;
    adminCredentials.password = DEFAULT_ADMIN_PASSWORD;
    saveAdminCredentials(adminCredentials);
}

// Admin login file se loaded credentials ke against verify karta hai.
bool adminLogin(const AdminCredentials& adminCredentials) {
    string username, password;

    cout << "\n===== ADMIN LOGIN =====" << endl;
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    if (username == adminCredentials.username && password == adminCredentials.password) {
        cout << "Login Successful!" << endl;
        return true;
    }

    cout << "Invalid Username or Password!" << endl;
    return false;
}

// Admin menu sensitive operations ko grouped form me show karta hai.
void showAdminMenu(Bank& bank, AdminCredentials& adminCredentials) {
    int choice;
    int accNo;
    char confirm;

    while (true) {
        cout << "\n===== ADMIN MENU =====" << endl;
        cout << "1. View All Accounts" << endl;
        cout << "2. View All Transactions" << endl;
        cout << "3. Delete Account" << endl;
        cout << "4. Change Admin Credentials" << endl;
        cout << "5. Reset System" << endl;
        cout << "6. Back" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                bank.showAllAccounts();
                break;

            case 2:
                bank.showAllTransactions();
                break;

            case 3:
                cout << "Enter Account No to Delete: ";
                cin >> accNo;
                bank.deleteAccount(accNo);
                break;

            case 4:
                changeAdminCredentials(adminCredentials);
                break;

            case 5:
                // Reset dangerous action hai, isliye confirmation zaroor li ja rahi hai.
                cout << "Are you sure you want to reset the entire system? (y/n): ";
                cin >> confirm;

                if (confirm == 'y' || confirm == 'Y') {
                    bank.resetSystem();
                    resetAdminCredentials(adminCredentials);
                    cout << "Admin credentials reset to default." << endl;
                } else {
                    cout << "System reset cancelled." << endl;
                }
                break;

            case 6:
                return;

            default:
                cout << "Invalid Choice!" << endl;
        }
    }
}

// Manager menu monitoring aur account maintenance ke liye hai.
void showManagerMenu(Bank& bank) {
    int choice;
    int accNo;

    while (true) {
        cout << "\n===== MANAGER MENU =====" << endl;
        cout << "1. View All Accounts" << endl;
        cout << "2. View All Transactions" << endl;
        cout << "3. Delete Account" << endl;
        cout << "4. Back" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                bank.showAllAccounts();
                break;

            case 2:
                bank.showAllTransactions();
                break;

            case 3:
                cout << "Enter Account No to Delete: ";
                cin >> accNo;
                bank.deleteAccount(accNo);
                break;

            case 4:
                return;

            default:
                cout << "Invalid Choice!" << endl;
        }
    }
}

// Customer menu account-related daily operations ko handle karta hai.
void showCustomerMenu(Bank& bank, ATM& atm) {
    int customerAccNo;
    int choice;
    string name;
    double amount, balance;

    while (true) {
        cout << "\n===== CUSTOMER MENU =====" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Check Balance" << endl;
        cout << "5. View Own Transaction History" << endl;
        cout << "6. Back" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter New Account Number: ";
                cin >> customerAccNo;

                // getline se naam sahi read ho, isliye buffer clear kiya ja raha hai.
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter Holder Name: ";
                getline(cin, name);
                cout << "Enter Initial Balance: ";
                cin >> balance;
                bank.createAccount(customerAccNo, name, balance);
                bank.saveToFile();
                break;

            case 2:
                cout << "Enter Account Number: ";
                cin >> customerAccNo;
                cout << "Enter Deposit Amount: ";
                cin >> amount;
                bank.depositToAccount(customerAccNo, amount);
                break;

            case 3:
                cout << "Enter Account Number: ";
                cin >> customerAccNo;
                cout << "Enter Withdraw Amount: ";
                cin >> amount;
                bank.withdrawFromAccount(customerAccNo, amount);
                break;

            case 4:
                cout << "Enter Account Number: ";
                cin >> customerAccNo;
                if (auto acc = bank.getAccount(customerAccNo)) {
                    atm.checkBalance(*acc);
                }
                break;

            case 5:
                cout << "Enter Account Number: ";
                cin >> customerAccNo;
                bank.showTransactionHistory(customerAccNo);
                break;

            case 6:
                return;

            default:
                cout << "Invalid Choice!" << endl;
        }
    }
}

// Main function startup loading aur role-based navigation ko control karti hai.
int main() {
    Bank bank;
    ATM atm;
    AdminCredentials adminCredentials;
    int choice;

    // Start me purana saved data load hota hai taaki system resume ho sake.
    bank.loadFromFile();
    bank.loadTransactionsFromFile();
    loadAdminCredentials(adminCredentials);

    // Main menu user ko role choose karne deta hai: Admin, Manager ya Customer.
    while (true) {
        cout << "\n===== BANK MANAGEMENT SYSTEM =====" << endl;
        cout << "1. Admin Login" << endl;
        cout << "2. Manager Menu" << endl;
        cout << "3. Customer Menu" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (adminLogin(adminCredentials)) {
                    showAdminMenu(bank, adminCredentials);
                }
                break;

            case 2:
                showManagerMenu(bank);
                break;

            case 3:
                showCustomerMenu(bank, atm);
                break;

            case 4:
                cout << "Thank you for using our Bank Management System!" << endl;
                return 0;

            default:
                cout << "Invalid Choice!" << endl;
        }
    }

    return 0;
}
