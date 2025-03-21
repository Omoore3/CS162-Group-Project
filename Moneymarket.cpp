// MoneyMarketAccount.cpp
#include "MoneyMarket.h"
#include "Account.h"

using namespace std;

// MoneyMarketAccount Class methods
MoneyMarket::MoneyMarket(long account_number, double balance): DepositableAccount(account_number, balance) {  // 1.25% APY
    if (balance < feeThreshold) {
        cout << "Warning: Initial deposit is less than $10,000. This may incur fees for certain operations." << endl;
    }
}

void MoneyMarket::deposit(double amount) {
    setBalance(getBalance() + amount);
}

void MoneyMarket::transfer(DepositableAccount* recipient, double amount) {
    if (this->getBalance() < amount) {
        throw runtime_error("Insufficient funds for transfer.");
    }
    this->setBalance(this->getBalance() - amount); // this statement replaces balance -= amount
    recipient->deposit(amount);

    // If balance goes below $10,000 after transfer, incur a fee
    if (getBalance() < feeThreshold) {
        setBalance(this->getBalance() - 200);  // $200 fee
        cout << "Transfer fee of $200 applied. New balance: $" << fixed << setprecision(2) << getBalance() << endl;
    }
}

void MoneyMarket::withdraw(double amount) {
    if (getBalance() < amount) {
        throw runtime_error("Insufficient funds for withdrawal.");
    }
    this->setBalance(this->getBalance() - amount);

    // If balance goes below $10,000 after withdrawal, incur a fee
    if (getBalance() < feeThreshold) {
        setBalance(this->getBalance() - 200);  // $200 fee
        cout << "Withdrawal fee of $200 applied. New balance: $" << fixed << setprecision(2) << getBalance() << endl;
    }
}

double MoneyMarket::calculateInterest() const {
    
    double years = 1.0;
    return getBalance() * pow(1 + interestRate, years) - getBalance();
}

void MoneyMarket::printAccount() const {
    Account::printAccount();
    cout << "Interest Rate: " << interestRate * 100 << "% APY" << endl;
}
