#include "DepositableAccount.h"

using namespace std;

void DepositableAccount::deposit(double amount) {
  this->setBalance(this->getBalance() - amount);
}
