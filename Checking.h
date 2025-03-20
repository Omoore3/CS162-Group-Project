//Checking.h

#indef CHECKING_H
#define CHECKING_H
#include <iostream>

class Checking {
private: 
    long cardNo;      // Card Number
    int securityCode; // Security code for the card
    int pin;          // Card pin

public: 
      // Contructor to initalize the checking account with card information and balance
      Checking(long card, int secCode, int pinNumber, double balance);

    // Methods to perform actions on the account
      void withdraw(double amount); // Withdraw money from the account
      void deposit(double amount);  // Deposit money from the account
      void transfer(double amount); // Transfer money from the account

    // Way to validate pin
      bool pinError(int enteredPin) const;
      void printAccountInfo() const;
};

 #endif // CHECKING_H

