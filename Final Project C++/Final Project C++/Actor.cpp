#include "Actor.h"
#include <time.h>

const Actor& Actor::operator=(const Actor& other)
{
	if (this != &other)
	{
		Participator::operator=(other);
		setLine(other.getLine());
	}
	return *this;
}

istream& operator>>(istream& in, Actor& actor)
{
	char temp[50];

	in >> (Participator&)actor;
	
	cout << "Please insert the actor's line: ";
	in.ignore();
	in.getline(temp, 25);
	actor.setLine(temp);

	return in;
}

void Actor::makeDrama()
{
	cout << m_name << " : PFFFF! I can't work like this !" << endl;
	m_egoLevel += ADDITION_TO_EGO;
	if (m_egoLevel > EGO_TRESHOLD)
	{
		cout << "YOU KNOW WHAT, SCREW THIS I'M GOING HOME!";
	}
}

void Actor::doPartInShow() 
{
	Participator::doPartInShow();
	cout << getLine() << endl;
	int i = rand();
	if (rand() % 100  < CHANCE_TO_DRAMA)
		makeDrama();
}

void Actor::toOs(ostream& os) const
{
	Participator::toOs(os);
	os << "Line: " << m_line << endl;
}