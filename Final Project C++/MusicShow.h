#ifndef __MUSICSHOW_H
#define __MUSICSHOW_H

#include "Show.h"
#include "Musician.h"

#define MAX_NUM_OF_MUSICIANS 20 

class MusicShow : public virtual Show
{
private:
	//Musician** m_musicians; 
	Crew m_musicalManager;
	int m_soundCheckTime;

public:
	MusicShow(const Show& other, const Crew& musicalManager, int soundCheckTime) : Show(other), m_musicalManager(musicalManager), m_soundCheckTime(soundCheckTime) { }
	//MusicShow(const MusicShow& other);
	//~MusicShow();

	void setMusicalManager(const Crew& musicalManager) { m_musicalManager = musicalManager; }
	void setSoundCheckTime(int soundCheckTime) { m_soundCheckTime = soundCheckTime; }

	//const Musician** getMusicians() const { return m_musicians; }
	const Crew& getMusicalManager() const { return m_musicalManager; }
	int getSoundCheckTime() const { return m_soundCheckTime; }

	//const MusicShow& operator=(const MusicShow& other);
	//friend ostream& operator<<(ostream& os, const MusicShow& show);
	friend istream& operator>>(istream& in, MusicShow& show);

	virtual void toOs(ostream& os) const;
	virtual void addParticipator(Musician& musician);

	virtual void makeShow()			const;
	virtual bool isShowPossible()	const;
	virtual void talkWithProducer();

	void encore() const;
	void drinkBeerAndSmokeCiggarettes();
};

#endif