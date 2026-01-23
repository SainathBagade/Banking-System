#include "FraudDetector.h"
#include <iostream>
#include <ctime>
#include <algorithm>

const double FraudDetector::WITHDRAWAL_LIMIT = 5000.0;
const int FraudDetector::TRANSACTION_LIMIT_PER_DAY = 10;
const double FraudDetector::DAILY_TRANSACTION_LIMIT = 50000.0;

FraudDetector::FraudDetector() {}

bool FraudDetector::isTransactionSuspicious(const Transaction& transaction, const Account& account) {
    // Check withdrawal limit
    if (transaction.getType() == Transaction::WITHDRAWAL) {
        if (!checkWithdrawalLimit(transaction.getAmount())) {
            return true;
        }
    }
    
    // Check unusual behavior
    auto& history = accountTransactions[account.getAccountId()];
    if (checkUnusualBehavior(transaction, history)) {
        return true;
    }
    
    // Check daily transaction count
    if (!checkDailyTransactionCount(account.getAccountId(), history)) {
        return true;
    }
    
    return false;
}

bool FraudDetector::checkWithdrawalLimit(double amount) {
    return amount <= WITHDRAWAL_LIMIT;
}

bool FraudDetector::checkDailyTransactionCount(const std::string& accountId, const std::vector<Transaction>& transactions) {
    std::time_t now = std::time(nullptr);
    std::time_t oneDayAgo = now - (24 * 60 * 60);
    
    int transactionCount = 0;
    double dailyAmount = 0.0;
    
    for (const auto& txn : transactions) {
        if (txn.getAccountId() == accountId && txn.getTimestamp() > oneDayAgo) {
            transactionCount++;
            dailyAmount += txn.getAmount();
        }
    }
    
    return (transactionCount <= TRANSACTION_LIMIT_PER_DAY) && (dailyAmount <= DAILY_TRANSACTION_LIMIT);
}

bool FraudDetector::checkUnusualBehavior(const Transaction& transaction, const std::vector<Transaction>& history) {
    if (history.empty()) {
        return false;
    }
    
    // Check for rapid transactions
    if (history.size() > 0) {
        std::time_t lastTxnTime = history.back().getTimestamp();
        std::time_t currentTime = std::time(nullptr);
        
        if ((currentTime - lastTxnTime) < 60) { // Less than 1 minute
            return true;
        }
    }
    
    return false;
}

void FraudDetector::flagSuspiciousAccount(const std::string& accountId) {
    if (std::find(suspiciousAccounts.begin(), suspiciousAccounts.end(), accountId) == suspiciousAccounts.end()) {
        suspiciousAccounts.push_back(accountId);
        std::cout << "Account " << accountId << " flagged as suspicious." << std::endl;
    }
}

void FraudDetector::unflagAccount(const std::string& accountId) {
    auto it = std::find(suspiciousAccounts.begin(), suspiciousAccounts.end(), accountId);
    if (it != suspiciousAccounts.end()) {
        suspiciousAccounts.erase(it);
        std::cout << "Account " << accountId << " unflagged." << std::endl;
    }
}

bool FraudDetector::isAccountSuspicious(const std::string& accountId) const {
    return std::find(suspiciousAccounts.begin(), suspiciousAccounts.end(), accountId) != suspiciousAccounts.end();
}

std::vector<std::string> FraudDetector::getSuspiciousAccounts() const {
    return suspiciousAccounts;
}

void FraudDetector::addTransactionRecord(const std::string& accountId, const Transaction& transaction) {
    accountTransactions[accountId].push_back(transaction);
}

std::vector<Transaction> FraudDetector::getAccountTransactionHistory(const std::string& accountId) const {
    auto it = accountTransactions.find(accountId);
    if (it != accountTransactions.end()) {
        return it->second;
    }
    return {};
}

void FraudDetector::generateFraudReport() const {
    std::cout << "=== Fraud Detection Report ===" << std::endl;
    std::cout << "Total Suspicious Accounts: " << suspiciousAccounts.size() << std::endl;
    
    if (!suspiciousAccounts.empty()) {
        std::cout << "Flagged Accounts: ";
        for (const auto& accountId : suspiciousAccounts) {
            std::cout << accountId << " ";
        }
        std::cout << std::endl;
    }
}
