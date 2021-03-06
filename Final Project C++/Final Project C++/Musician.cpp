#include "Musician.h"

void Musician::toOs(ostream& os) const
{
	Participator::toOs(os);
	os << "Instrument: " << getInstrument() << endl;
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
	Participator::doPartInShow();
	cout << "plays the " << getInstrument() << endl;
	if (rand() % 100 < CHANCE_TO_SOLO)
		makeSolo();
}

void Musician::makeSolo()
{
	cout << m_name << ": Is making a maginificant solo on his " << m_instrument << endl;
	m_egoLevel += ADDITION_TO_EGO;
	if (m_egoLevel > EGO_TRESHOLD)
	{
		cout << m_name << ": YOU KNOW WHAT?!? I'M TOO GOOD FOR THIS GIG!" << endl;;
	}
}