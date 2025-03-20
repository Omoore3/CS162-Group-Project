//CheckingAccount.h

#indef CHECKINGS_H
#define CHECKINGS_H
#include <iostream>
using namespace std; 

class CheckingAccount {
private: 
    long cardNo;      // Card Number
    int securityCode; // Security code for the card
    int pin;          // Card pin
    double balance;   // Account's balance

public: 
      // Contructor to initalize the checking account with card information and balance
      CheckingAccount(long card, int secCode, int pinNumber, double initialBalance);

    // Methods to perform actions on the account
      void withdraw(double amount); // Withdraw money from the account
      void deposit(double amount);  // Deposit money from the account
      void transfer(double amount); // Transfer money from the account

    // Receiving the balance of the account
      double getBalance() const; 

    // Way to validate pin
      bool pinError(int enteredPin) const;
      void printAccountInfo() const;
};

     #endif // CHECKINGS_H

