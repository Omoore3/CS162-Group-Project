// MoneyMarketAccount.cpp
#include "MoneyMarket.h"

// MoneyMarketAccount Class methods
MoneyMarket::MoneyMarket(long account_number, double balance): Account(account_number, balance) {  // 1.25% APY
    if (initialDeposit < feeThreshold) {
        cout << "Warning: Initial deposit is less than $10,000. This may incur fees for certain operations." << endl;
    }
}

void MoneyMarket::deposit(double amount) {
    Account::deposit(amount);
}

void MoneyMarket::transfer(Account& toAccount, double amount) {
    if (balance < amount) {
        throw runtime_error("Insufficient funds for transfer.");
    }
    balance -= amount;
    toAccount.deposit(amount);

    // If balance goes below $10,000 after transfer, incur a fee
    if (balance < feeThreshold) {
        balance -= 200;  // $200 fee
        cout << "Transfer fee of $200 applied. New balance: $" << fixed << setprecision(2) << balance << endl;
    }
}

void MoneyMarket::withdraw(double amount) {
    if (balance < amount) {
        throw runtime_error("Insufficient funds for withdrawal.");
    }
    balance -= amount;

    // If balance goes below $10,000 after withdrawal, incur a fee
    if (balance < feeThreshold) {
        balance -= 200;  // $200 fee
        cout << "Withdrawal fee of $200 applied. New balance: $" << fixed << setprecision(2) << balance << endl;
    }
}

double MoneyMarket::calculateInterest() const {
    // Interest calculation for 1.25% APY
    double years = 1.0;  // Since interest is APY, we assume 1 year for simplicity
    return balance * pow(1 + interestRate, years) - balance;
}

void MoneyMarket::printAccount() const {
    Account::printAccount();
    cout << "Interest Rate: " << interestRate * 100 << "% APY" << endl;
}
