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
}

void Actor::doPartInShow() 
{
	srand((unsigned int) time(NULL));
	Participator::doPartInShow();
	cout << getLine() << endl;
	if (rand() > CHANCE_TO_DRAMA)
	{
		this->makeDrama();
	}
}

void Actor::toOs(ostream& os) const
{
	Participator::toOs(os);
	os << "Line: " << m_line << endl;
}