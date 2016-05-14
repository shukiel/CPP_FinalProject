#include "Dancer.h"
#include <time.h>

istream& operator>>(istream& in, Dancer& dancer)
{
	int inj;
	in >> (Participator&)dancer >> inj;
	dancer.setIsInjured(inj);
	return in;
}

void Dancer::doPartInShow()
{
	srand(time(NULL));
	cout << getName() << ": **dancing**..." << endl;
	if (rand() > CHANCE_TO_ACROBATICS)
	{
		makeAcrobatics();
	}
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

void Dancer::makeAcrobatics()
{
	cout << m_name << "Making Acrobatics !" <<endl;
	if (rand() > CHANCE_TO_INJURE)
	{
		setIsInjured(true);
	}
	else
	{
		m_egoLevel += ADDITION_TO_EGO;
	}
}