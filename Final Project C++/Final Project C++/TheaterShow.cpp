#include "TheaterShow.h"

void TheaterShow::addParticipator(Participator& participator) throw (GenericException)
{
	if (m_participators.size() < MAX_NUM_OF_ACTORS)
	{
		if (typeid(participator) == typeid(Actor))
			Show::addParticipator(participator);

		else
			throw GenericException("The participant is not an actor.");
	}

	else
		throw GenericException("No more room for this actor :(");
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

void TheaterShow::makeShow()
{
	loadInTime();
	Show::makeShow();
	m_director.setNumOfWorkingHours(m_director.getNumOfWorkingHours() + m_duration);
}

void TheaterShow::loadInTime()
{
	Show::loadInTime();
	m_director.drinkBeers();
}