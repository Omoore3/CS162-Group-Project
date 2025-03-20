#include "moneymarket.h"

MoneyMarket::MoneyMarket(double balance, double interestRate)
    : balance(balance), interestRate(interestRate) {
}

void MoneyMarket::deposit(double amount) {
    balance += amount;
}

void MoneyMarket::withdraw(double amount) {
    if (amount <= balance) {
        balance -= amount;
    }
    else {
        cout << "Insufficient funds!" << endl;
    }
}

void MoneyMarket::calculateInterest() {
    balance += balance * (interestRate / 100);
}

void MoneyMarket::displayBalance() const {
    cout << "Money Market Balance: $" << balance << endl;
}
