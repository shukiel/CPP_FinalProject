#ifndef __CONTACT_H
#define __CONTACT_H

#include <iostream>
#include <string>
using namespace std;

class Contact
{
protected:
	string m_name;
	string m_phoneNum;
	string m_address;

public:
	Contact(const string& name, const string& phoneNum, const string& address) : m_name(name), m_phoneNum(phoneNum), m_address(address) { }
	Contact() { }

	void setName(const string& name)			{ m_name = name; }
	void setPhoneNum(const string& phoneNum)	{ m_phoneNum = phoneNum; }
	void setAddress(const string& address)		{ m_address = address; }

	const string& getName()		const { return m_name; }
	const string& getPhoneNum()	const { return m_phoneNum; }
	const string& getAddress()	const { return m_address; }

	bool operator==(const Contact& other) const { return getName().compare(other.getName()) == 0 && getPhoneNum().compare(other.getPhoneNum()) == 0; }
	bool operator!=(const Contact& other) const { return !(*this == other); }

	friend ostream& operator<<(ostream& os, const Contact& contact);
	friend istream& operator>>(istream& in, Contact& contact);
	
	virtual void toOs(ostream& os) const;
};

#endif