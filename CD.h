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

	static const double CD_3_MON = 0.025;
	static const double CD_6_MON = 0.03;
	static const double CD_12_MON = 0.05;
    	double calculateInterestRate() const;
public:
	CD(long account_number, double balance, int termMonths);
	bool isMaturityDatePassed() const;
	double calculateInterest();
    	void deposit(double amount) override final;  // Disable deposit function for this class
    	void withdraw(double amount) override final;
    	void transfer(double amount, Account* recipient) override final;
    	void printAccount() const;
};

#endif
