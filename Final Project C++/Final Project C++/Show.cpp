#include "Show.h"
#include "Exceptions.h"
#include <algorithm>

Show::Show(const string& name, int duration, int loadInLoadOutTime,
	 Crew& lightingDesigner,  Crew& soundDesigner,  Crew& setDesigner,
	 int ticketPrice) :
	 m_duration(duration), m_loadInLoadOutTime(loadInLoadOutTime), m_lightingDesigner(lightingDesigner), 
	 m_soundDesigner(soundDesigner), m_setDesigner(setDesigner), m_ticketPrice(ticketPrice), m_name(name)
{
	m_numOfShows = 0;
	m_lightingDesigner.setNumOfWorkingHours(m_loadInLoadOutTime + m_duration);
	m_setDesigner.setNumOfWorkingHours(m_loadInLoadOutTime);
	m_soundDesigner.setNumOfWorkingHours(m_loadInLoadOutTime + m_duration);
}

Show::Show(const Show& other) : m_lightingDesigner(other.m_lightingDesigner),
		m_setDesigner(other.m_setDesigner), m_soundDesigner(other.m_soundDesigner),
		m_duration(other.m_duration), m_loadInLoadOutTime(other.m_loadInLoadOutTime),
		m_ticketPrice(other.m_ticketPrice), m_numOfShows(other.m_numOfShows), m_name(other.m_name)
{
	m_participators.reserve(other.m_participators.size());
	copy(other.m_participators.begin(), other.m_participators.end(), back_inserter(m_participators));

	m_lightingDesigner.setNumOfWorkingHours(m_loadInLoadOutTime + m_duration);
	m_setDesigner.setNumOfWorkingHours(m_loadInLoadOutTime);
	m_soundDesigner.setNumOfWorkingHours(m_loadInLoadOutTime + m_duration);
}

int Show::getCost() const
{
	int sum = 0;
	sum += m_lightingDesigner.calcSalary();
	sum += m_setDesigner.calcSalary();
	sum += m_soundDesigner.calcSalary();

	vector<Participator*>::const_iterator it = m_participators.begin();
	vector<Participator*>::const_iterator itEnd = m_participators.end();
	for (; it != itEnd; ++it)
		sum += (*it)->calcSalary();

	return sum;
}

const Show& Show::operator=(const Show& other)
{
	if (this != &other)
	{
		setName(other.m_name);
		setDuration(other.m_duration);
		setLoadInLoadOutTime(other.m_loadInLoadOutTime);
		setLightingDesigner(other.m_lightingDesigner);
		setSoundDesigner(other.m_soundDesigner);
		setSetDesigner(other.m_setDesigner);
		setTicketPrice(other.m_ticketPrice);
		setNumOfShows(other.m_numOfShows);

		m_participators.reserve(other.m_participators.size());
		copy(other.m_participators.begin(), other.m_participators.end(), back_inserter(m_participators));
	}
	return *this;
}

ostream& operator<<(ostream& os, const Show& show)
{
	show.toOs(os);
	return os;
}

istream& operator>>(istream& in, Show& show)
{
	in >> show.m_name >> show.m_duration >> show.m_loadInLoadOutTime 
		>> (Crew&)show.m_lightingDesigner >> (Crew&)show.m_soundDesigner >> (Crew&)show.m_setDesigner 
		>> show.m_ticketPrice >> show.m_numOfShows;
	return in;
}	

void Show::toOs(ostream& os) const
{
	os << "Show Name : " << m_name << " | Duration : " << m_duration << ", Load in and load out time: " << m_loadInLoadOutTime << endl;
	os << endl << "Lighting Designer: " << endl << m_lightingDesigner << endl;
	os << "Set Designer: " << endl << m_setDesigner << endl;
	os << "Sound Designer: " << endl << m_soundDesigner << endl;
	os << "Ticket price: " << m_ticketPrice << ", Num of shows: " << m_numOfShows <<" Show Cost: "<<getCost()<<endl;

	os << endl << "Participant:" << endl;
	vector<Participator*>::const_iterator it = m_participators.begin();
	vector<Participator*>::const_iterator itEnd = m_participators.end();
	for (; it != itEnd; ++it)
			os << *it << endl;
}

void Show::addParticipator(Participator& participator) throw (GenericException)
{
	if(m_participators.size() < MAX_NUM_OF_PARTICIPATORS)
	{
		participator.setNumOfWorkingHours(participator.getNumOfWorkingHours() + m_duration);
		m_participators.push_back(&participator);
	}

	else
		throw "No more room for this participator.";
}

void Show::makeShow() throw (GenericException)
{
	if (!isShowPossible())
	{
		talkWithProducer();
		throw GenericException("This Show is not possible!");
	}

	cout << "The Show " << m_name << " Is now starting please turn off your phones.\n";

	vector<Participator*>::iterator it = m_participators.begin();
	vector<Participator*>::iterator itEnd = m_participators.end();
	for (; it != itEnd; ++it)
	{
		(*it)->doPartInShow();
		(*it)->setNumOfWorkingHours((*it)->getNumOfWorkingHours() + m_duration);
	}

	m_lightingDesigner.setNumOfWorkingHours(m_lightingDesigner.getNumOfWorkingHours() + m_duration + m_loadInLoadOutTime);
	m_soundDesigner.setNumOfWorkingHours(m_soundDesigner.getNumOfWorkingHours() + m_duration + m_loadInLoadOutTime);
	m_setDesigner.setNumOfWorkingHours(m_setDesigner.getNumOfWorkingHours() + m_duration + m_loadInLoadOutTime);
	cout << "\n------------------------The End------------------------------------\n\n\n";
	m_numOfShows++;
}

bool Show::isShowPossible() const
{
	vector<Participator*>::const_iterator it = m_participators.begin();
	vector<Participator*>::const_iterator itEnd = m_participators.end();
	for (; it != itEnd; ++it)
		if (!((*it)->isCanPerform()))
			return false;
	return !(m_lightingDesigner.isTooDrunk()) && !(m_setDesigner.isTooDrunk()) && !(m_soundDesigner.isTooDrunk());
}

void Show::talkWithProducer()
{
	vector<Participator*>::iterator it = m_participators.begin();
	vector<Participator*>::iterator itEnd = m_participators.end();
	for (; it != itEnd; ++it)
		(*it)->resetEgoLevel();
	m_lightingDesigner.soberUp();
	m_setDesigner.soberUp();
	m_soundDesigner.soberUp();
}

void Show::loadInTime()
{
	m_lightingDesigner.drinkBeers();
	m_setDesigner.drinkBeers();
	m_soundDesigner.drinkBeers();
}