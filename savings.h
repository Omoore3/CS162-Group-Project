// SavingsAccount.h

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include <iostream>
#include <stdexcept>  // To handle errors

// Base Account class
class Account {
protected:
    int accountId;  // Account ID
    double balance; // Balance in the account

public:
    Account(int id, double balance); // Constructor to set account ID and balance
    double getBalance() const;       // To get the account balance
    void deposit(double amount);     // To deposit money into the account
    void withdraw(double amount);    // To withdraw money from the account
    void transfer(Account& toAccount, double amount); // To transfer money to another account
    virtual void printAccount() const; // To print account details
};

// Savings Account class derived from Account class
class SavingsAccount : public Account {
public:
    SavingsAccount(int id, double initialDeposit); // Constructor to create a savings account

    void withdraw(double amount) override; // Override withdraw method
    void printAccount() const override;   // Override to print savings account details
};

#endif // SAVINGSACCOUNT_H
