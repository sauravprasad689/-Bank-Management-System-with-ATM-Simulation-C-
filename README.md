# Bank Management System (C++)

## Overview

This project is a console-based Bank Management System implemented in C++ using Object-Oriented Programming principles. It simulates basic banking operations such as account creation, deposits, withdrawals, and transaction tracking. The system is modular, with separate classes handling accounts, transactions, and overall bank operations.

The goal of this project is to demonstrate strong fundamentals in C++, OOP design, and basic system architecture.

---

## Features

* Create new bank accounts
* Deposit money into an account
* Withdraw money from an account
* Transfer money between accounts
* Maintain transaction history
* Persistent data storage using file handling
* Role-based flow (Admin / Manager / Customer)

---

## Technologies Used

* Language: C++
* Concepts:

  * Object-Oriented Programming (Encapsulation, Abstraction)
  * File Handling
  * STL (Vectors)
  * Enums for transaction types
  * Modular code structure

---

## Project Structure

```
.
├── Account.h / Account.cpp       # Handles account details and operations
├── Transaction.h / Transaction.cpp # Stores transaction data
├── Bank.h / Bank.cpp             # Core logic of the system
├── ATM.h / ATM.cpp               # Interface layer for user interaction
├── Utils.h                       # Utility/helper functions
├── main.cpp                      # Entry point and program flow
```

---

## Key Concepts Used

### 1. Classes and Encapsulation

Each entity (Account, Transaction, Bank) is represented as a class with private data members and public methods.

### 2. Enum Usage

Transaction types are represented using enums:

```
enum TransactionType {
    DEPOSIT,
    WITHDRAW,
    TRANSFER
};
```

This improves readability and avoids using raw integers.

### 3. File Handling

Data is stored and retrieved from files to ensure persistence between program runs.

### 4. Modular Design

The system is divided into multiple files to improve maintainability and readability.

---

## How It Works

1. The program starts from `main.cpp`
2. User selects a role (Admin / Manager / Customer)
3. Based on the role:

   * Accounts are created or accessed
   * Transactions are performed
4. All operations are handled by the `Bank` class
5. Data is stored using file handling

---

## Example Flow

* Create Account
* Deposit Amount
* Withdraw Amount
* View Balance
* Transfer Funds

Each action generates a transaction record.

---

## How to Run

### Prerequisites

* C++ compiler (g++ recommended)

### Steps

1. Clone the repository:

```
git clone https://github.com/your-username/bank-management-system.git
```

2. Navigate to the project folder:

```
cd bank-management-system
```

3. Compile the code:

```
g++ main.cpp Account.cpp Transaction.cpp Bank.cpp ATM.cpp -o bank
```

4. Run the program:

```
./bank
```

---

## Future Improvements

* Add GUI interface
* Implement database (MySQL / SQLite)
* Improve authentication system
* Add multi-user concurrency support
* Enhance transaction security

---

## Author

Saurav Prasad

---

## Notes

This project is built for learning purposes and demonstrates core C++ and OOP concepts. It is not intended for production use.
