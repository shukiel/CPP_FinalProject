#include "Crew.h"

istream& operator>>(istream& in, Crew& crew)
{
	in >> (Employee&) crew >> crew.m_numOfBeersDrank;
	return in;
}

void Crew::toOs(ostream& os) const
{
	Employee::toOs(os);
	os << "Num of beers drank: " << m_numOfBeersDrank << endl;
}