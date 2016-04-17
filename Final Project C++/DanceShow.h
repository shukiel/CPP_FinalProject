#ifndef __DANCESHOW_H
#define __DANCESHOW_H

#include "Show.h"
#include "Participator.h"

class DanceShow : public Show
{
private:
	Participator* dancers; 
	Participator choreograph;

public:
	DanceShow(char* name, int duration, int loadInLoadOutTime, 
		 Crew lightingDesigner, Crew soundDesigner, Crew setDesigner, 
		 int ticketPrice, int numOfShows, int numOfParticipant,
		 Participator choreograph, Participator* dancers = NULL);
	DanceShow(const DanceShow& other);
	~DanceShow();

	void setChoreograph(Participator choreograph);

	const Participator* getDancers() const {return dancers;}
	const Participator getChoreograph() const {return choreograph;}
	
	void show() const;

	const DanceShow& operator=(const DanceShow& other);
	friend ostream& operator<<(ostream& os, const DanceShow& show);
	friend istream& operator>>(istream& in, DanceShow& show);

	const void makeShow();
	void dancerInjured(Participator dancer); 
};

#endif