//Methods primarily for bank and person header files
#include <iostream>
#include<algorithm>
#include<fstream>
using namespace std;
//BANK METHODS
#include "bank.h"
#include "person.h"
#include "Account.h"
#include "Cd.h"
Bank::Bank() {}

void Bank::addCustomer(string name, int dob, int phone, string email, string pass) {
	//if there is no voided(removed customers) adds new customer to the back of the vector. Else, it replaces the first voided customer to save memory.
	for (int i = 0; i < customers.size(); i++) {
		if (customers[i].getPhone() == NULL) {
			customers[i] = Person(name, dob, phone, email, pass);
			return;
		}
		customers.emplace_back(name, dob, phone, email, pass);
	}
}
int Bank::findCustomerIndex(Person customer) {//Searches for a customer by their phone number, since that will always be unique.
	for (int i = 0; i < customers.size(); i++) {
		if (customers[i].getPhone() == customer.getPhone()) {
			return i;
		}
		cout << "Customer not found" << endl;
		return -1;
	}
}

Person Bank::getCustomer(int index) {
	return customers[index];
}

void Bank::removeCustomer(int index) {
	customers[index] = Person();
}

void Bank::retrieve() {
	//reads in customer/account data, gets # of transactions, reads in transaction data
}
void Bank::store() {
	//pretty similar to ^
	ofstream outFile("output.bin", ios::binary);
	for (int i = 0; i < customers.size(); i++) {
		outFile.write(customers[i].getName().c_str(), sizeof(customers[i].getName().c_str()));
		outFile.write(reinterpret_cast<char*>(customers[i].getDOB()), sizeof(customers[i].getDOB()));
		outFile.write(reinterpret_cast<char*>(customers[i].getPhone()), sizeof(customers[i].getPhone()));
		outFile.write(customers[i].getEmail().c_str(), sizeof(customers[i].getEmail().c_str()));
		outFile.write(customers[i].getPass().c_str(), sizeof(customers[i].getPass().c_str()));
		
	}
}

//PERSON METHODS
Person::Person(string name, int dob, int phone, string email, string pass) { //Consstructor for person with all the parameters
	this->name = name;
	dateOfBirth = dob;
	phoneNo = phone;
	this->email = email;
	password = pass;
}

void Person::createAccount(long num, double balance, int type) {
	//Call account constructor, based on the number given
	if (type == 1) {//Calls CD constructor
		int term;
		cout << "How many months is the term?" << endl;
		cin >> term;
		Cd myCd(num, balance, term);
	}
	else if (type == 2) {//Calls MM constructor

	}
	else if (type == 3) {//Calls Savings constructor

	}
	else if (type == 4) {//Calls Checking constructor

	}
}
Account Person::getAccount(int index) {
	return accounts[index]; //Returns the account at the given index
}
void Person::removeAccount(int index) {
	~Account accounts[index]; //Calls the deconstructor for the account linked to that index
}
Person::Person() { //Default constructor that sets all customer identifiers to null, as a way to erase customers.
	name = '\0';
	dateOfBirth = NULL;
	phoneNo = NULL;
	email = '\0';
	password = '\0';
}
