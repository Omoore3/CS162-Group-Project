// MoneyMarket.h
#ifndef MONEYMARKET_H
#define MONEYMARKET_H

#include "DepositableAccount.h"

#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <ctime>
#include <cmath>

using namespace std;

// MoneyMarketAccount Class (derived from Account)
class MoneyMarket : public DepositableAccount {
private:
    static constexpr double feeThreshold = 10000.00;  // Balance threshold to avoid fees
public:
    MoneyMarket(long account_number, double balance);
    void deposit(double amount) override final;
    void transfer(DepositableAccount* recipient, double amount);
    void withdraw(double amount) override final;
    double calculateInterest();
    void printAccount();
    MoneyMarket();
};

#endif
