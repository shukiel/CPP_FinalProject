#include "Show.h"

Show::Show(const char* name, int duration, int loadInLoadOutTime,
	const Crew& lightingDesigner, const Crew& soundDesigner, const Crew& setDesigner,
	int ticketPrice, int numOfShows, int numOfParticipant):
	m_duration(duration), m_loadInLoadOutTime(loadInLoadOutTime), m_lightingDesigner(lightingDesigner), 
	m_soundDesigner(soundDesigner), m_setDesigner(setDesigner), m_ticketPrice(ticketPrice), m_numOfShows(numOfShows),
	m_numOfParticipant(numOfParticipant)
{
	m_name = _strdup(name);
}

Show::Show(const Show& other) : m_lightingDesigner(other.getLightingDesigner()),
		m_setDesigner(other.m_setDesigner), m_soundDesigner(other.m_soundDesigner),
		m_duration(other.m_duration), m_loadInLoadOutTime(other.m_loadInLoadOutTime),
		m_ticketPrice(other.m_ticketPrice), m_numOfParticipant(other.m_numOfParticipant),
		m_numOfShows(other.m_numOfShows)
{
	m_name = _strdup(other.m_name);
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
		setNumOfParticipant(other.m_numOfParticipant);
	}
	return *this;
}

ostream& operator<<(ostream& os, const Show& show)
{
	os << "Show Name : " << show.m_name << " | Duration : " << show.m_duration;
	show.toOs(os);
	return os;
}

istream& operator>>(istream& in, Show& show)
{
	in >> show.m_name >> show.m_duration >> show.m_loadInLoadOutTime 
		>> (Crew&)show.m_lightingDesigner >> (Crew&)show.m_soundDesigner >> (Crew&)show.m_setDesigner 
		>> show.m_ticketPrice >> show.getNumOfShows >> show.m_numOfParticipant;
	return in;
}	
