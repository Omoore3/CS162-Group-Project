//Name: Atticus Crook
//Purpose: Header file for the base class account.
//Date Modified: 12/02/24
//Compiler Used: MS VC++ 2022

#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <vector>
#include "Transaction.h"


class Account {
private:
	long account_number; //unique identifier for each account class. Need a method
	double balance;	     //to verrify that account_number is unique in all classes (Use a map?)
	std::vector<Transaction> transactions;
	int numOfTransactions;
protected:
	//some of the virtual functions to be inherited by subclasses
	virtual void transfer(Account& other, double amount) = 0;
	virtual void deposit(double amount) = 0;
	virtual void withdraw(double amount) = 0;
	//getters and setters
	Transaction getTransaction(int i) const;
	void setTransaction(int i, Transaction T);
	double getBalance() const;
	void setBalance(double b);
	long getAccountNumber() const;
	void setAccountNumber(long num);
	int getNumOfTransactions() const;
	int setNumOfTransactions() const;
	//Constructors
	Account();
	Account(long a, double b);
	//virtual destructor in case we use pointers. I'm not sure if this
	//is necessary or not but I'm including it as a reminder to check back
	//on it.
	virtual ~Account();

};

#endif
