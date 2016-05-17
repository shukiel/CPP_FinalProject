#ifndef __THEATERSHOW_H
#define __THEATERSHOW_H

#include "Show.h"
#include "Actor.h"

#define MAX_NUM_OF_ACTORS 20

class TheaterShow : public virtual Show
{
protected: 
	Crew	m_director;

public:
	TheaterShow(const Show& other, const Crew& director) : Show(other), m_director(director) { }

	void setDirector(const Crew& director) { m_director = director; }

	const Crew& getDirector() const { return m_director; }

	friend istream& operator>>(istream& in, TheaterShow& show);

	virtual void addParticipator(Actor& actor);
	virtual void talkWithProducer();
	virtual void loadInTime();

	virtual void toOs(ostream& os)	const;
	virtual bool isShowPossible()	const;
};

#endif