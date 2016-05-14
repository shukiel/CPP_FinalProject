#include "Actor.h"
#include <time.h>

void Actor::setLine(const char* line)
{
	delete []m_line;
	m_line = _strdup(line);
}

const Actor& Actor::operator=(const Actor& other)
{
	if (this != &other)
	{
		(Participator&)(*this) = other;
		setLine(other.getLine());
	}
	return *this;
}

istream& operator>>(istream& in, Actor& actor)
{
	in >> (Participator&)actor >> actor.m_line;
	return in;
}

void Actor::makeDrama()
{
	cout << m_name << " :" << " PFFFF! I can't work like this !";
	m_egoLevel += ADDITION_TO_EGO;
}

void Actor::doPartInShow() 
{
	srand((unsigned int) time(NULL));
	cout << getName() << ": " << getLine() << endl;
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