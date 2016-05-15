#include "Musician.h"
#include <time.h>

void Musician::toOs(ostream& os) const
{
	Participator::toOs(os);
	os << "Instrument: " << getInstrument() << endl;
}

const Musician& Musician::operator=(const Musician& other)
{
	if (this != &other)
	{
		Participator::operator=(other);
		setInstrument(other.getInstrument());
	}
	return *this;
}

istream& operator>>(istream& in, Musician& musician)
{
	char temp[50];

	in >> (Participator&)musician;
	
	cout << "Please insert the musician's instrument: ";
	in.ignore();
	in.getline(temp, 25);
	musician.setInstrument(temp);

	return in;
}

void Musician::doPartInShow() 
{
	srand((unsigned int) time(NULL));
	Participator::doPartInShow();
	cout << "plays the " << getInstrument() << endl;
	if (rand() > CHANCE_TO_SOLO)
	{
		makeSolo();
	}
}

void Musician::makeSolo()
{
	cout << m_name << ": Is making a maginificant solo on his " << m_instrument << endl;
	m_egoLevel += ADDITION_TO_EGO;
}