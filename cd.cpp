// CDAccount.cpp
#include "cd.h"

using namespace std;

// Account class methods
Account::Account(int id, double balance) : accountId(id), balance(balance) {}

int Account::getAccountId() const {
    return accountId;
}

void Account::setAccountId(int id) {
    accountId = id;
}

double Account::getBalance() const {
    return balance;
}

void Account::setBalance(double balance) {
    this->balance = balance;
}

void Account::printAccount() const {
    cout << "Account ID: " << accountId << " | Balance: $" << fixed << setprecision(2) << balance << endl;
}

// CDAccount class methods
CDAccount::CDAccount(int id, double initialDeposit, int termMonths)
    : Account(id, initialDeposit), termMonths(termMonths) {
    interestRate = calculateInterestRate();
    
    time_t currentTime = time(0);
    tm* timeStruct = localtime(&currentTime);
    timeStruct->tm_mon += termMonths;
    mktime(timeStruct);  // Normalize the tm structure
    time_agreement = mktime(timeStruct);
}

double CDAccount::calculateInterestRate() const {
    if (termMonths == 3) return 0.025;  // 2.5% for 3 months
    else if (termMonths == 6) return 0.03;  // 3% for 6 months
    else if (termMonths == 12) return 0.05;  // 5% for 12 months
    return 0.0;
}

bool CDAccount::isMaturityDatePassed() const {
    return difftime(time(0), time_agreement) > 0;
}

double CDAccount::calculateInterest() {
    if (!isMaturityDatePassed()) {
        throw runtime_error("Cannot calculate interest: Maturity date has not passed yet.");
    }

    double years = static_cast<double>(termMonths) / 12.0;
    double interest = balance * pow(1 + interestRate, years) - balance;
    return interest;
}

void CDAccount::withdraw(double amount) {
    if (!isMaturityDatePassed()) {
        throw runtime_error("Cannot withdraw: Maturity date has not passed yet.");
    }
    if (amount > balance) {
        throw runtime_error("Insufficient funds for withdrawal.");
    }
    balance -= amount;
}

void CDAccount::transfer(CDAccount& toAccount, double amount) {
    if (!isMaturityDatePassed()) {
        throw runtime_error("Cannot transfer: Maturity date has not passed yet.");
    }
    if (amount > balance) {
        throw runtime_error("Insufficient funds for transfer.");
    }
    balance -= amount;
    toAccount.balance += amount;
}

void CDAccount::printAccount() const {
    Account::printAccount();
    cout << "Term: " << termMonths << " months | Interest Rate: "
         << interestRate * 100 << "% | Maturity Date: "
         << put_time(localtime(&time_agreement), "%c") << endl;
}

// CDAccountSystem class methods
void CDAccountSystem::addCDAccount(CDAccount account) {
    cdAccounts.push_back(account);
    cout << "CD Account added successfully!" << endl;
}

void CDAccountSystem::printCDAccounts() const {
    cout << "\n--- List of CD Accounts ---" << endl;
    for (const auto& account : cdAccounts) {
        account.printAccount();
    }
}

void CDAccountSystem::transferBetweenAccounts(int fromAccountId, int toAccountId, double amount) {
    CDAccount* fromAccount = nullptr;
    CDAccount* toAccount = nullptr;

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
