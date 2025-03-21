#ifndef BANK_H
#define BANK_H
#include <vector>
#include "person.h"
using namespace std;
class Bank {
private:
	vector<Person> customers;
protected:
	double const MM_INTEREST = 0.0125;
	double const CHECK_INTEREST = 0.0002;
public:
	Bank();
	void addCustomer(string name, int dob, int phone, string email, string pass);
	int findCustomerIndex(Person customer);
	void removeCustomer(int index);
	Person getCustomer(int index);
};
#endif
