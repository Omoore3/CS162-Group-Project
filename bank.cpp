#include "bank.h"

Bank::Bank() {
    cd = nullptr;
    moneyMarket = nullptr;
    checking = nullptr;
    savings = nullptr;
}

Bank::~Bank() {
    delete cd;
    delete moneyMarket;
    delete checking;
    delete savings;
}

void Bank::menu() {
    int choice;
    do {
        cout << "\nBank Menu: \n";
        cout << "1. Create CD\n";
        cout << "2. Create MoneyMarket\n";
        cout << "3. Create Checking Account\n";
        cout << "4. Create Savings Account\n";
        cout << "5. Deposit\n";
        cout << "6. Withdraw\n";
        cout << "7. Display Balances\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            double balance, interestRate;
            int term;
            cout << "Enter initial balance: ";
            cin >> balance;
            cout << "Enter interest rate: ";
            cin >> interestRate;
            cout << "Enter term (in months): ";
            cin >> term;
            cd = new CD(balance, interestRate, term);
            break;
        }
        case 2: {
            double balance, interestRate;
            cout << "Enter initial balance: ";
            cin >> balance;
            cout << "Enter interest rate: ";
            cin >> interestRate;
            moneyMarket = new MoneyMarket(balance, interestRate);
            break;
        }
        case 3: {
            double balance;
            cout << "Enter initial balance: ";
            cin >> balance;
            checking = new Checking(balance);
            break;
        }
        case 4: {
            double balance, interestRate;
            cout << "Enter initial balance: ";
            cin >> balance;
            cout << "Enter interest rate: ";
            cin >> interestRate;
            savings = new Savings(balance, interestRate);
            break;
        }
        case 5: {
            int accType;
            double amount;
            cout << "Enter account type (1-CD, 2-MM, 3-Checking, 4-Savings): ";
            cin >> accType;
            cout << "Enter deposit amount: ";
            cin >> amount;
            switch (accType) {
            case 1: cd->deposit(amount); break;
            case 2: moneyMarket->deposit(amount); break;
            case 3: checking->deposit(amount); break;
            case 4: savings->deposit(amount); break;
            }
            break;
        }
        case 6: {
            int accType;
            double amount;
            cout << "Enter account type (1-CD, 2-MM, 3-Checking, 4-Savings): ";
            cin >> accType;
            cout << "Enter withdrawal amount: ";
            cin >> amount;
            switch (accType) {
            case 1: cd->withdraw(amount); break;
            case 2: moneyMarket->withdraw(amount); break;
            case 3: checking->withdraw(amount); break;
            case 4: savings->withdraw(amount); break;
            }
            break;
        }
        case 7: {
            if (cd) cd->displayBalance();
            if (moneyMarket) moneyMarket->displayBalance();
            if (checking) checking->displayBalance();
            if (savings) savings->displayBalance();
            break;
        }
        case 8:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 8);
}
