#include "Show.h"
#include <string>

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
	m_name = _strdup(m_name);
}

Show::~Show()
{
	delete[] m_name;
}

void addPerformance();

void Show::setLightingDesigner(const Crew& lightingDesigner)
{
	m_lightingDesigner = lightingDesigner;
}
void Show::setSoundDesigner(const Crew& soundDesigner)
{
	m_soundDesigner = soundDesigner;
}
void Show::setSetDesigner(const Crew& setDesigner)
{
	m_setDesigner = setDesigner;
}


const Show& Show::operator=(const Show& other)  //TODO::
{
	if (this != &other)
	{
	}
}

bool Show::operator==(const Show& other) const
{	//Assuming there is no such things as two shows with same name and duration
	return (strcmp(m_name, other.m_name) && (m_duration == other.m_duration));
}
bool Show::operator!=(const Show& other) const
{
	return (!(*this == other));	//I don't understand why it doesent work :(
}

ostream& operator<<(ostream& os, const Show& show)
{
	os << "Show Name : " << show.m_name << " | Duration : " << show.m_duration;
	return os;
}

istream& operator>>(istream& in, Show& show)
{
	in >> show.m_name >> show.m_duration >> show.m_loadInLoadOutTime 
		>> show.m_lightingDesigner >> show.m_soundDesigner >> show.m_setDesigner 
		>> show.m_ticketPrice >> show.getNumOfShows >> show.m_numOfParticipant;
	return in;
}	
