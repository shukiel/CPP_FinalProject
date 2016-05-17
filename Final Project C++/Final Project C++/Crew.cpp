#include "Crew.h"
#include <time.h>

istream& operator>>(istream& in, Crew& crew)
{
	in >> (Employee&) crew;

	cout << "Please insert the crew's num of beers drank: ";
	in >> crew.m_numOfBeersDrank;

	return in;
}

void Crew::toOs(ostream& os) const
{
	Employee::toOs(os);
	os << "Num of beers drank: " << m_numOfBeersDrank << endl;
}

const Crew& Crew::operator+=(int num)
{
	m_numOfBeersDrank += num;
	return *this;
}

ostream& operator<<(ostream& os, Crew& crew)
{
	crew.toOs(os);
	return os;
}

void Crew::drinkBeers()
{
	if (rand() % 100 > CHANCE_TO_DRINK_BEER)
		*this += rand() % 5;
	if (m_numOfBeersDrank > MAX_NUM_OF_BEERS)
	{
		cout << "************** >>" << m_name << ": Oh shot I think I'm too drunk" << endl;
	}
}