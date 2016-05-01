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
	Contact(const char* name, const char* phoneNum, const char* address);
	Contact(const Contact& other);
	~Contact();

	void setPhoneNum(const char* phoneNum);
	void setAddress(const char* address);

	const char* getName() const { return name; }
	const char* getPhoneNum() const { return phoneNum; }
	const char* getAddress() const { return address; }

	const Contact& operator=(const Contact& other);
	bool operator==(const Contact& other) const;
	bool operator!=(const Contact& other) const;
	friend ostream& operator<<(ostream& os, const Contact& contact);
	friend istream& operator>>(istream& in, Contact& contact);
};

#endif