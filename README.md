🏦 Bank Management System with ATM Simulation

A clean, beginner-friendly C++ project that simulates how a real bank and ATM work — built with OOP principles, structured code, and persistent storage.

✨ Why this project?

Because banking systems are everywhere — and this project shows how real-world logic can be modeled using Object-Oriented Programming in C++.
No fancy buzzwords, just solid fundamentals done right.

🔍 What it does (in simple terms)

Admin can create, modify, delete, and manage accounts

Customers can log in like an ATM

Supports deposit, withdrawal, transfer, balance check

Keeps transaction history

Saves data permanently using files (even after program closes)

Basically: mini bank, real logic.

🧠 Core Concepts Used (Technical)

Language: C++ (C++17)

Programming Paradigm: Object-Oriented Programming (OOP)

Key OOP Principles:

Encapsulation

Abstraction

Modular Design

Data Structures: vector

File Handling: Persistent storage using .dat files

Environment: VS Code / g++ (Windows)

🧩 Project Structure
BankManagementSystem/
│
├── main.cpp              # Entry point & main menu
├── Account.h / .cpp      # Account data & operations
├── Transaction.h / .cpp  # Transaction records
├── Bank.h / .cpp         # Admin-side logic
├── ATM.h / .cpp          # Customer-side (ATM) logic
├── accounts.dat          # Stored account data
└── transactions.dat      # Stored transaction history

🔄 How the system works (high-level)

Program starts → existing data loads from files

User selects Admin or Customer

Actions update data in memory

Every important change is saved to files

On restart → data is restored automatically

Just like how real banks maintain records.

▶️ How to Run
g++ -std=gnu++17 *.cpp -o bank_system
./bank_system

🧪 Example Features

Secure login using Account Number + PIN

Balance validation before withdrawal/transfer

Separate roles for Admin vs Customer

Transaction logs for transparency

🚀 Learning Outcomes

Understand how real systems are structured

Apply OOP concepts in a practical project

Learn data flow from user → memory → file

Gain confidence in multi-file C++ projects




Built with consistency, debugging, and a lot of learning.
If you’re reviewing this — thanks for stopping by SAURAV 🤝
