#include "Transaction.h"
#include <iostream>
#include <iomanip>
#include <ctime>

Transaction::Transaction() 
    : transactionId(""), accountId(""), type(DEPOSIT), amount(0.0), description(""), successful(false) {
    timestamp = std::time(nullptr);
}

Transaction::Transaction(const std::string& txnId, const std::string& accId, TransactionType txnType, 
                         double amt, const std::string& desc)
    : transactionId(txnId), accountId(accId), type(txnType), amount(amt), description(desc), successful(true) {
    timestamp = std::time(nullptr);
}

std::string Transaction::getTransactionId() const {
    return transactionId;
}

std::string Transaction::getAccountId() const {
    return accountId;
}

Transaction::TransactionType Transaction::getType() const {
    return type;
}

double Transaction::getAmount() const {
    return amount;
}

std::time_t Transaction::getTimestamp() const {
    return timestamp;
}

std::string Transaction::getDescription() const {
    return description;
}

bool Transaction::isSuccessful() const {
    return successful;
}

void Transaction::setTransactionId(const std::string& id) {
    transactionId = id;
}

void Transaction::setAccountId(const std::string& id) {
    accountId = id;
}

void Transaction::setType(TransactionType txnType) {
    type = txnType;
}

void Transaction::setAmount(double amt) {
    amount = amt;
}

void Transaction::setDescription(const std::string& desc) {
    description = desc;
}

void Transaction::setSuccessful(bool success) {
    successful = success;
}

std::string Transaction::getTypeString() const {
    switch (type) {
        case DEPOSIT:
            return "Deposit";
        case WITHDRAWAL:
            return "Withdrawal";
        case TRANSFER:
            return "Transfer";
        case INTEREST:
            return "Interest";
        default:
            return "Unknown";
    }
}

void Transaction::displayTransaction() const {
    std::cout << "Transaction ID: " << transactionId << std::endl;
    std::cout << "Account ID: " << accountId << std::endl;
    std::cout << "Type: " << getTypeString() << std::endl;
    std::cout << "Amount: $" << std::fixed << std::setprecision(2) << amount << std::endl;
    std::cout << "Timestamp: " << std::ctime(&timestamp);
    std::cout << "Description: " << description << std::endl;
    std::cout << "Status: " << (successful ? "Successful" : "Failed") << std::endl;
}
