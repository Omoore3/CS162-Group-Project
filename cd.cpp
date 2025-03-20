#include "cd.h"

CD::CD(double balance, double interestRate, int term)
    : balance(balance), interestRate(interestRate), term(term) {
}

void CD::deposit(double amount) {
    balance += amount;
}

void CD::withdraw(double amount) {
    if (amount <= balance) {
        balance -= amount;
    }
    else {
        cout << "Insufficient funds!" << endl;
    }
}

void CD::calculateInterest() {
    balance += balance * (interestRate / 100) * (term / 12.0);
}

void CD::displayBalance() const {
    cout << "CD Balance: $" << balance << endl;
}
