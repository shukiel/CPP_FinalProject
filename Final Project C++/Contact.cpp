#include "Contact.h"


Contact::Contact(const char* name, const char* phoneNum, const char* address)
{
	this->m_name = _strdup(name);
	this->m_phoneNum = _strdup(phoneNum);
	this->m_address = _strdup(address);
}
Contact::Contact(const Contact& other)
{
	this* = other;
}
Contact::~Contact()
{
	freeAlloc();
}

void Contact::setPhoneNum(const char* phoneNum) { this->m_phoneNum = _strdup(phoneNum); }
void Contact::setAddress(const char* address) { this->m_address = _strdup(address); }
void Contact::freeAlloc()
{
	delete m_name;
	delete m_phoneNum;
	delete m_address;
}

const Contact& Contact::operator=(const Contact& other)
{
	if (this != &other)
	{
		freeAlloc();
		this->m_name = _strdup(other.m_name);
		this->m_phoneNum = _strdup(m_phoneNum);
		this->m_address = _strdup(m_address);
		
	}
}
bool	Contact::operator==(const Contact& other) const
{
	return (strcmp(other.m_address, m_address) && strcmp(other.m_name, m_name) && strcmp(other.m_phoneNum, m_phoneNum));
}
bool	Contact::operator!=(const Contact& other) const
{
	return (!(other == this*));
}
ostream& operator<<(ostream& os, const Contact& contact)
{
	os << contact.m_name << contact.m_phoneNum << contact.m_address; 
	return os;
}
istream& operator>>(istream& in, Contact& contact)
{
	in >> contact.m_name >> contact.m_phoneNum >> contact.m_address;
	return in;
}
