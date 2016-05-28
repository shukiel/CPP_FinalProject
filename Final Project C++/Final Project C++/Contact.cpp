#include "Contact.h"

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
	os << "Name: " << m_name << ", Phone number: " << m_phoneNum << ", Address: " << m_address << endl;
}