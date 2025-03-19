// Cd.h
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
    Cd(long account_number, double balance, int termMonths);
    bool isMaturityDatePassed() const;
    double calculateInterest();
    void deposit(double amount) override final;  // Disable deposit function for this class
    void withdraw(double amount) override final;
    void transfer(CDAccount& toAccount, double amount) override final;
    void printAccount() const override;
};

#endif
