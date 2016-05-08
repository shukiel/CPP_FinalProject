#ifndef __THEATERSHOW_H
#define __THEATERSHOW_H

#include "Show.h"
#include "Actor.h"

#define MAX_NUM_OF_ACTORS 20

class TheaterShow : public virtual Show
{
private:
	//Actor**	 m_actors; 
	Crew	m_director;

public:
	TheaterShow(const Show& other, const Crew& director) : Show(other), m_director(director) { }
	//TheaterShow(const TheaterShow& other);
	//~TheaterShow();

	void setDirector(const Crew& director) { m_director = director; }

	//Actor** getActors() const { return m_actors; }
	const Crew& getDirector() const { return m_director; }

	//const TheaterShow& operator=(const TheaterShow& other);
	friend istream& operator>>(istream& in, TheaterShow& show);

	virtual void addParticipator(Actor& actor);
	virtual void talkWithProducer();

	virtual void toOs(ostream& os)	const;
	virtual void makeShow()			const;
	virtual bool isShowPossible()	const;
};

#endif