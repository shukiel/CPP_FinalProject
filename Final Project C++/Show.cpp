#include "Show.h"

Show::Show(const char* name, int duration, int loadInLoadOutTime,
	const Crew& lightingDesigner, const Crew& soundDesigner, const Crew& setDesigner,
	int ticketPrice, int numOfShows):
	m_duration(duration), m_loadInLoadOutTime(loadInLoadOutTime), m_lightingDesigner(lightingDesigner), 
	m_soundDesigner(soundDesigner), m_setDesigner(setDesigner), m_ticketPrice(ticketPrice), m_numOfShows(numOfShows)
{
	m_name = _strdup(name);
	m_numOfParticipant = 0;
	m_participators = new Participator*[MAX_NUM_OF_PARTICIPATORS];
	m_lightingDesigner.setNumOfWorkingHours(m_loadInLoadOutTime + m_duration);
	m_setDesigner.setNumOfWorkingHours(m_loadInLoadOutTime);
	m_soundDesigner.setNumOfWorkingHours(m_loadInLoadOutTime + m_duration);
}

Show::Show(const Show& other) : m_lightingDesigner(other.getLightingDesigner()),
		m_setDesigner(other.m_setDesigner), m_soundDesigner(other.m_soundDesigner),
		m_duration(other.m_duration), m_loadInLoadOutTime(other.m_loadInLoadOutTime),
		m_ticketPrice(other.m_ticketPrice), m_numOfShows(other.m_numOfShows)
{
	m_name = _strdup(other.m_name);
	m_numOfParticipant = 0;
	m_participators = new Participator*[MAX_NUM_OF_PARTICIPATORS];
	if(other.getNumOfParticipant() > 0)
	{
		Participator** temp = other.getParticipators();
		for(int i = 0; i < other.getNumOfParticipant(); i++)
			addParticipator(*temp[i]);
	}
	m_lightingDesigner.setNumOfWorkingHours(m_loadInLoadOutTime + m_duration);
	m_setDesigner.setNumOfWorkingHours(m_loadInLoadOutTime);
	m_soundDesigner.setNumOfWorkingHours(m_loadInLoadOutTime + m_duration);
}

float Show::getCost() const
{
	float sum = 0;
	sum += m_lightingDesigner.calcSalary();
	sum += m_setDesigner.calcSalary();
	sum += m_soundDesigner.calcSalary();
	for(int i = 0; i < getNumOfParticipant(); i++)
		sum += m_participators[i]->calcSalary();
	return sum;
}

const Show& Show::operator=(const Show& other)
{
	if (this != &other)
	{
		delete []m_name;
		m_name = _strdup(other.m_name);
		setDuration(other.m_duration);
		setLoadInLoadOutTime(other.m_loadInLoadOutTime);
		setLightingDesigner(other.m_lightingDesigner);
		setSoundDesigner(other.m_soundDesigner);
		setSetDesigner(other.m_setDesigner);
		setTicketPrice(other.m_ticketPrice);
		setNumOfShows(other.m_numOfShows);
		m_numOfParticipant = 0;
		m_participators = new Participator*[MAX_NUM_OF_PARTICIPATORS];
		if(other.getNumOfParticipant() > 0)
		{
			Participator** temp = other.getParticipators();
			for(int i = 0; i < other.getNumOfParticipant(); i++)
				addParticipator(*temp[i]);
		}
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
	os << "Show Name : " << m_name << " | Duration : " << m_duration;
}

void Show::addParticipator(Participator& participator)
{
	if(m_numOfParticipant < MAX_NUM_OF_PARTICIPATORS)
	{
		m_participators[m_numOfParticipant] = &participator;
		m_numOfParticipant++;
	}
	else
		cout << "No more room for this participator." << endl;
}
