// SavingsAccount.h

#ifndef SAVINGS_H
#define SAVINGS_H

#include <iostream>
#include <stdexcept>  // To handle errors
#inlcude "Account.h"  //base class

using namespace std;

// Savings Account class derived from Account class
class Savings : public Account {
public:
    SavingsAccount(int id, double initialDeposit); // Constructor to create a savings account

    void withdraw(double amount) override; // Override withdraw method
    void printAccount() const override;   // Override to print savings account details
};

#endif // SAVINGSACCOUNT_H
