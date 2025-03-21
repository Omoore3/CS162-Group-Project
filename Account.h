//Name: Atticus Crook
//Purpose: Header file for the base class account.
//Date Modified: 12/02/24
//Compiler Used: MS VC++ 2022

#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <vector>
#include <ctime>

using namespace std;

class Account {
private:
	long account_number; //unique identifier for each account class. Need a method
	double balance;	     //to verrify that account_number is unique in all classes (Use a map?)
	time_t lastAccess;

	//setters which should be inaccessible to prevent fraud, but are required for the rubric
	void setBalance(double balance);
	void setAccountNumber(long account_number);
protected:
	//some of the virtual functions to be inherited by subclasses
	virtual void transfer(double amount, Account* recipient) = 0;
	virtual void deposit(double amount) = 0;
	virtual void withdraw(double amount) = 0;
	virtual void updateBalance() = 0;
	//getters
	double getBalance() const;
	long getAccountNumber() const;
	//Constructors
	Account();
	Account(long account_number, double balance);
};

#endif
