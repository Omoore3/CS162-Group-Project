#include <iostream>
using namespace std;
class Person {
private:
	string name;
	int dateOfBirth; // stored as ddmmyyyy
	int phoneNo;
	string email;
	string password;
	Account accounts[4]; //each account will have an assigned number: 0 for CD, 1 for Money Market, etc. TO BE DEFINED
protected:
	void setPass(string pass) { password = pass; }
	void setDOB(int DOB) { dateOfBirth = DOB; }
public:
	Person(string name, int dob, int phone, string email, string pass);
	Person();
	void createAccount();
	Account getAccount(int index);
	void removeAccount(int index);
	//No deconstructor is needed, since the only objects getting added deal with being in a container, needing erase()
	
	string getName() { return name; }
	int getDOB() { return dateOfBirth; }
	int getPhone() { return phoneNo; }
	string getEmail() { return email; }
	string getPass() { return password; }

	void setName(string name) { this->name = name; }
	void setPhone(int phone) { phoneNo = phone; }
	void setEmail(string mail) { email = mail; }
};