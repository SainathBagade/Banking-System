#ifndef FRAUDDETECTOR_H
#define FRAUDDETECTOR_H

#include "Transaction.h"
#include "Account.h"
#include <vector>
#include <string>
#include <map>

class FraudDetector {
private:
    static const double WITHDRAWAL_LIMIT;
    static const int TRANSACTION_LIMIT_PER_DAY;
    static const double DAILY_TRANSACTION_LIMIT;
    
    std::map<std::string, std::vector<Transaction>> accountTransactions;
    std::vector<std::string> suspiciousAccounts;

public:
    FraudDetector();
    
    bool isTransactionSuspicious(const Transaction& transaction, const Account& account);
    bool checkWithdrawalLimit(double amount);
    bool checkDailyTransactionCount(const std::string& accountId, const std::vector<Transaction>& transactions);
    bool checkUnusualBehavior(const Transaction& transaction, const std::vector<Transaction>& history);
    
    void flagSuspiciousAccount(const std::string& accountId);
    void unflagAccount(const std::string& accountId);
    bool isAccountSuspicious(const std::string& accountId) const;
    
    std::vector<std::string> getSuspiciousAccounts() const;
    
    void addTransactionRecord(const std::string& accountId, const Transaction& transaction);
    std::vector<Transaction> getAccountTransactionHistory(const std::string& accountId) const;
    
    void generateFraudReport() const;
};

#endif // FRAUDDETECTOR_H
