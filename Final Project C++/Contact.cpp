#include "Contact.h"

Contact::Contact(char* name, char* phoneNum, char* address)
{
	this->name = strdup(name);
	this->phoneNum = strdup(phoneNum);
	this->address = strdup(address);
}
Contact::Contact(const Contact& other)
{
	this->name = strdup(other->name);
	this->phoneNum = strdup(phoneNum);
	this->address = strdup(address);
}
Contact::~Contact()
{
		
}

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