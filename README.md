🏦 Bank Management System with ATM Simulation (C++)

A simple yet structured C++ console application that simulates how basic banking operations work through an ATM interface.

This project focuses on clean Object-Oriented Programming design, modular code organization, and modeling real-world banking logic in a beginner-friendly way.

No unnecessary complexity — just solid fundamentals and clean architecture.

✨ Project Idea

Ever wondered what happens behind the scenes when you use an ATM?

This project demonstrates a mini banking system simulation where users can:

Create bank accounts

Deposit money

Withdraw money

Check account balance

View all accounts in the system

Think of it as a tiny ATM sitting inside your terminal.

No card required. No bank queue. Just C++.

⚙️ Features

✔ Create new bank accounts
✔ Deposit money into an account
✔ Withdraw money with balance validation
✔ Check account balance
✔ Display all existing accounts
✔ Structured multi-file C++ project
✔ Clear separation of responsibilities using classes

Bonus: No hidden banking fees (unlike real banks 😄)

🧠 Concepts Demonstrated

This project focuses on applying core C++ and OOP principles in a practical scenario.

Language

C++ (C++17 compatible)

Programming Paradigm

Object-Oriented Programming (OOP)

Key Concepts Used

Classes and Objects

Encapsulation

Modular Design

Function Separation

Basic Error Handling

STL Vector for storing accounts

The goal was to simulate real-world logic while keeping the code readable and beginner-friendly.

🧩 Project Structure
Bank-Management-System
│
├── main.cpp
├── Bank.h / Bank.cpp
├── Account.h / Account.cpp
├── ATM.h / ATM.cpp
├── Transaction.h / Transaction.cpp
└── Utils.h
File Responsibilities

main.cpp
Entry point of the program. Displays the ATM menu and routes user actions.

Bank Class
Responsible for managing all accounts.
Handles account creation and searching.

Account Class
Represents a bank account with balance operations like deposit and withdrawal.

ATM Class
Acts as the interface between the user and the account operations.

Transaction Class
Prepared for future transaction tracking features.

Utils.h
Contains helper utilities such as date/time functions.

🔄 System Flow

The program follows a clear logical flow:

User Interaction
       ↓
ATM Menu (main.cpp)
       ↓
Bank System
       ↓
Account Operations
       ↓
Balance Updates

In simple words:

User → ATM → Bank → Account
▶️ How to Run

Compile using g++

g++ main.cpp Bank.cpp ATM.cpp Account.cpp -o bank_system

Run the program

./bank_system

If everything works correctly, you should see:

===== BANK ATM MENU =====
1. Create Account
2. Deposit Money
3. Withdraw Money
4. Check Balance
5. Show All Accounts
6. Exit

And yes — option 6 is still the safest banking decision.

🧪 Example Workflow

Create an account

Enter Account No: 101
Enter Holder Name: Saurav
Enter Initial Balance: 5000

Deposit money

Enter Account No: 101
Enter Deposit Amount: 1000

Withdraw money

Enter Withdraw Amount: 2000

The system automatically validates balances before allowing withdrawals.

🎯 Learning Outcomes

Building this project helps in understanding:

How real-world systems can be modeled in code

Structuring a multi-file C++ project

Designing classes with clear responsibilities

Managing data flow between program components

Writing maintainable and modular code

It’s a great beginner project for understanding OOP in C++.

🚀 Possible Future Improvements

Some features that could make this system more advanced:

PIN based authentication

Account deletion and modification

Money transfer between accounts

Transaction history

File-based persistent storage

GUI interface

Because every banking system deserves an upgrade eventually.

👨‍💻 Author

Saurav Prasad

Built as a learning project while exploring Object-Oriented Programming in C++ and practicing structured system design.

If you're reviewing this project — thanks for stopping by 🤝
