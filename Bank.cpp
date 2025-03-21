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
	//reads in customer/account data; Assuming that all objects are already created.
	ifstream inFile("output.bin", ios::binary);
	int readsize;
	inFile.read(reinterpret_cast<char*>(&readsize), sizeof(readsize));


	for (int i = 0; i < readsize; i++) {
		inFile.read(reinterpret_cast<char*>(&customers[i]), sizeof(customers[i]));
	}
}
void Bank::store() {
	//pretty similar to ^
	ofstream outFile("output.bin", ios::binary);
	outFile.write(reinterpret_cast<char*>(customers.size()), sizeof(customers.size());

	for (int i = 0; i < customers.size(); i++) {
		outFile.write(customers[i].getName().c_str(), sizeof(customers[i].getName().c_str())); //Saving the 
		outFile.write(reinterpret_cast<char*>(customers[i].getDOB()), sizeof(customers[i].getDOB()));
		outFile.write(reinterpret_cast<char*>(customers[i].getPhone()), sizeof(customers[i].getPhone()));
		outFile.write(customers[i].getEmail().c_str(), sizeof(customers[i].getEmail().c_str()));
		outFile.write(customers[i].getPass().c_str(), sizeof(customers[i].getPass().c_str()));

		if (customers[i].getAccount(0).getNumber() != 0) {//DEFINE getNumber OR SOMETHING OF SIMILAR FUNCTION THAT GETS THE ACCOUNT NUMBER
			outFile.write(reinterpret_cast<char*>(customers[i].getAccount(0)), sizeof(customers[i].getAccount(0)));
		}
		if (customers[i].getAccount(1).getNumber() != 0) {
			outFile.write(reinterpret_cast<char*>(customers[i].getAccount(1)), sizeof(customers[i].getAccount(1)));
		}
		if (customers[i].getAccount(2).getNumber() != 0) {
			outFile.write(reinterpret_cast<char*>(customers[i].getAccount(2)), sizeof(customers[i].getAccount(2)));
		}
		if (customers[i].getAccount(3).getNumber() != 0) {
			outFile.write(reinterpret_cast<char*>(customers[i].getAccount(3)), sizeof(customers[i].getAccount(3)));
		}
	}
	outFile.close();
}