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
	virtual ~Contact();

	void setName(const char* name);
	void setPhoneNum(const char* phoneNum);
	void setAddress(const char* address);

	const char* getName() const { return m_name; }
	const char* getPhoneNum() const { return m_phoneNum; }
	const char* getAddress() const { return m_address; }

	const Contact& operator=(const Contact& other);
	bool operator==(const Contact& other) const { return ((strcmp(this->getName(), other.getName()) == 0) && (strcmp(this->getPhoneNum(), other.getPhoneNum()))); }
	bool operator!=(const Contact& other) const { return !(*this == other); }
	friend ostream& operator<<(ostream& os, const Contact& contact);
	friend istream& operator>>(istream& in, Contact& contact);
	
	virtual void toOs(ostream& os) const;
};

#endif