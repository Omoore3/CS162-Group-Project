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

Account* Person::getAccount(int index) {
	return *(accPtr + index); //Returns the account at the given index
}
void Person::removeAccount(int index) {
	if (index == 1) {//Calls the default constructor for the account linked to that index
		CD defCD();
		accPtr[0] = &defCD;
	}
	else if (index == 2) {
		MM defMM();
		accPtr[1] = &defMM;
	}
	else if (index == 3) {
		Savings defSav();
		accPtr[2] = &defSav;
	}
	else if (index == 4) {
		Checking defCheck();
		accPtr[3] = &defCheck;
	}
}
Person::Person() { //Default constructor that sets all customer identifiers to null, as a way to erase customers.
	name = '\0';
	dateOfBirth = NULL;
	phoneNo = NULL;
	email = '\0';
	password = '\0';
}