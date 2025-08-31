#include <iostream>
#include "Bank.h"
#include "ATM.h"
using namespace std;


// PASTE THIS COMMAND IN TERMIANAL TO RUN IT -> 

// cd "e:\projects(resume)\BANK MANAGEMENT SYSTEM\"
// g++ main.cpp Bank.cpp ATM.cpp Account.cpp -o main
// .\main








int main() {
    Bank bank;
    ATM atm;

    int choice;
    while (true) {
        cout << "\n===== BANK ATM MENU =====" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Check Balance" << endl;
        cout << "5. Show All Accounts" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 6) break;

        int accNo;
        string name;
        double amount, balance;

        switch (choice) {
            case 1:
                cout << "Enter Account No: ";
                cin >> accNo;
                cout << "Enter Holder Name: ";
                cin >> name;
                cout << "Enter Initial Balance: ";
                cin >> balance;
                bank.createAccount(accNo, name, balance);
                break;

            case 2:
                cout << "Enter Account No: ";
                cin >> accNo;
                cout << "Enter Deposit Amount: ";
                cin >> amount;
                if (auto acc = bank.getAccount(accNo)) {
                    atm.depositMoney(*acc, amount);
                }
                break;

            case 3:
                cout << "Enter Account No: ";
                cin >> accNo;
                cout << "Enter Withdraw Amount: ";
                cin >> amount;
                if (auto acc = bank.getAccount(accNo)) {
                    atm.withdrawMoney(*acc, amount);
                }
                break;

            case 4:
                cout << "Enter Account No: ";
                cin >> accNo;
                if (auto acc = bank.getAccount(accNo)) {
                    atm.checkBalance(*acc);
                }
                break;

            case 5:
                bank.showAllAccounts();
                break;

            default:
                cout << "Invalid Choice!" << endl;
        }
    }

    cout << "Thank you for using our Bank ATM System!" << endl;
    return 0;
}
