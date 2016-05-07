#ifndef __THEATERSHOW_H
#define __THEATERSHOW_H

#include "Show.h"
#include "Participator.h"
class Actor;	//forward declaration

class TheaterShow : public Show
{
private:
	Actor**	 m_actors; 
	Crew	m_director;

	const int MAX_NUM_OF_ACTORS = 20;

public:
	TheaterShow(const Show& other, const Crew& director);
	TheaterShow(const TheaterShow& other);
	~TheaterShow();

	void setDirector(const Crew& director);

	const Actor** getActors() const { return m_actors; }
	const Crew& getDirector() const { return m_director; }

	const TheaterShow& operator=(const TheaterShow& other);
	friend ostream& operator<<(ostream& os, const TheaterShow& show);
	friend istream& operator>>(istream& in, TheaterShow& show);

	bool isShowPossible();
	void talkWithProducer();
	float getCost();
	void addActor(Actor& actor);
	void makeShow();
};

#endif