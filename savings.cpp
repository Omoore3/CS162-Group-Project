#include "savings.h"

Savings::Savings(double balance, double interestRate)
    : balance(balance), interestRate(interestRate) {
}

void Savings::deposit(double amount) {
    balance += amount;
}

void Savings::withdraw(double amount) {
    if (amount <= balance) {
        balance -= amount;
    }
    else {
        cout << "Insufficient funds!" << endl;
    }
}

void Savings::calculateInterest() {
    balance += balance * (interestRate / 100);
}

void Savings::displayBalance() const {
    cout << "Savings Balance: $" << balance << endl;
}
