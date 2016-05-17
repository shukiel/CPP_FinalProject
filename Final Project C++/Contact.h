#ifndef __CONTACT_H
#define __CONTACT_H

#include <iostream>
using namespace std;

class Contact
{
protected:
	char* m_name;
	char* m_phoneNum;
	char* m_address;

public:
	Contact(const char* name, const char* phoneNum, const char* address);
	Contact(const Contact& other) : m_name(NULL), m_phoneNum(NULL), m_address(NULL) { *this = other; }
	Contact() { }
	virtual ~Contact();

	void setName(const char* name)			{ m_name = _strdup(name); }
	void setPhoneNum(const char* phoneNum)	{ m_phoneNum = _strdup(phoneNum); }
	void setAddress(const char* address)	{ m_address = _strdup(address); }

	const char* getName()		const { return m_name; }
	const char* getPhoneNum()	const { return m_phoneNum; }
	const char* getAddress()	const { return m_address; }

	bool operator==(const Contact& other) const { return strcmp(getName(), other.getName()) == 0 && strcmp(getPhoneNum(), other.getPhoneNum()) == 0; }
	bool operator!=(const Contact& other) const { return !(*this == other); }

	const Contact& operator=(const Contact& other);
	friend ostream& operator<<(ostream& os, const Contact& contact);
	friend istream& operator>>(istream& in, Contact& contact);
	
	virtual void toOs(ostream& os) const;
};

#endif