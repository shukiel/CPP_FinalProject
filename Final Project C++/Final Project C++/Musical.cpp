#include "Musical.h"

istream& operator>>(istream& in, Musical& show)
{
	in >> (MusicShow&)show >> (Crew&)show.m_choreograph >> (Crew&)show.m_director;
	return in;
}

void Musical::toOs(ostream& os) const
{
	MusicShow::toOs(os);
	os << "Choregraph: " << getChoreograph() << endl;
	os << "Director: " << getDirector() << endl;
}

void Musical::addParticipator(Participator& participator)
{
	if (typeid(participator) == typeid(Dancer))
		DanceShow::addParticipator(participator);

	else if (typeid(participator) == typeid(Musician))
		MusicShow::addParticipator(participator);

	else
		TheaterShow::addParticipator(participator);
}

void Musical::talkWithProducer()
{
	DanceShow::talkWithProducer();
	m_musicalManager.soberUp();
	m_director.soberUp();
}

void Musical::loadInTime()
{
	DanceShow::loadInTime();
	m_musicalManager.drinkBeers();
	m_director.drinkBeers();
}

void Musical::makeShow()
{
	DanceShow::makeShow();
	m_director.setNumOfWorkingHours(m_director.getNumOfWorkingHours() + m_duration);
	m_choreograph.setNumOfWorkingHours(m_choreograph.getNumOfWorkingHours() + m_duration);
}