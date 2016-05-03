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

	void Contact::setName(const char* name)
	{
		delete[] m_name;
		m_name = strdup(name);
	}

	void Contact::setPhoneNum(const char* phoneNum)
	{
		delete[] m_phoneNum;
		m_phoneNum = strdup(phoneNum);
	}

	void Contact::setAddress(const char* address)
	{
		delete[] m_address;
		m_address = strdup(address);
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
		in >> contact.m_name >> contact.m_phoneNum >> contact.m_address;
		return in;
	}