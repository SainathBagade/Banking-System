#include "TransactionManager.h"
#include <iostream>
#include <sstream>
#include <iomanip>

TransactionManager::TransactionManager() : transactionCounter(1000) {}

void TransactionManager::addAccount(const Account& account) {
    accounts[account.getAccountId()] = account;
    std::cout << "Account " << account.getAccountId() << " added successfully." << std::endl;
}

void TransactionManager::removeAccount(const std::string& accountId) {
    auto it = accounts.find(accountId);
    if (it != accounts.end()) {
        accounts.erase(it);
        std::cout << "Account " << accountId << " removed successfully." << std::endl;
    } else {
        std::cerr << "Account " << accountId << " not found." << std::endl;
    }
}

Account TransactionManager::getAccount(const std::string& accountId) const {
    auto it = accounts.find(accountId);
    if (it != accounts.end()) {
        return it->second;
    }
    return Account();
}

bool TransactionManager::deposit(const std::string& accountId, double amount) {
    auto it = accounts.find(accountId);
    if (it != accounts.end()) {
        if (it->second.deposit(amount)) {
            std::string txnId = "TXN" + std::to_string(transactionCounter++);
            Transaction txn(txnId, accountId, Transaction::DEPOSIT, amount, "Deposit");
            recordTransaction(txn);
            return true;
        }
    } else {
        std::cerr << "Account " << accountId << " not found." << std::endl;
    }
    return false;
}

bool TransactionManager::withdraw(const std::string& accountId, double amount) {
    auto it = accounts.find(accountId);
    if (it != accounts.end()) {
        if (it->second.withdraw(amount)) {
            std::string txnId = "TXN" + std::to_string(transactionCounter++);
            Transaction txn(txnId, accountId, Transaction::WITHDRAWAL, amount, "Withdrawal");
            recordTransaction(txn);
            return true;
        }
    } else {
        std::cerr << "Account " << accountId << " not found." << std::endl;
    }
    return false;
}

bool TransactionManager::transfer(const std::string& fromAccountId, const std::string& toAccountId, double amount) {
    auto fromIt = accounts.find(fromAccountId);
    auto toIt = accounts.find(toAccountId);
    
    if (fromIt == accounts.end() || toIt == accounts.end()) {
        std::cerr << "One or both accounts not found." << std::endl;
        return false;
    }
    
    if (fromIt->second.withdraw(amount)) {
        toIt->second.deposit(amount);
        
        std::string txnId1 = "TXN" + std::to_string(transactionCounter++);
        Transaction txn1(txnId1, fromAccountId, Transaction::TRANSFER, amount, "Transfer to " + toAccountId);
        recordTransaction(txn1);
        
        std::string txnId2 = "TXN" + std::to_string(transactionCounter++);
        Transaction txn2(txnId2, toAccountId, Transaction::TRANSFER, amount, "Transfer from " + fromAccountId);
        recordTransaction(txn2);
        
        return true;
    }
    return false;
}

void TransactionManager::recordTransaction(const Transaction& transaction) {
    transactions.push_back(transaction);
}

std::vector<Transaction> TransactionManager::getTransactionHistory(const std::string& accountId) const {
    std::vector<Transaction> history;
    for (const auto& txn : transactions) {
        if (txn.getAccountId() == accountId) {
            history.push_back(txn);
        }
    }
    return history;
}

std::vector<Transaction> TransactionManager::getAllTransactions() const {
    return transactions;
}

double TransactionManager::getTotalDeposits(const std::string& accountId) const {
    double total = 0.0;
    for (const auto& txn : transactions) {
        if (txn.getAccountId() == accountId && txn.getType() == Transaction::DEPOSIT) {
            total += txn.getAmount();
        }
    }
    return total;
}

double TransactionManager::getTotalWithdrawals(const std::string& accountId) const {
    double total = 0.0;
    for (const auto& txn : transactions) {
        if (txn.getAccountId() == accountId && txn.getType() == Transaction::WITHDRAWAL) {
            total += txn.getAmount();
        }
    }
    return total;
}

void TransactionManager::displayAllAccounts() const {
    std::cout << "=== All Accounts ===" << std::endl;
    for (const auto& pair : accounts) {
        pair.second.displayAccountInfo();
        std::cout << "---" << std::endl;
    }
}

void TransactionManager::displayTransactionHistory(const std::string& accountId) const {
    std::cout << "=== Transaction History for Account " << accountId << " ===" << std::endl;
    auto history = getTransactionHistory(accountId);
    for (const auto& txn : history) {
        std::cout << txn.getTypeString() << ": $" << std::fixed << std::setprecision(2) 
                  << txn.getAmount() << std::endl;
    }
}

int TransactionManager::getTotalAccounts() const {
    return accounts.size();
}

int TransactionManager::getTotalTransactions() const {
    return transactions.size();
}
