#include "Participator.h"

void Participator::toOs(ostream& os) const
{
	Employee::toOs(os);
	os << "Ego Level : " << m_egoLevel;
}

istream& operator>>(istream& in, Participator& participator)
{
	in >> (Employee&)participator >> participator.m_egoLevel;
	return in;
}