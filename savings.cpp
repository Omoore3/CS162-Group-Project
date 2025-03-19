// SavingsAccount.cpp

#include "Savings.h"

// Method to withdraw money from the account
// Withdrawing from a savings account incurs a $50 fee
void Savings::withdraw(double amount) {
    if (balance < amount - 50) {
        throw runtime_error("Not enough money to withdraw!"); // Handle error if balance is too low
    }
    balance -= amount; // Deduct the amount from the balance
}

// Method to transfer money to another account
void Savings::transfer(Account& toAccount, double amount) {
    if (balance < amount) {
        throw runtime_error("Not enough money to transfer!"); // Handle error if balance is too low
    }
    balance -= amount; // Deduct the amount from this account
    toAccount.deposit(amount); // Add the amount to the other account
}

// Method to print the account details (ID and balance)
void Savings::printAccount() const {
    cout << "Account ID: " << accountId << " | Balance: $" << balance << endl;
}

// Constructor for SavingsAccount class (inherits from Account)
SavingsAccount::SavingsAccount(int id, double initialDeposit)
    : Account(id, initialDeposit) {}

// Overridden withdraw method for SavingsAccount
void Savings::withdraw(double amount) {
    if (balance < amount) {
        throw runtime_error("Not enough money to withdraw!"); // Handle error if balance is too low
    }

    // If balance after withdrawal is below $1,000, apply a $50 penalty
    if (balance - amount < 1000) {
        if (balance - amount < 50) {
            throw runtime_error("Not enough money to cover the $50 penalty!");
        }
        balance -= 50; // Apply $50 penalty
    }

    balance -= amount; // Deduct the amount from the balance
}

// Method to print the savings account details
void SavingsAccount::printAccount() const {
    Account::printAccount(); // Print the base account details
    cout << "Interest Rate: 1.05% APY" << endl; // Print the interest rate
}
