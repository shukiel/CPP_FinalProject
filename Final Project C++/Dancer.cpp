#include "Dancer.h"

istream& operator>>(istream& in, Dancer& dancer)
{
	int inj;
	in >> (Participator&)dancer >> inj;
	dancer.setIsInjured(inj);
	return in;
}

void Dancer::doPartInShow() const
{
	cout << getName() << " dancing..." << endl;
}

void Dancer::toOs(ostream& os) const
{
	Participator::toOs(os);
	os << "Is injures? ";
	if(m_isInjured)
		os << "True." << endl;
	else
		os << "False." << endl;
}