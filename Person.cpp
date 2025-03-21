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
		CD myCd(num, balance, term);
		accPtr[0] = &myCd;
	}
	else if (type == 2) {//Calls MM constructor

	}
	else if (type == 3) {//Calls Savings constructor

	}
	else if (type == 4) {//Calls Checking constructor

	}
}
template <class T>
T Person::getAccount<T>(int index) {
	return *accPtr[0]; //Returns the account at the given index
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