#ifndef __SHOW_H
#define __SHOW_H

#include "Crew.h"

class Show
{
private:
	char* name;
	int duration;
	int loadInLoadOutTime;
	Crew lightingDesigner;
	Crew soundDesigner;
	Crew setDesigner;
	int ticketPrice;
	int numOfShows;
	int numOfParticipant;

public:
	Show(const char* name, int duration, int loadInLoadOutTime, 
		 const Crew& lightingDesigner, const Crew& soundDesigner, const Crew& setDesigner, 
		 int ticketPrice, int numOfShows, int numOfParticipant);
	Show(const Show& other);
	~Show();

	void setDuration(int duration) { this->duration = duration; }
	void setLoadInLoadOutTime(int loadInLoadOutTime) { this->loadInLoadOutTime = loadInLoadOutTime; }
	void setLightingDesigner(const Crew& lightingDesigner);
	void setSoundDesigner(const Crew& soundDesigner);
	void setSetDesigner(const Crew& setDesigner);
	void setTicketPrice(int ticketPrice) { this->ticketPrice = ticketPrice; }
	void setNumOfShows(int numOfShows) { this->numOfShows = numOfShows; }
	void setNumOfParticipant(int numOfParticipant) { this->numOfParticipant = numOfParticipant; }

	const char* getName() const { return name; }
	int getDuration() const { return duration; }
	int getLoadInLoadOutTime() const { return loadInLoadOutTime; }
	const Crew& getLightingDesigner() const { return lightingDesigner; }
	const Crew& getSoundDesigner() const { return soundDesigner; }
	const Crew& getSetDesigner() const { return setDesigner; }
	int getTicketPrice() const { return ticketPrice; }
	int getNumOfShows() const { return numOfShows; }
	int getNumOfParticipant() const { return numOfParticipant; }

	const Show& operator=(const Show& other);
	bool operator==(const Show& other) const;
	bool operator!=(const Show& other) const;
	friend ostream& operator<<(ostream& os, const Show& show);
	friend istream& operator>>(istream& in, Show& show);

	float getAllSalaries() const;
	void addPerformance();
	void makeShow() const;
	bool isShowPossible () const;
	void talkWithProducer() const;
};

#endif