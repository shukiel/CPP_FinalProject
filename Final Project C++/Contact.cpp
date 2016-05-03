#include "Contact.h"

	Contact::Contact(const char* name, const char* phoneNum, const char* address) : name(NULL), phoneNum(NULL), address(NULL)
	{
		setName(name);
		setPhoneNum(phoneNum);
		setAddress(address);
	}

	Contact::~Contact()
	{
		delete []name;
		delete []phoneNum;
		delete []address;
	}

	void Contact::setName(const char* name)
	{
		delete[] this->name;
		this->name = strdup(name);
	}

	void Contact::setPhoneNum(const char* phoneNum)
	{
		delete[] this->phoneNum;
		this->phoneNum = strdup(phoneNum);
	}

	void Contact::setAddress(const char* address)
	{
		delete[] this->address;
		this->address = strdup(address);
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
		os << "Name: " << contact.getName() << ", Phone number: " << contact.getPhoneNum() << ", Address: " << contact.getAddress() << endl;
		contact.toOs(os);
		return os;
	}

	istream& operator>>(istream& in, Contact& contact)
	{
		in >> contact.name >> contact.phoneNum >> contact.address;
		return in;
	}

