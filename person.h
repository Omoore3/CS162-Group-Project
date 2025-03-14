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
public:
	Person(string name, int dob, int phone, string email, string pass);
	Person();
	void createAccount();
	Account getAccount(int index);
	void removeAccount(int index);
	//No deconstructor is needed, since the only objects getting added deal with being in a container, needing erase()
	int getPhone() {
		return phoneNo;
	}
};