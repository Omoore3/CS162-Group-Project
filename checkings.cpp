// CheckingAccount.cpp

#include "checkings.h"

// Constructor to initialize the Checking Account
CheckingAccount::CheckingAccount(long card, int secCode, int pinNumber, double initialBalance)
    : cardNo(card), securityCode(secCode), pin(pinNumber), balance(initialBalance) {}

// Withdraw money from the account
void CheckingAccount::withdraw(double amount) {
    cout << "Enter pin number to proceed with withdrawal: ";
    int enteredPin;
    cin >> enteredPin;

    if (pinError(enteredPin)) {
        cout << "Incorrect pin! Withdrawal declined." << endl;
        return;
    }

    if (amount > balance) {
        cout << "Insufficient funds! Withdrawal declined." << endl;
    } else {
        balance -= amount;
        cout << "Withdrawal of $" << amount << " successful!" << endl;
    }
}

// Deposit money into the account
void CheckingAccount::deposit(double amount) {
    balance += amount;
    cout << "Deposit of $" << amount << " successful!" << endl;
}

// Transfer money to another Checking Account
void CheckingAccount::transfer(double amount, CheckingAccount& recipient) {
    cout << "Enter pin number to proceed with transfer: ";
    int enteredPin;
    cin >> enteredPin;

    if (pinError(enteredPin)) {
        cout << "Incorrect pin! Transfer declined." << endl;
        return;
    }

    if (amount > balance) {
        cout << "Insufficient funds! Transfer declined." << endl;
    } else {
        balance -= amount;
        recipient.deposit(amount);  // Add money to the recipient's account
        cout << "Transfer of $" << amount << " successful!" << endl;
    }
}

// Check if the entered pin is correct
bool CheckingAccount::pinError(int enteredPin) const {
    return enteredPin != pin;
}

// Get the balance of the account
double CheckingAccount::getBalance() const {
    return balance;
}

// Print the account information
void CheckingAccount::printAccountInfo() const {
    cout << "Card Number: " << cardNo << endl;
    cout << "Balance: $" << balance << endl;
    cout << "Interest Rate: 0.02% APY" << endl;
}
