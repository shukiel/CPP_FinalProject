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
	Dancer* tempD = dynamic_cast<Dancer*>(&participator);
	if(tempD)
	{
		DanceShow::addParticipator(*tempD);
		return;
	}

	Musician* tempM = dynamic_cast<Musician*>(&participator);
	if(tempM)
	{
		MusicShow::addParticipator(*tempM);
		return;
	}

	Actor* tempA = dynamic_cast<Actor*>(&participator);
	if(tempA)
		TheaterShow::addParticipator(*tempA);
}

bool Musical::isShowPossible() const
{
	return DanceShow::isShowPossible() && !(m_musicalManager.isTooDrunk()) && !(m_director.isTooDrunk());
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