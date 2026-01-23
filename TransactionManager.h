#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H

#include "Account.h"
#include "Transaction.h"
#include <vector>
#include <map>
#include <string>

class TransactionManager {
private:
    std::vector<Transaction> transactions;
    std::map<std::string, Account> accounts;
    int transactionCounter;

public:
    TransactionManager();
    
    void addAccount(const Account& account);
    void removeAccount(const std::string& accountId);
    Account getAccount(const std::string& accountId) const;
    
    bool deposit(const std::string& accountId, double amount);
    bool withdraw(const std::string& accountId, double amount);
    bool transfer(const std::string& fromAccountId, const std::string& toAccountId, double amount);
    
    void recordTransaction(const Transaction& transaction);
    std::vector<Transaction> getTransactionHistory(const std::string& accountId) const;
    std::vector<Transaction> getAllTransactions() const;
    
    double getTotalDeposits(const std::string& accountId) const;
    double getTotalWithdrawals(const std::string& accountId) const;
    
    void displayAllAccounts() const;
    void displayTransactionHistory(const std::string& accountId) const;
    
    int getTotalAccounts() const;
    int getTotalTransactions() const;
};

#endif // TRANSACTIONMANAGER_H
