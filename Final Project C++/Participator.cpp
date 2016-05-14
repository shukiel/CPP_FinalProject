#include "Participator.h"

void Participator::toOs(ostream& os) const
{
	Employee::toOs(os);
	os << "Ego Level : " << m_egoLevel << endl;
}

istream& operator>>(istream& in, Participator& participator)
{
	in >> (Employee&)participator;

	cout << "Please insert the participator's ego level: ";
	in >> participator.m_egoLevel;

	return in;
}