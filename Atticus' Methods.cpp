#include "Transaction.h"
#include "Account.h"

Transaction::Transaction() : amount(0), date(time(0)) {}

Transaction::Transaction(double a) : amount(a), date(time(0)) {}

Transaction::Transaction(double a, time_t d) : amount(a), date(d) {}

double Transaction::getAmount() const {
	return this->amount;
}

time_t Transaction::getTime() const {
	return this->date;
}
