//Methods primarily for bank and person header files
#include <iostream>
#include<algorithm>
using namespace std;
//BANK METHODS
#include "bank.h"
#include "person.h"
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

void Bank::removeCustomer(int index) {
	customers[index] = Person();
}

//PERSON METHODS
Person::Person(string name, int dob, int phone, string email, string pass) { //Consstructor for person with all the parameters
	this->name = name;
	dateOfBirth = dob;
	phoneNo = phone;
	this->email = email;
	password = pass;
}

void Person::createAccount(){
	//Call account constructor, based on the number given
}
Account Person::getAccount(int index) {
	return accounts[index]; //Returns the account at the given index
}
void Person::removeAccount(int index) {
	~Account[index]; //Calls the deconstructor for the account linked to that index
}
Person::Person() { //Default constructor that sets all customer identifiers to null, as a way to erase customers.
	name = '\0';
	dateOfBirth = NULL;
	phoneNo = NULL;
	email = '\0';
	password = '\0';
}