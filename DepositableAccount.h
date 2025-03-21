#include "Account.h"

using namespace std;

#ifndef DEPOSITABLEACCOUNT_H
#define DEPOSITABLEACCOUNT_H
class DepositableAccount : public Account {
public:
	void deposit(double amount);
};

#endif
