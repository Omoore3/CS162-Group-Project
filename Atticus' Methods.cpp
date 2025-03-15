//Name: Atticus Crook
//Purpose: Implementation of the functions and constructors of the Transaction and Account class
//Date Modified: 12/02/24
//Compiler Used: MS VC++ 2022

#include "Transaction.h"
#include "Account.h"
#include <string>

Transaction::Transaction() : amount(0), date(time(0)) {}

Transaction::Transaction(double a) : amount(a), date(time(0)) {}

Transaction::Transaction(double a, time_t d) : amount(a), date(d) {}

double Transaction::getAmount() const {
	return this->amount;
}

time_t Transaction::getTime() const {
	return this->date;
}

//function implementation for the account class...

//Possible boounds exception. Function must be passed from inside a
//try block with the appropriate catch block
Transaction Account::getTransaction(int i) {
	if(i >= transactions.size() || i < 0) throw string("Out of bounds error. Aborting process...");
	return transactions[i];
}

void Account:setTransaction(int i, Transaction T) {
	if(i >= transactions.size() || i < 0) throw string("Out of bounds error. Aborting process...");
	transactions[i] = T;
}

Account::Account(): account_number(0), balance(0), numOfTransactions(0) {}
Account::Account(long a, double b): account_number(a), balance(b), numOfTransactions(0) {}

