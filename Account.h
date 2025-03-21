//Name: Atticus Crook
//Purpose: Header file for the base class account.
//Date Modified: 12/02/24
//Compiler Used: MS VC++ 2022

#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <vector>
#include "Transaction.h"

using namespace std;

class Account {
private:
	long account_number; //unique identifier for each account class. Need a method
	double balance;	     //to verrify that account_number is unique in all classes (Use a map?)
	vector<Transaction> transactions;
	int numOfTransactions;

	//setters which should be inaccessible to prevent fraud, but are required for the rubric
	void setTransaction(int i, Transaction T);
	void setBalance(double balance);
	void setAccountNumber(long account_number);
	void setNumOfTransactions();
protected:
	//some of the virtual functions to be inherited by subclasses
	virtual void transfer(double amount, Account* recipient) = 0;
	virtual void deposit(double amount) = 0;
	virtual void withdraw(double amount) = 0;
	//getters
	Transaction getTransaction(int i) const;
	double getBalance() const;
	long getAccountNumber() const;
	int getNumOfTransactions() const;
	//Constructors
	Account();
	Account(long account_number, double balance);
	//virtual destructor in case we use pointers. I'm not sure if this
	//is necessary or not but I'm including it as a reminder to check back
	//on it.
	virtual ~Account();

};

#endif
