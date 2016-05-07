#include "Musician.h"

void Musician::setInstrument(const char* instrument)
{ 
	delete []m_instrument;
	m_instrument = strdup(instrument);
}

void Musician::toOs(ostream& os) const
{
	Participator::toOs(os);
	os << "Instrument: " << getInstrument() << endl;
}