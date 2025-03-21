// Cd.h
#ifndef CD_H
#define CD_H

#include "Account.h"

#include <ctime>

using namespace std;


// CDAccount Class (derived from Account)
class CD : public Account {
private:
    time_t time_agreement;  // Maturity date of the CD
    int termMonths;         // The term length of the CD in months
    bool maturityReached;

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
