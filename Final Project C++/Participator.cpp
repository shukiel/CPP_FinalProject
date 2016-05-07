#include "Participator.h"

void Participator::setPart(const char* part)
{
	delete[] m_part;
	m_part = strdup(part);
}

void Participator::doPartInShow()
{
	cout << m_name << ": " << m_part <<endl;
}

const Participator& Participator::operator=(const Participator& other)
{
	if (this != &other)
	{
		Employee::operator=(other);
		setPart(other.m_part);
		m_egoLevel = other.getEgoLevel();
	}
	return *this;
}

void Participator::toOs(ostream& os) const
{
	Employee::toOs(os);
	os << "Ego Level : " << m_egoLevel << " | Part: " << m_part;
}

istream& operator>>(istream& in, Participator& participator)
{
	in >> (Employee&)participator >> participator.m_part >> participator.m_egoLevel;
	return in;
}