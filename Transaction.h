#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <ctime>

class Transaction {
private:
	double amount;
	time_t date;
public:
	double getAmount() const;
	time_t getTime() const;
	Transaction(double a);
	Transaction(double a, time_t d);
	Transaction();
};

#endif
