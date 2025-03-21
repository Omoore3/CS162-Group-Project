// CDAccount.cpp
#include "Cd.h"
#include <stdexcept>
#include <iostream>
#include <cmath>    // For pow function

// CDAccount class methods
Cd::Cd(int account_number, double balance, int termMonths)
    : Account(account_number, balance), termMonths(termMonths) {
    interestRate = calculateInterestRate();
    maturityReached = false;
    
    time_t currentTime = time(0);
    tm* timeStruct = localtime(&currentTime);
    timeStruct->tm_mon += termMonths;
    mktime(timeStruct);  // Normalize the tm structure
    time_agreement = mktime(timeStruct);
}

double Cd::calculateInterestRate() const {
    if (termMonths == 3) return 0.025;  // 2.5% for 3 months
    else if (termMonths == 6) return 0.03;  // 3% for 6 months
    else if (termMonths == 12) return 0.05;  // 5% for 12 months
    return 0.0;
}

bool Cd::isMaturityDatePassed() const {
    if(difftime(time(0), time_agreement) > 0 && !maturityReached) {
        balance += calculateInterest();
        maturityReached = true;
    }
    return difftime(time(0), time_agreement) > 0;
}

double Cd::calculateInterest() {
    double years = static_cast<double>(termMonths) / 12.0;
    double interest = balance * pow(1 + interestRate, years) - balance;
    return interest;
}

void Cd::withdraw(double amount) {
    if (!isMaturityDatePassed()) {
        throw runtime_error("Cannot withdraw: Maturity date has not passed yet.");
    }
    if (amount > balance) {
        throw runtime_error("Insufficient funds for withdrawal.");
    }
    balance -= amount;
}

void Cd::transfer(CDAccount* recipient, double amount) {
    if (!isMaturityDatePassed()) {
        throw runtime_error("Cannot transfer: Maturity date has not passed yet.");
    }
    if (amount > balance) {
        throw runtime_error("Insufficient funds for transfer.");
    }
    balance -= amount;
    toAccount.balance += amount;
}

void Cd::printAccount() const {
    cout << "Term: " << termMonths << " months | Interest Rate: "
         << interestRate * 100 << "% | Maturity Date: "
         << put_time(localtime(&time_agreement), "%c") << endl;
}

void Cd::transferBetweenAccounts(int fromAccountId, int toAccountId, double amount) {
    Cd* fromAccount = nullptr;
    Cd* toAccount = nullptr;

    for (auto& account : cdAccounts) {
        if (account.getAccountId() == fromAccountId) {
            fromAccount = &account;
        } else if (account.getAccountId() == toAccountId) {
            toAccount = &account;
        }
    }

    if (fromAccount && toAccount) {
        fromAccount->transfer(*toAccount, amount);
        cout << "Transfer successful!" << endl;
    } else {
        cout << "Error: One or both account IDs not found." << endl;
    }
}
