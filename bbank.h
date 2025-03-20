#ifndef BANK_H
#define BANK_H

#include <iostream>
#include "cd.h"
#include "moneymarket.h"
#include "checkings.h"
#include "savings.h"

using namespace std;

class Bank {
private:
    CD* cd;
    MoneyMarket* moneyMarket;
    Checking* checking;
    Savings* savings;

public:
    Bank();
    ~Bank();
    void menu();
};

#endif
