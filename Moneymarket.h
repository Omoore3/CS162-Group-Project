// MoneyMarket.h
#ifndef MONEYMARKET_H
#define MONEYMARKET_H

#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <ctime>
#include <cmath>

using namespace std;

// MoneyMarketAccount Class (derived from Account)
class MoneyMarket : public Account {
private:
    static constexpr double feeThreshold = 10000.00;  // Balance threshold to avoid fees
public:
    MoneyMarket(long account_number, double balance);
    void deposit(double amount) override final;
    void transfer(Account& toAccount, double amount) override final;
    void withdraw(double amount) override final;
    double calculateInterest();
    void printAccount();
};

#endif
