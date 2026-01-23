#include <iostream>
#include "Account.h"
#include "Transaction.h"
#include "TransactionManager.h"
#include "FraudDetector.h"

int main() {
    TransactionManager manager;
    FraudDetector detector;
    
    std::cout << "=== Banking System ===" << std::endl << std::endl;
    
    // Create accounts
    Account acc1("ACC001", "John Doe", 5000.0, "Checking");
    Account acc2("ACC002", "Jane Smith", 10000.0, "Savings");
    Account acc3("ACC003", "Bob Johnson", 2500.0, "Checking");
    
    // Add accounts to manager
    manager.addAccount(acc1);
    manager.addAccount(acc2);
    manager.addAccount(acc3);
    
    std::cout << std::endl;
    
    // Display all accounts
    manager.displayAllAccounts();
    
    std::cout << std::endl;
    
    // Perform transactions
    std::cout << "=== Performing Transactions ===" << std::endl;
    
    // Deposit
    manager.deposit("ACC001", 1000.0);
    std::cout << "Deposited $1000 to ACC001" << std::endl;
    
    // Withdrawal
    manager.withdraw("ACC002", 500.0);
    std::cout << "Withdrew $500 from ACC002" << std::endl;
    
    // Transfer
    manager.transfer("ACC001", "ACC003", 2000.0);
    std::cout << "Transferred $2000 from ACC001 to ACC003" << std::endl;
    
    std::cout << std::endl;
    
    // Display updated accounts
    std::cout << "=== Updated Account Information ===" << std::endl;
    manager.displayAllAccounts();
    
    std::cout << std::endl;
    
    // Display transaction history
    std::cout << "=== Transaction History ===" << std::endl;
    manager.displayTransactionHistory("ACC001");
    
    std::cout << std::endl;
    
    // Display statistics
    std::cout << "=== Banking Statistics ===" << std::endl;
    std::cout << "Total Accounts: " << manager.getTotalAccounts() << std::endl;
    std::cout << "Total Transactions: " << manager.getTotalTransactions() << std::endl;
    std::cout << "ACC001 Total Deposits: $" << std::fixed << std::setprecision(2) 
              << manager.getTotalDeposits("ACC001") << std::endl;
    std::cout << "ACC001 Total Withdrawals: $" << std::fixed << std::setprecision(2) 
              << manager.getTotalWithdrawals("ACC001") << std::endl;
    
    std::cout << std::endl;
    
    // Fraud detection
    std::cout << "=== Fraud Detection ===" << std::endl;
    detector.flagSuspiciousAccount("ACC001");
    detector.generateFraudReport();
    
    return 0;
}
