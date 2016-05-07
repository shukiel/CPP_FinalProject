#ifndef __MUSICAL_H
#define __MUSICAL_H

#include "DanceShow.h"
#include "MusicShow.h"
#include "TheaterShow.h"

class Musical : public DanceShow, MusicShow, TheaterShow
{
public:
	Musical(char* name, int duration, int loadInLoadOutTime, 
		 Crew lightingDesigner, Crew soundDesigner, Crew setDesigner, 
		 int ticketPrice, int numOfShows, int numOfParticipant,
		 Crew director, Crew musicalManger, int soundCheckTime, Crew choreograph, 
		 Participator* musicians, Actor* actors, Dancer* dancers);
	Musical(const Musical& other);


	void makeShow();
	bool isShowPossible();
	void talkWithProducer();
	float getCost();



	const Musical& operator=(const Musical& other);
	friend ostream& operator<<(ostream& os, const Musical& show);
	friend istream& operator>>(istream& in, Musical& show);
};
#endif