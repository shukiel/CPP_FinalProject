#ifndef __MUSICSHOW_H
#define __MUSICSHOW_H

#include "Show.h"
#include "Musician.h"

#define MAX_NUM_OF_MUSICIANS 20 

class MusicShow : public virtual Show
{
protected:
	Crew m_musicalManager;
	int m_soundCheckTime;

public:
	MusicShow(const Show& other, const Crew& musicalManager, int soundCheckTime) : Show(other), m_musicalManager(musicalManager), m_soundCheckTime(soundCheckTime) 
	{
		m_musicalManager.setNumOfWorkingHours(m_soundCheckTime + m_duration + m_loadInLoadOutTime);
	}

	void setMusicalManager(const Crew& musicalManager)	{ m_musicalManager = musicalManager; }
	void setSoundCheckTime(int soundCheckTime)			{ m_soundCheckTime = soundCheckTime; }

	const Crew& getMusicalManager() const { return m_musicalManager; }
	int getSoundCheckTime()			const { return m_soundCheckTime; }

	friend istream& operator>>(istream& in, MusicShow& show);

	virtual void toOs(ostream& os) const;
	virtual void addParticipator(Musician& musician);
	virtual void loadInTime();

	virtual bool isShowPossible() const;
	virtual void talkWithProducer();
	virtual float getCost() const;

	void encore() ;
};

#endif