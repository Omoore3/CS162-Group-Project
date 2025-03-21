#include "Account.h"

#using namespace std;

#ifndef DEPOSITABLEACCOUNT_H
#define DEPOSITABLEACCOUNT_H
class DepositableAccount: public Account {
  public:
  virtual void deposit(double amount) = 0;
};

#endif
