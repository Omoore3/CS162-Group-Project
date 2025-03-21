//Checking.h

#indef CHECKING_H
#define CHECKING_H

#include "DepositableAccount.h"

using namespace std;

class Checking: public DepositableAccount {
private: 
    long cardNo;      // Card Number
    int securityCode; // Security code for the card
    int pin;          // Card pin

public: 
      // Contructor to initalize the checking account with card information and balance
      Checking(long card, int secCode, int pinNumber, double balance);

    // Methods to perform actions on the account
      void withdraw(double amount) override final; // Withdraw money from the account
      void deposit(double amount) override final;  // Deposit money from the account
      void transfer(double amount, Account* recipient) override final // Transfer money from the account

    // Way to validate pin
      bool pinError(int enteredPin) const;
      void printAccount() const;
};

 #endif // CHECKING_H

