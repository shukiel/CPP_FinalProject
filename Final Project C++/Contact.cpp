#include "Contact.h"

Contact::Contact(const char* name, const char* phoneNum, const char* address) : m_name(NULL), m_phoneNum(NULL), m_address(NULL)
{
	setName(name);
	setPhoneNum(phoneNum);
	setAddress(address);
}

Contact::~Contact()
{
	delete []m_name;
	delete []m_phoneNum;
	delete []m_address;
}

const Contact& Contact::operator=(const Contact& other)
{
	if (this != &other)
	{
		setName(other.getName());
		setPhoneNum(other.getPhoneNum());
		setAddress(other.getAddress());
	}
	return *this;
}

ostream& operator<<(ostream& os, const Contact& contact)
{
	contact.toOs(os);
	return os;
}

istream& operator>>(istream& in, Contact& contact)
{
	char temp[50];

	cout << "Please insert the contact's name: ";
	in.getline(temp, 25);
	contact.setName(temp);

	cout << "Please insert the contact's phone number: ";
	in.getline(temp, 25);
	contact.setPhoneNum(temp);

	cout << "Please insert the contact's address: ";
	in.getline(temp, 25);
	contact.setAddress(temp);

	return in;
}

void Contact::toOs(ostream& os) const
{
	os << "Name: " << getName() << ", Phone number: " << getPhoneNum() << ", Address: " << getAddress() << endl;
}