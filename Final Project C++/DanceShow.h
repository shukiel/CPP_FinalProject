#ifndef __DANCESHOW_H
#define __DANCESHOW_H

#include "Dancer.h"
#include "Show.h"

class DanceShow : public Show
{
private:
	//Dancer** m_dancers; 
	Crew m_choreograph;

public:
	DanceShow(const Show& other, const Dancer& choreograph);
	//DanceShow(const DanceShow& other);
	//virtual ~DanceShow() { delete []m_dancers; }

	void setChoreograph(const Dancer& choreograph);

	//const Dancer** getDancers() const { return m_dancers; }
	const Crew& getChoreograph() const { return m_choreograph; }

	const DanceShow& operator=(const DanceShow& other);
	//friend ostream& operator<<(ostream& os, const DanceShow& show);
	friend istream& operator>>(istream& in, DanceShow& show);

	void dancerInjured(const Dancer& dancer); 

	//float getAllSalaries()	const;

	virtual void toOs(ostream& os) const;
	virtual void addParticipator(Actor& actor);

	virtual void makeShow()			const;
	virtual bool isShowPossible()	const;
	virtual void talkWithProducer();
};

#endif