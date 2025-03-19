// Savings.h

#ifndef SAVINGS_H
#define SAVINGS_H

#include "Account.h"  //base class

// Savings Account class derived from Account class
class Savings : public Account {
public:
    Savings(int account_number, double balance); // Constructor to create a savings account

    void withdraw(double amount) override final; // Override withdraw method
    void transfer(Account* other) override final; // Override transfer method
    void deposit(double amount) override final; // Override deposit method

};

#endif
