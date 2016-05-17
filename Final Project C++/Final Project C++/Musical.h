#ifndef __MUSICAL_H
#define __MUSICAL_H

#include "DanceShow.h"
#include "MusicShow.h"
#include "TheaterShow.h"

class Musical : public DanceShow, MusicShow, TheaterShow
{
public:
	Musical(const Show& show, const Crew& director, const Crew& choreograph, const Crew& musicalManager, int soundCheckTime) 
		: Show(show), DanceShow(show, choreograph), TheaterShow(show, director), MusicShow(show, musicalManager, soundCheckTime) { }

	friend istream& operator>>(istream& in, Musical& show);

	virtual void toOs(ostream& os)	const;
	virtual bool isShowPossible()	const 
		{ return DanceShow::isShowPossible() && !(m_musicalManager.isTooDrunk()) && !(m_director.isTooDrunk()); }
	virtual int getCost()			const 
		{	return TheaterShow::getCost() + m_choreograph.calcSalary() + m_musicalManager.calcSalary(); }

	virtual void addParticipator(Participator& participator);
	virtual void talkWithProducer();
	virtual void loadInTime();
	virtual void makeShow();
};
#endif