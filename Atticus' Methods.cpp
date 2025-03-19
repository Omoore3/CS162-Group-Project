//Name: Atticus Crook
//Purpose: Implementation of the functions and constructors of the Transaction and Account class
//Date Modified: 12/02/24
//Compiler Used: MS VC++ 2022

#include "Account.h"
#include <stdexcept>
#include <string>

//Transaction class' methods, getters, setters and constructors
//*********************************************************

//default constructor. Should NOT be used in code, as setters are private
Transaction::Transaction() : amount(0), date(time(0)), otherAccountNumber(0) {}

//given an amount by default creates a transaction at the time the object is instantiated. If amount is negative, 
// transaction represents a withdrawal, if positve represents a deposit. Used for creating deposits and withdrawals
Transaction::Transaction(double amount) {
	this->amount = amount;
	this->date = time(0); //sets time to the time of the objects instantiation
	if(amount < 0) { // if transaction represents a negative quantity, it represents a withdrawal
		this->otherAccountNumber = -1;
	} else { // otherwise the transaction will represent a deposit
		this->otherAccountNumber = 1;
	}	
} 

//should be the constructor used to create transfers between acounts
//creates a transaction of the amount at the current time and with the accountNumber specified. Should be the constructor used when creating functions
Transaction::Transaction(double amount, long otherAccountNumber) {
	this->amount = amount;
	this->date = time(0);
	this->otherAccountNumber = otherAccountNumber;
}

//getters

double Transaction::getAmount() const {
	return this->amount;
}

time_t Transaction::getTime() const {
	return this->date;
}

long Transaction::getOtherAccountNumber() const {
	return this->otherAccountNumber;
}

//implementation of private setters for transaction class

void Transaction::setAmount(double newAmount) {
	this->amount = newAmount;
}

void Transaction::setTime(time_t newDate) {
	this->date = newDate;
}

void Transaction::setOtherAccountNumber(long newOtherAccountNumber) {
	this->otherAccountNumber = newOtherAccountNumber;
}



//Account class' methods, getters, setters and constructors
//*********************************************************


Account::Account(): account_number(0), balance(0), numOfTransactions(0) {} // default constructor
Account::Account(long a, double b): account_number(a), balance(b), numOfTransactions(0) {} //constructor for account_number and balance

//Possible boounds exception. Function must be passed from inside a
//try block with the appropriate catch block
Transaction Account::getTransaction(int i) {
	if(i >= transactions.size() || i < 0) 
		throw runtime_error("Out of bounds error. Aborting process...");
	return transactions[i];
}
void Account::setTransaction(int i, Transaction T) {
	if(i >= transactions.size() || i < 0) 
		throw runtime_error("Out of bounds error. Aborting process...");
	transactions[i] = T;
}
