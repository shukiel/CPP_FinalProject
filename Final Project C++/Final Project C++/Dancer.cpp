#include "Dancer.h"
#include <time.h>

istream& operator>>(istream& in, Dancer& dancer)
{
	in >> (Participator&)dancer;
	dancer.setIsInjured(false);

	return in;
}

void Dancer::doPartInShow()
{
	srand((unsigned int) time(NULL));
	Participator::doPartInShow();
	cout <<  "**dancing**..." << endl;
	if (rand() > CHANCE_TO_ACROBATICS)
		makeAcrobatics();
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
	cout << m_name << " Making Acrobatics !" <<endl;
	if (rand() < CHANCE_TO_INJURE)
		makeInjury();
	else
		m_egoLevel += ADDITION_TO_EGO;
}