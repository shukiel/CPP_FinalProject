#include "DanceShow.h"

istream& operator>>(istream& in, DanceShow& show)
{
	in >> (Show&)show >> (Crew&)show.m_choreograph;
	return in;
}

void DanceShow::toOs(ostream& os) const
{
	Show::toOs(os);	
	os << "Choregraph: " << getChoreograph() << endl;
}

void DanceShow::addParticipator(Dancer& dancer)
{
	if (!(m_numOfParticipant + 1 > MAX_NUM_OF_DANCERS))
	{
		dancer.setNumOfWorkingHours(m_duration);
		Show::addParticipator(dancer);
	}
	throw "No more room for this dancer :(";
}

bool DanceShow::isShowPossible() const
{
	return Show::isShowPossible() && !(m_choreograph.isTooDrunk());
}

void DanceShow::talkWithProducer()
{
	Show::talkWithProducer();
	m_choreograph.soberUp();
}

void DanceShow::dancerInjured(Dancer& dancer)
{
	for(int i = 0; i < m_numOfParticipant; i++)
	{
		Dancer* temp = dynamic_cast<Dancer*>(m_participators[i]);
		if(temp)
			if(*temp == dancer)
				temp->makeInjury();
	}
}

void DanceShow::loadInTime()
{
	Show::loadInTime();
	m_choreograph.drinkBeers();
}