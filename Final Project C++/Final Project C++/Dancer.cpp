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
	Participator::doPartInShow();
	cout <<  "**dancing**..." << endl;
	if (rand() % 100  < CHANCE_TO_ACROBATICS)
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
	if (rand() % 100 < CHANCE_TO_INJURE)
		makeInjury();
	else
		m_egoLevel += ADDITION_TO_EGO;

	if (m_egoLevel > EGO_TRESHOLD)
		cout << m_name << ": This show is so boring! I'M GOING HOME!" << endl;
}

bool Dancer::isCanPerform() const
{
	if (m_isInjured)
	{
		cout << m_name << "- is injured!" << endl;
		return false;
	}
	return Participator::isCanPerform();
}