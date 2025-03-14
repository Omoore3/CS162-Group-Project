// MoneyMarketAccount.h
#ifndef MONEYMARKETACCOUNT_H
#define MONEYMARKETACCOUNT_H

#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <ctime>
#include <cmath>

using namespace std;

// Base Account Class
class Account {
protected:
    int accountId;
    double balance;
    double interestRate;

public:
    Account(int id = 0, double balance = 0.0, double rate = 0.0);
    int getAccountId() const;
    void setAccountId(int id);
    double getBalance() const;
    void setBalance(double balance);
    virtual void deposit(double amount);
    virtual void transfer(Account& toAccount, double amount);
    virtual void withdraw(double amount);
    virtual void printAccount() const;
    virtual double calculateInterest() const = 0;  // To be implemented by derived classes
};

// MoneyMarketAccount Class (derived from Account)
class MoneyMarketAccount : public Account {
private:
    static constexpr double feeThreshold = 10000.00;  // Balance threshold to avoid fees

public:
    MoneyMarketAccount(int id, double initialDeposit);
    void deposit(double amount) override;
    void transfer(Account& toAccount, double amount) override;
    void withdraw(double amount) override;
    double calculateInterest() const override;
    void printAccount() const override;
};

#endif // MONEYMARKETACCOUNT_H
