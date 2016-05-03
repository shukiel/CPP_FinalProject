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

	void setName(const char* name);

public:
	Contact(const char* name, const char* phoneNum, const char* address);
	Contact(const Contact& other) : name(NULL), phoneNum(NULL), address(NULL) { *this = other; }
	virtual ~Contact();

	void setPhoneNum(const char* phoneNum);
	void setAddress(const char* address);

	const char* getName() const { return m_name; }
	const char* getPhoneNum() const { return m_phoneNum; }
	const char* getAddress() const { return m_address; }

	const Contact& operator=(const Contact& other);
	bool operator==(const Contact& other) const { return strcmp(this->getName(), other.getName()) == 0; }
	bool operator!=(const Contact& other) const { return !(*this == other); }
	friend ostream& operator<<(ostream& os, const Contact& contact);
	friend istream& operator>>(istream& in, Contact& contact);

	virtual void toOs(ostream& os) const = 0;
};

#endif