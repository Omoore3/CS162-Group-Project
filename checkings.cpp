#include "checkings.h"

Checking::Checking(double balance) : balance(balance) {}

void Checking::deposit(double amount) {
    balance += amount;
}

void Checking::withdraw(double amount) {
    if (amount <= balance) {
        balance -= amount;
    }
    else {
        cout << "Insufficient funds!" << endl;
    }
}

void Checking::displayBalance() const {
    cout << "Checking Balance: $" << balance << endl;
}
