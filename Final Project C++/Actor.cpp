#include "Actor.h"

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

}

void Actor::doPartInShow() const
{
	cout << getName() << ": " << getLine() << endl;
}

void Actor::toOs(ostream& os) const
{
	Participator::toOs(os);
	os << "Line: " << m_line << endl;
}