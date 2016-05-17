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
	TheaterShow(const Show& other, const Crew& director) : Show(other), m_director(director) 
		{ m_director.setNumOfWorkingHours(m_loadInLoadOutTime + m_duration); }

	void setDirector(const Crew& director) { m_director = director; }

	const Crew& getDirector() const { return m_director; }

	friend istream& operator>>(istream& in, TheaterShow& show);

	virtual void toOs(ostream& os)	const;
	virtual bool isShowPossible()	const { return Show::isShowPossible() && !(m_director.isTooDrunk()); }
	virtual float getCost()			const {	return Show::getCost() + m_director.calcSalary(); }

	virtual void addParticipator(Participator& participator);
	virtual void talkWithProducer();
	virtual void loadInTime();
};

#endif