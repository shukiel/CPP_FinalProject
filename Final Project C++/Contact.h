#ifndef __CONTACT_H
#define __CONTACT_H

#include <iostream>
using namespace std;

class Contact
{
private:
	char* name;
	char* phoneNum;
	char* address;

public:
	Contact(char* name, char* phonrNum, char* address);
	Contact(const Contact& other);
	~Contact();

	void setPhoneNum(char* phoneNum);
	void setAddress(char* address);

	const char* getName() const {return name;}
	const char* getPhoneNum() const {return phoneNum;}
	const char* getAddress() const {return address;}

	void show() const;

	const Contact& operator=(const Contact& other);
	bool operator==(const Contact& other) const;
	bool operator!=(const Contact& other) const;
	friend ostream& operator<<(ostream& os, const Contact& contact);
	friend istream& operator>>(istream& in, Contact& contact);
};

#endif