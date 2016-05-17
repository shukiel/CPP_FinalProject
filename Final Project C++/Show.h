#ifndef __SHOW_H
#define __SHOW_H

#include "Participator.h"
#include "Crew.h"

#pragma warning( disable : 4290 )

#define MAX_NUM_OF_PARTICIPATORS 50

class Show
{
protected:
	char*			m_name;
	int				m_duration;
	int				m_loadInLoadOutTime;
	Crew			m_lightingDesigner;
	Crew			m_soundDesigner;
	Crew			m_setDesigner;
	Participator**	m_participators;
	int				m_ticketPrice;
	int				m_numOfShows;
	int				m_numOfParticipant;

public:
	Show(const char* name, int duration, int loadInLoadOutTime, 
		 const Crew& lightingDesigner, const Crew& soundDesigner, const Crew& setDesigner, 
		 int ticketPrice, int numOfShows);
	Show(const Show& other);
	Show() { }
	virtual ~Show() { delete[] m_name; }

	void setName(const char* name)							{ m_name = _strdup(name); }
	void setDuration(int duration)							{ m_duration = duration; }
	void setLoadInLoadOutTime(int loadInLoadOutTime)		{ m_loadInLoadOutTime = loadInLoadOutTime; }
	void setLightingDesigner(const Crew& lightingDesigner)	{ m_lightingDesigner = lightingDesigner; }
	void setSoundDesigner(const Crew& soundDesigner)		{ m_soundDesigner = soundDesigner; }
	void setSetDesigner(const Crew& setDesigner)			{ m_setDesigner = setDesigner; }
	void setTicketPrice(int ticketPrice)					{ m_ticketPrice = ticketPrice; }
	void setNumOfShows(int numOfShows)						{ m_numOfShows = numOfShows; }
	void setNumOfParticipant(int numOfParticipant)			{ m_numOfParticipant = numOfParticipant; }

	const char* getName()				const { return m_name; }
	int getDuration()					const { return m_duration; }
	int getLoadInLoadOutTime()			const { return m_loadInLoadOutTime; }
	const Crew& getLightingDesigner()	const { return m_lightingDesigner; }
	const Crew& getSoundDesigner()		const { return m_soundDesigner; }
	const Crew& getSetDesigner()		const { return m_setDesigner; }
	int getTicketPrice()				const { return m_ticketPrice; }
	int getNumOfShows()					const { return m_numOfShows; }
	int getNumOfParticipant()			const { return m_numOfParticipant; }
	Participator** getParticipators()	const { return m_participators; }

	bool operator==(const Show& other)	const { return strcmp(getName(), other.getName()) == 0 && getDuration() == other.getDuration(); }
	bool operator!=(const Show& other)	const { return !(*this == other); }

	const Show& operator=(const Show& other);
	friend ostream& operator<<(ostream& os, const Show& show);
	friend istream& operator>>(istream& in, Show& show);

	virtual void talkWithProducer();
	virtual void addParticipator(Participator& participator);
	virtual void loadInTime();

	virtual bool isShowPossible()	const;
	virtual void toOs(ostream& os)	const;

	void makeShow();

	float getCost() const;
};

#endif