#ifndef __THEATERSHOW_H
#define __THEATERSHOW_H

#include "Show.h"
#include "Participator.h"

class TheaterShow : public Show
{
private:
	Participator* actors; 
	Crew director;

public:
	TheaterShow(char* name, int duration, int loadInLoadOutTime, 
		 Crew lightingDesigner, Crew soundDesigner, Crew setDesigner, 
		 int ticketPrice, int numOfShows, int numOfParticipant,
		 Crew director, Participator* actors = NULL);
	TheaterShow(const TheaterShow& other);
	~TheaterShow();

	void setDirector(Crew director);

	const Participator* getActors() const {return actors;}
	const Crew getDirector() const {return director;}

	void show() const;

	const TheaterShow& operator=(const TheaterShow& other);
	friend ostream& operator<<(ostream& os, const TheaterShow& show);
	friend istream& operator>>(istream& in, TheaterShow& show);

	const void makeShow();
	const void makeDrama();
};

#endif