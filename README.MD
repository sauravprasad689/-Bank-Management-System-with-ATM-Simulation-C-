🏦 Bank Management System with ATM Simulation (C++)

A clean and beginner-friendly C++ console project that simulates how a basic bank and ATM system works.

This project focuses on solid Object-Oriented Programming (OOP) principles and structured multi-file C++ development.

No over-engineering.
No unnecessary frameworks.

Just good old C++ doing useful things.

✨ Project Overview

Imagine a tiny ATM running inside your terminal.

This program allows users to perform common banking operations such as creating accounts, depositing money, withdrawing funds, and checking balances.

Think of it as a mini banking system — minus the long queues and paperwork.

⚙️ Features

• Create new bank accounts
• Deposit money into an account
• Withdraw money with balance validation
• Check account balance
• Display all accounts in the system
• Modular multi-file C++ project structure
• Clear separation of responsibilities using classes

Bonus feature:
• No hidden bank charges (your terminal is very generous 😄)

🧠 Concepts Demonstrated

This project was built to practice core C++ programming and OOP fundamentals.

Language

• C++ (C++17 compatible)

Programming Paradigm

• Object-Oriented Programming (OOP)

Concepts Used

• Classes and Objects
• Encapsulation
• Modular Code Design
• Function Separation
• Basic Input Validation
• STL vector for storing accounts

The goal was simple:
write readable code that models real-world logic.

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

• Entry point of the program
• Displays the ATM menu
• Handles user input

Bank Class

• Stores and manages all accounts
• Creates and searches accounts

Account Class

• Represents individual bank accounts
• Handles deposit, withdrawal, and display operations

ATM Class

• Acts as the interface between user actions and account operations

Transaction Class

• Designed for future transaction tracking features

Utils.h

• Utility helper functions (like date/time generation)

🔄 System Flow

The system follows a simple logical flow.

User Interaction
      ↓
ATM Menu (main.cpp)
      ↓
Bank System
      ↓
Account Operations
      ↓
Balance Updates

Or in even simpler terms:

User → ATM → Bank → Account
▶️ How to Run

Compile the project using g++

g++ main.cpp Bank.cpp ATM.cpp Account.cpp -o bank_system

Run the program

./bank_system

You should see something like this:

===== BANK ATM MENU =====
1. Create Account
2. Deposit Money
3. Withdraw Money
4. Check Balance
5. Show All Accounts
6. Exit

Pro tip:
Option 6 is still the safest financial decision.

🧪 Example Usage

Create an account

Enter Account No: 101
Enter Holder Name: Saurav
Enter Initial Balance: 5000

Deposit money

Enter Account No: 101
Enter Deposit Amount: 1000

Withdraw money

Enter Withdraw Amount: 2000

The system automatically checks whether enough balance is available before allowing withdrawals.

(Your ATM is polite but strict.)

🎯 Learning Outcomes

Working on this project helps in understanding:

• How real-world systems can be modeled using code
• How to structure a multi-file C++ project
• How different classes interact in a program
• How to design modular and maintainable code
• How user input flows through a system

It’s a great beginner project for practicing OOP with practical logic.

🚀 Possible Future Improvements

If this project were expanded further, the following features could be added:

• PIN-based authentication
• Account deletion and modification
• Money transfer between accounts
• Transaction history tracking
• File-based persistent storage
• Graphical interface (GUI)

Because every banking system eventually needs version 2.0.

👨‍💻 Author

Saurav Prasad

Built while learning and experimenting with Object-Oriented Programming in C++ and system design fundamentals.

If you’re reviewing this project —
thanks for stopping by 🤝