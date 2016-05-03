#ifndef __CONTACT_H
#define __CONTACT_H

#include <iostream>
using namespace std;

class Contact
{
private:
	char* m_name;
	char* m_phoneNum;
	char* m_address;

	void freeAlloc();

public:
	Contact(const char* name, const char* phoneNum, const char* address);
	Contact(const Contact& other);
	~Contact();

	void setPhoneNum(const char* phoneNum);
	void setAddress(const char* address);

	const char* getName() const { return m_name; }
	const char* getPhoneNum() const { return m_phoneNum; }
	const char* getAddress() const { return m_address; }

	const Contact& operator=(const Contact& other);
	bool operator==(const Contact& other) const;
	bool operator!=(const Contact& other) const;
	friend ostream& operator<<(ostream& os, const Contact& contact);
	friend istream& operator>>(istream& in, Contact& contact);
};

#endif