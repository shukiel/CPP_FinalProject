#include "Participator.h"


Participator::Participator(const Employee& other, const char* part, int egoLevel) : Employee(other), m_egoLevel(egoLevel)
{
	this->m_part = _strdup(part);
}
Participator::Participator(const Participator& other) :
		Employee(other),
		m_egoLevel(other.m_egoLevel)
{
	this->m_part = _strdup(other.m_part);
}
Participator::~Participator()
{
	delete[] m_part;
}

void Participator::setPart(const char* part) { this->m_part = _strdup(part); }

void Participator::doPartInShow()
{
	cout << m_name << ": " << m_part <<endl;
}

const Participator& Participator::operator=(const Participator& other)
{
	if (this != &other)
	{
		Employee::operator=(other);
		this->m_part = _strdup(other.m_part);
		this->m_egoLevel = other.getEgoLevel();
	}
	return *this;
}

void Participator::toOs(ostream& os) const
{
	Employee::toOs(os);
	os << "Ego Level : " << m_egoLevel << " | Part: " << m_part;
}

ostream& operator<<(ostream& os, const Participator& participator)
{
	participator.toOs(os);
	return os;
}

istream& operator>>(istream& in, Participator& participator)
{
	return in;
}