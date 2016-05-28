#include "DanceShow.h"
#include "Exceptions.h"

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

void DanceShow::addParticipator(Participator& participator) throw (GenericException)
{
	if (m_participators.size() < MAX_NUM_OF_DANCERS)
	{
		if (typeid(participator) == typeid(Dancer))
			Show::addParticipator(participator);

		else
			throw GenericException ("The participant is not a dancer.");
	}

	else
		throw GenericException("No more room for this dancer :(");
}

void DanceShow::talkWithProducer()
{
	Show::talkWithProducer();
	m_choreograph.soberUp();
}

void DanceShow::dancerInjured(Dancer& dancer)
{
	vector<Participator*>::iterator it = m_participators.begin();
	vector<Participator*>::iterator itEnd = m_participators.end();
	for (; it != itEnd; ++it)
	{
		Dancer* temp = dynamic_cast<Dancer*>(*it);
		if(temp)
			if(*temp == dancer)
				temp->makeInjury();
	}
}

void DanceShow::makeShow()
{
	loadInTime();
	Show::makeShow();
	m_choreograph.setNumOfWorkingHours(m_choreograph.getNumOfWorkingHours() + m_duration);
}

void DanceShow::loadInTime()
{
	Show::loadInTime();
	m_choreograph.drinkBeers();
	vector<Participator*>::iterator it = m_participators.begin();
	vector<Participator*>::iterator itEnd = m_participators.end();
	for (; it != itEnd; ++it)
	{
		Dancer* temp = dynamic_cast<Dancer*>(*it);
		if (temp)
			if (temp->getIsInjured())
				if (rand() % 100 < temp->CHANCE_TO_RECOVER)
					temp->recover();
	}
}