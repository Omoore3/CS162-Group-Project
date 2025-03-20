#ifndef MONEYMARKET_H
#define MONEYMARKET_H

#include <string>
#include <iostream>

using namespace std;

class MoneyMarket {
private:
    double balance;
    double interestRate;

public:
    MoneyMarket(double balance, double interestRate);
    void deposit(double amount);
    void withdraw(double amount);
    void calculateInterest();
    void displayBalance() const;
};

#endif
