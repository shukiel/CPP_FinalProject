#include "Musician.h"
#include <time.h>

void Musician::setInstrument(const char* instrument)
{ 
	delete []m_instrument;
	m_instrument = _strdup(instrument);
}

void Musician::toOs(ostream& os) const
{
	Participator::toOs(os);
	os << "Instrument: " << getInstrument() << endl;
}

const Musician& Musician::operator=(const Musician& other)
{
	if (this != &other)
	{
		(Participator&)(*this) = other;
		setInstrument(other.getInstrument());
	}
	return *this;
}

istream& operator>>(istream& in, Musician& musician)
{
	in >> (Participator&)musician >> musician.m_instrument;
	return in;
}

void Musician::doPartInShow() 
{
	srand(time(NULL));
	cout << getName() << " plays the " << getInstrument() << endl;
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