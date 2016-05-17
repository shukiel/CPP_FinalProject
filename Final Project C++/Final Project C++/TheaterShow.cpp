#include "TheaterShow.h"

void TheaterShow::addParticipator(Participator& participator) throw (const char*)
{
	if (m_numOfParticipant < MAX_NUM_OF_ACTORS)
	{
		if (typeid(participator) == typeid(Actor))
			Show::addParticipator(participator);

		else
			throw "The participant is not an actor.";
	}

	else
		throw "No more room for this actor :(";
}

void TheaterShow::toOs(ostream& os) const
{
	Show::toOs(os);	
	os << "Director: " << getDirector() << endl;
}

istream& operator>>(istream& in, TheaterShow& show)
{
	in >> (Show&)show >> (Crew&)show.m_director;
	return in;
}

void TheaterShow::talkWithProducer()
{//Set All Ego Back to 0 for the participator And number of beers drank to 
	Show::talkWithProducer();
	m_director.soberUp();
}

void TheaterShow::loadInTime()
{
	Show::loadInTime();
	m_director.drinkBeers();
}