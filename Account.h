//Name: Atticus Crook
//Purpose: Header file for the abstract base class account.
//Date Modified: 12/02/24
//Compiler Used: MS VC++ 2022

#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <vector>
#include "Transaction.h"


class Account {
private:
	long account_number;
	double balance;
	std::vector<Transaction> transactions;
	int numOfTransactions;
protected:
	virtual void transfer(Account *other) = 0;
	virtual void deposit(double amount) = 0;
	virtual void withdraw(double amount) = 0;
	virtual double getBalance() const = 0;
	virtual void setBalance(double b) = 0;
	long getAccountNumber() const;
	void setAccountNumber(long num);
	int getNumOfTransactions() const;
	int setNumOfTransactions() const;
};

#endif
