#ifndef __DANCESHOW_H
#define __DANCESHOW_H

#include "Dancer.h"
#include "Show.h"

#define MAX_NUM_OF_DANCERS 20 

class DanceShow : public virtual Show
{
protected: 
	Crew m_choreograph;

public:
	DanceShow(const Show& other, const Crew& choreograph) : Show(other), m_choreograph(choreograph)
		{ m_choreograph.setNumOfWorkingHours(m_duration + m_loadInLoadOutTime); }

	void setChoreograph(const Crew& choreograph) { m_choreograph = choreograph; }

	const Crew& getChoreograph() const { return m_choreograph; }

	friend istream& operator>>(istream& in, DanceShow& show);

	virtual void toOs(ostream& os)	const;
	virtual bool isShowPossible()	const { return Show::isShowPossible() && !(m_choreograph.isTooDrunk()); }
	virtual float getCost()			const {	return Show::getCost() + m_choreograph.calcSalary(); }

	virtual void addParticipator(Participator& participator);
	virtual void loadInTime();
	virtual void talkWithProducer();

	void dancerInjured(Dancer& dancer); 
};

#endif