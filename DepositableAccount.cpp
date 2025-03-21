void DepositableAccount::deposit(double amount) {
  this->setBalance(this->getBalance() - amount);
}
