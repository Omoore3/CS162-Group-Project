#ifndef CHECKING_H
#define CHECKING_H

#include <string>
#include <iostream>

using namespace std;

class Checking {
private:
    double balance;

public:
    Checking(double balance);
    void deposit(double amount);
    void withdraw(double amount);
    void displayBalance() const;
};

#endif
