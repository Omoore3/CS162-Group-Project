//Name: Atticus Crook
//Purpose: Implementation of the functions and constructors of the Account class
//Date Modified: 12/02/24
//Compiler Used: MS VC++ 2022

#include "Account.h"
#include <stdexcept>

using namespace std;

//Account class' methods, getters, setters and constructors
//*********************************************************


Account::Account() : account_number(0), balance(0) {} // default constructor

//constructor for account_number and balance
Account::Account(long account_number, double balance) {
	this->account_number = account_number;
	this->balance = balance;
}

//getters for Account class (not virtual functions, those are defined in subclasses)

double Account::getBalance() const {
	return this->balance;
}

long Account::getAccountNumber() const {
	return this->account_number;
}

//setters for Account class

void Account::setBalance(double balance) {
	this->balance = balance;
}

void Account::setAccountNumber(long account_number) {
	this->account_number = account_number;
}
