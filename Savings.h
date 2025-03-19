// SavingsAccount.h

#ifndef SAVINGS_H
#define SAVINGS_H

#include <stdexcept>  // To handle errors
#include "Account.h"  //base class

using namespace std;

// Savings Account class derived from Account class
class Savings : public Account {
public:
    Savings(int id, double initialDeposit); // Constructor to create a savings account

    void withdraw(double amount) override final; // Override withdraw method
    void transfer(Account* other) override final; // Override transfer method
    void deposit(double amount) override final; // Override deposit method

};

#endif // SAVINGSACCOUNT_H
