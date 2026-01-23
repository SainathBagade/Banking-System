# Banking System

A simple C++ banking system simulation.

## Features
- **Account Management**: Create and manage bank accounts (Checking/Savings).
- **Transactions**: Perform deposits, withdrawals, and transfers between accounts.
- **Transaction History**: View detailed transaction logs for each account.
- **Statistics**: View total accounts, total transactions, and aggregate deposit/withdrawal amounts.
- **Fraud Detection**: Basic fraud detection capabilities (flagging suspicious accounts).

## Getting Started

### Prerequisites
- C++ Compiler (g++, clang++, or MSVC)

### Compilation
Compile the source files using your preferred compiler. For example:
```bash
g++ main.cpp Account.cpp TransactionManager.cpp -o BankingSystem
```

### Usage
Run the executable to see the banking system simulation in action:
```bash
./BankingSystem
```

## File Structure
- `main.cpp`: Entry point of the application, demonstrating usage.
- `Account.h/cpp`: Account class definition and implementation.
- `TransactionManager.h/cpp`: Manages accounts and transactions.
- `Transaction.h`: Transaction class definition.
- `FraudDetector.h`: Fraud detection module.
- `data.txt`: Data persistence (if implemented).
