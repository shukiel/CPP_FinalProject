#ifndef __SHOW_H
#define __SHOW_H

#include "Crew.h"

class Show
{
private:
	char*	m_name;
	int		m_duration;
	int		m_loadInLoadOutTime;
	Crew	m_lightingDesigner;
	Crew	m_soundDesigner;
	Crew	m_setDesigner;
	int		m_ticketPrice;
	int		m_numOfShows;
	int		m_numOfParticipant;

public:
	Show(const char* name, int duration, int loadInLoadOutTime, 
		 const Crew& lightingDesigner, const Crew& soundDesigner, const Crew& setDesigner, 
		 int ticketPrice, int numOfShows, int numOfParticipant);
	Show(const Show& other);
	~Show();

	virtual void makeShow() const			=0;
	virtual float getAllSalaries() const	=0;
	virtual bool isShowPossible() const		=0;
	virtual void talkWithProducer() const	=0;

	void addPerformance();


	void setDuration(int duration) { this->m_duration = duration; }
	void setLoadInLoadOutTime(int loadInLoadOutTime) { this->m_loadInLoadOutTime = loadInLoadOutTime; }
	void setLightingDesigner(const Crew& lightingDesigner);
	void setSoundDesigner(const Crew& soundDesigner);
	void setSetDesigner(const Crew& setDesigner);
	void setTicketPrice(int ticketPrice) { this->m_ticketPrice = ticketPrice; }
	void setNumOfShows(int numOfShows) { this->m_numOfShows = numOfShows; }
	void setNumOfParticipant(int numOfParticipant) { this->m_numOfParticipant = numOfParticipant; }

	const char* getName() const { return m_name; }
	int getDuration() const { return m_duration; }
	int getLoadInLoadOutTime() const { return m_loadInLoadOutTime; }
	const Crew& getLightingDesigner() const { return m_lightingDesigner; }
	const Crew& getSoundDesigner() const { return m_soundDesigner; }
	const Crew& getSetDesigner() const { return m_setDesigner; }
	int getTicketPrice() const { return m_ticketPrice; }
	int getNumOfShows() const { return m_numOfShows; }
	int getNumOfParticipant() const { return m_numOfParticipant; }

	const Show& operator=(const Show& other);
	bool operator==(const Show& other) const;
	bool operator!=(const Show& other) const;
	friend ostream& operator<<(ostream& os, const Show& show);
	friend istream& operator>>(istream& in, Show& show);

	
};

#endif