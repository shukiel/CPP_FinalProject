#ifndef __DANCESHOW_H
#define __DANCESHOW_H

#include "Dancer.h"
#include "Show.h"

#define MAX_NUM_OF_DANCERS 20 

class DanceShow : public virtual Show
{
private:
	//Dancer** m_dancers; 
	Crew m_choreograph;

public:
	DanceShow(const Show& other, const Crew& choreograph) : Show(other), m_choreograph(choreograph) { }
	//DanceShow(const DanceShow& other);
	//virtual ~DanceShow() { delete []m_dancers; }

	void setChoreograph(const Crew& choreograph) { m_choreograph = choreograph; }

	//const Dancer** getDancers() const { return m_dancers; }
	const Crew& getChoreograph() const { return m_choreograph; }

	//const DanceShow& operator=(const DanceShow& other);
	//friend ostream& operator<<(ostream& os, const DanceShow& show);
	friend istream& operator>>(istream& in, DanceShow& show);

	//float getAllSalaries()	const;

	virtual void toOs(ostream& os) const;
	virtual void addParticipator(Dancer& dancer);

	virtual void makeShow()			const;
	virtual bool isShowPossible()	const;
	virtual void talkWithProducer();

	void dancerInjured(Dancer& dancer); 
};

#endif