#ifndef WITHDRAWABLEACCOUNT_H
#define WITHDRAWABLEACCOUNT_H

class WithdrawableAccount: public Account {
  virtual void withdraw(double amount) = 0;
};

#endif
