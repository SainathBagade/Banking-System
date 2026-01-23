#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <ctime>

class Transaction {
public:
    enum TransactionType {
        DEPOSIT,
        WITHDRAWAL,
        TRANSFER,
        INTEREST
    };

private:
    std::string transactionId;
    std::string accountId;
    TransactionType type;
    double amount;
    std::time_t timestamp;
    std::string description;
    bool successful;

public:
    Transaction();
    Transaction(const std::string& txnId, const std::string& accId, TransactionType txnType, 
                double amt, const std::string& desc);
    
    std::string getTransactionId() const;
    std::string getAccountId() const;
    TransactionType getType() const;
    double getAmount() const;
    std::time_t getTimestamp() const;
    std::string getDescription() const;
    bool isSuccessful() const;
    
    void setTransactionId(const std::string& id);
    void setAccountId(const std::string& id);
    void setType(TransactionType type);
    void setAmount(double amount);
    void setDescription(const std::string& desc);
    void setSuccessful(bool success);
    
    std::string getTypeString() const;
    void displayTransaction() const;
};

#endif // TRANSACTION_H
