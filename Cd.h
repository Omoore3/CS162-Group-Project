// CDAccount.h
#ifndef CD_H
#define CD_H

#include "Account.h"

#include <iostream>
#include <vector>
#include <stdexcept>
#include <ctime>
#include <iomanip>  // For setprecision
#include <cmath>    // For pow function


// CDAccount Class (derived from Account)
class CD : public Account {
private:
    time_t time_agreement;  // Maturity date of the CD
    double interestRate;    // Interest rate based on the term
    int termMonths;         // The term length of the CD in months

    double calculateInterestRate() const;

public:
    CDAccount(int id, double initialDeposit, int termMonths);
    bool isMaturityDatePassed() const;
    double calculateInterest();
    void deposit(double amount) = delete;  // Disable deposit function for this class
    void withdraw(double amount);
    void transfer(CDAccount& toAccount, double amount);
    void printAccount() const override;
};

// CDAccountSystem Class to manage CD accounts
class CDAccountSystem {
private:
    vector<CDAccount> cdAccounts;

public:
    void addCDAccount(CDAccount account);
    void printCDAccounts() const;
    void transferBetweenAccounts(int fromAccountId, int toAccountId, double amount);
};

#endif // CDACCOUNT_H
