#include "TheaterShow.h"

void TheaterShow::addParticipator(Actor& actor) throw (const char*)
{
	if (m_numOfParticipant < MAX_NUM_OF_ACTORS)
	{
		actor.setNumOfWorkingHours(m_duration);  //Why is that?!
		Show::addParticipator(actor);
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

bool TheaterShow::isShowPossible() const
{//Checks if all actors dont have too high Ego Level! And if the Crew is not too drunk
	return Show::isShowPossible() && !(m_director.isTooDrunk());
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

float TheaterShow::getCost() const
{
	return Show::getCost() + m_director.calcSalary();
}