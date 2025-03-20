#ifndef CD_H
#define CD_H

#include <string>
#include <iostream>

using namespace std;

class CD {
private:
    double balance;
    double interestRate;
    int term; // in months

public:
    CD(double balance, double interestRate, int term);
    void deposit(double amount);
    void withdraw(double amount);
    void calculateInterest();
    void displayBalance() const;
};

#endif
