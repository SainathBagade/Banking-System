#include "Account.h"
#include <iostream>
#include <iomanip>

Account::Account() : accountId(""), accountHolder(""), balance(0.0), accountType(""), isActive(false) {}

Account::Account(const std::string& id, const std::string& holder, double initialBalance, const std::string& type)
    : accountId(id), accountHolder(holder), balance(initialBalance), accountType(type), isActive(true) {}

std::string Account::getAccountId() const {
    return accountId;
}

std::string Account::getAccountHolder() const {
    return accountHolder;
}

double Account::getBalance() const {
    return balance;
}

std::string Account::getAccountType() const {
    return accountType;
}

bool Account::getIsActive() const {
    return isActive;
}

void Account::setAccountId(const std::string& id) {
    accountId = id;
}

void Account::setAccountHolder(const std::string& holder) {
    accountHolder = holder;
}

void Account::setAccountType(const std::string& type) {
    accountType = type;
}

void Account::setIsActive(bool active) {
    isActive = active;
}

bool Account::deposit(double amount) {
    if (!isActive) {
        std::cerr << "Account is not active." << std::endl;
        return false;
    }
    
    if (amount <= 0) {
        std::cerr << "Deposit amount must be positive." << std::endl;
        return false;
    }
    
    balance += amount;
    return true;
}

bool Account::withdraw(double amount) {
    if (!isActive) {
        std::cerr << "Account is not active." << std::endl;
        return false;
    }
    
    if (amount <= 0) {
        std::cerr << "Withdrawal amount must be positive." << std::endl;
        return false;
    }
    
    if (amount > balance) {
        std::cerr << "Insufficient funds. Current balance: $" << balance << std::endl;
        return false;
    }
    
    balance -= amount;
    return true;
}

void Account::displayAccountInfo() const {
    std::cout << "Account ID: " << accountId << std::endl;
    std::cout << "Holder: " << accountHolder << std::endl;
    std::cout << "Type: " << accountType << std::endl;
    std::cout << "Balance: $" << std::fixed << std::setprecision(2) << balance << std::endl;
    std::cout << "Status: " << (isActive ? "Active" : "Inactive") << std::endl;
}
