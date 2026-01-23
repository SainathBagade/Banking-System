#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>

class Account {
private:
    std::string accountId;
    std::string accountHolder;
    double balance;
    std::string accountType;
    bool isActive;

public:
    Account();
    Account(const std::string& id, const std::string& holder, double initialBalance, const std::string& type);
    
    std::string getAccountId() const;
    std::string getAccountHolder() const;
    double getBalance() const;
    std::string getAccountType() const;
    bool getIsActive() const;
    
    void setAccountId(const std::string& id);
    void setAccountHolder(const std::string& holder);
    void setAccountType(const std::string& type);
    void setIsActive(bool active);
    
    bool deposit(double amount);
    bool withdraw(double amount);
    double getBalance();
    
    void displayAccountInfo() const;
};

#endif // ACCOUNT_H
