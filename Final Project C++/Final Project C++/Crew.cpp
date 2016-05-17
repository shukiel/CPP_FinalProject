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

void Crew::drinkBeers()
{
	srand((unsigned int) time(NULL));
	if (rand() > CHANCE_TO_DRINK_BEER)
		*this += (rand() % MAX_NUM_OF_BEERS) + 1;
}