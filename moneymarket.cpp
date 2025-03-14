// MoneyMarketAccount.cpp
#include "MoneyMarketAccount.h"

// Base Account Class methods
Account::Account(int id, double balance, double rate) 
    : accountId(id), balance(balance), interestRate(rate) {}

int Account::getAccountId() const {
    return accountId;
}

void Account::setAccountId(int id) {
    accountId = id;
}

double Account::getBalance() const {
    return balance;
}

void Account::setBalance(double balance) {
    this->balance = balance;
}

void Account::deposit(double amount) {
    balance += amount;
}

void Account::transfer(Account& toAccount, double amount) {
    if (balance < amount) {
        throw runtime_error("Insufficient funds for transfer.");
    }
    balance -= amount;
    toAccount.deposit(amount);
}

void Account::withdraw(double amount) {
    if (balance < amount) {
        throw runtime_error("Insufficient funds for withdrawal.");
    }
    balance -= amount;
}

void Account::printAccount() const {
    cout << "Account ID: " << accountId << " | Balance: $" << fixed << setprecision(2) << balance << endl;
}

// MoneyMarketAccount Class methods
MoneyMarketAccount::MoneyMarketAccount(int id, double initialDeposit)
    : Account(id, initialDeposit, 0.0125) {  // 1.25% APY
    if (initialDeposit < feeThreshold) {
        cout << "Warning: Initial deposit is less than $10,000. This may incur fees for certain operations." << endl;
    }
}

void MoneyMarketAccount::deposit(double amount) {
    Account::deposit(amount);
}

void MoneyMarketAccount::transfer(Account& toAccount, double amount) {
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

void MoneyMarketAccount::withdraw(double amount) {
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

double MoneyMarketAccount::calculateInterest() const {
    // Interest calculation for 1.25% APY
    double years = 1.0;  // Since interest is APY, we assume 1 year for simplicity
    return balance * pow(1 + interestRate, years) - balance;
}

void MoneyMarketAccount::printAccount() const {
    Account::printAccount();
    cout << "Interest Rate: " << interestRate * 100 << "% APY" << endl;
}
