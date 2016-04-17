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
	Show(char* name, int duration, int loadInLoadOutTime, 
		 Crew lightingDesigner, Crew soundDesigner, Crew setDesigner, 
		 int ticketPrice, int numOfShows, int numOfParticipant);
	Show(const Show& other);
	~Show();

	void setDuration(int duration);
	void setLoadInLoadOutTime(int loadInLoadOutTime);
	void setLightingDesigner(Crew lightingDesigner);
	void setSoundDesigner(Crew soundDesigner);
	void setSetDesigner(Crew setDesigner);
	void setTicketPrice(int ticketPrice);
	void setNumOfShows(int numOfShows);
	void setNumOfParticipant(int numOfParticipant);

	const char* getName() const {return name;}
	const int getDuration() const {return duration;}
	const int getLoadInLoadOutTime() const {return loadInLoadOutTime;}
	const Crew getLightingDesigner() const {return lightingDesigner;}
	const Crew getSoundDesigner() const {return soundDesigner;}
	const Crew getSetDesigner() const {return setDesigner;}
	const int getTicketPrice() const {return ticketPrice;}
	const int getNumOfShows() const {return numOfShows;}
	const int getNumOfParticipant() const {return numOfParticipant;}

	void show() const;

	const Show& operator=(const Show& other);
	bool operator==(const Show& other) const;
	bool operator!=(const Show& other) const;
	friend ostream& operator<<(ostream& os, const Show& show);
	friend istream& operator>>(istream& in, Show& show);

	const float getAllSalaries() const;
	void addPerformance();
	const void makeShow();
	const bool isShowPossible () const;
	const void talkWithProducer();
};

#endif