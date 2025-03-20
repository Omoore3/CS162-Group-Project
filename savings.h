#ifndef SAVINGS_H
#define SAVINGS_H

#include <string>
#include <iostream>

using namespace std;

class Savings {
private:
    double balance;
    double interestRate;

public:
    Savings(double balance, double interestRate);
    void deposit(double amount);
    void withdraw(double amount);
    void calculateInterest();
    void displayBalance() const;
};

#endif
