#ifndef __THEATERSHOW_H
#define __THEATERSHOW_H

#include "Show.h"
#include "Participator.h"

#define MAX_NUM_OF_ACTORS 20

class Actor;	//forward declaration

class TheaterShow : public Show
{
private:
	Actor**	 m_actors; 
	Crew	m_director;

public:
	TheaterShow(const Show& other, const Crew& director);
	TheaterShow(const TheaterShow& other);
	~TheaterShow();

	void setDirector(const Crew& director);

	Actor** getActors() const { return m_actors; }
	const Crew& getDirector() const { return m_director; }

	const TheaterShow& operator=(const TheaterShow& other);
	friend istream& operator>>(istream& in, TheaterShow& show);

	virtual void toOs(ostream& os) const;

	bool isShowPossible();
	void talkWithProducer();
	float getCost();
	void addActor(Actor& actor);
	void makeShow();
};

#endif