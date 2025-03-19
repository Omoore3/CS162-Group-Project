#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <ctime>

class Transaction {
private:
	double amount; //positive quanties indicate monies recieved. negative quanties indicate monies sent to source
	time_t date;
	long otherAccountNumber; //use the account_number from the source account class
		     //source of 1 represents an external deposit. source of -1 represent a withdrawal

	//Setters which are inaccessible after initial action made. Required by rubric, but inacessible to prevent fraud
	void setAmount(double a);
	void setTime(time_t newDate);
	void setOtherAccountNumber(long newAccout);
public:
	//getter methods
	double getAmount() const;
	time_t getTime() const;
	long getOtherAccountNumber() const;

	//This project requires all member fields have proper getters and setters.
	//In the real world though, publically accessible setter methods should probably
	//not exist to prevent potential fraud (i.e. rerouting transactions to other accounts.
	//changing transaction amounts, etc.).
	
	Transaction(double a);
	Transaction(double a, time_t d, long num);
	Transaction();
};

#endif
