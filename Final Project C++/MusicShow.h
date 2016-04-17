#ifndef __MUSICSHOW_H
#define __MUSICSHOW_H

#include "Show.h"
#include "Participator.h"

class MusicShow : public Show
{
private:
	Participator* musicians; 
	Crew musicalManger;
	int soundCheckTime;

public:
	MusicShow(char* name, int duration, int loadInLoadOutTime, 
		 Crew lightingDesigner, Crew soundDesigner, Crew setDesigner, 
		 int ticketPrice, int numOfShows, int numOfParticipant,
		 Crew musicalManger, int soundCheckTime, Participator* musicians);
	MusicShow(const MusicShow& other);
	~MusicShow();

	void setDirector(Crew director);
	void setSoundCheckTime(int soundCheckTime);

	const Participator* getMusicians() const {return musicians;}
	const Crew getMusicalManger() const {return musicalManger;}
	const int getSoundCheckTime() const {return soundCheckTime;}

	void show() const;

	const MusicShow& operator=(const MusicShow& other);
	friend ostream& operator<<(ostream& os, const MusicShow& show);
	friend istream& operator>>(istream& in, MusicShow& show);

	const void makeShow();
	void encore();
	void drinkBeerAndSmokeCiggarettes();
};

#endif