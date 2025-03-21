// CDAccount.cpp
#include "CD.h"
#include <stdexcept>
#include <iostream>
#include <cmath>    // For pow function

// CDAccount class methods
CD::CD(int account_number, double balance, int termMonths)
    : Account(account_number, balance), termMonths(termMonths) {
    interestRate = calculateInterestRate();
    maturityReached = false;
    
    time_t currentTime = time(0);
    tm* timeStruct = localtime(&currentTime);
    timeStruct->tm_mon += termMonths;
    mktime(timeStruct);  // Normalize the tm structure
    time_agreement = mktime(timeStruct);
}

static const double CD::calculateInterestRate() const {
    if (termMonths == 3) return CD_3_MON;  // 2.5% for 3 months
    else if (termMonths == 6) return CD_6_MON;  // 3% for 6 months
    else if (termMonths == 12) return CD_12_MON;  // 5% for 12 months
    return 0.0;
}

bool CD::isMaturityDatePassed() const {
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

void CD::withdraw(double amount) {
    if (!isMaturityDatePassed()) {
        throw runtime_error("Cannot withdraw: Maturity date has not passed yet.");
    }
    if (amount > balance) {
        throw runtime_error("Insufficient funds for withdrawal.");
    }
    balance -= amount;
}

void CD::transfer(double amount, Account* recipient) {
    if (!isMaturityDatePassed()) {
        throw runtime_error("Cannot transfer: Maturity date has not passed yet.");
    }
    if (amount > balance) {
        throw runtime_error("Insufficient funds for transfer.");
    }
    balance -= amount;
    toAccount.balance += amount;
}

void CD::printAccount() const {
    cout << "Term: " << termMonths << " months | Interest Rate: "
         << interestRate * 100 << "% | Maturity Date: "
         << put_time(localtime(&time_agreement), "%c") << endl;
}
