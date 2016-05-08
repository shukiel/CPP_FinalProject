#ifndef __MUSICSHOW_H
#define __MUSICSHOW_H

#include "Show.h"
#include "Musician.h"

class MusicShow : public Show
{
private:
	//Musician** m_musicians; 
	Crew m_musicalManger;
	int m_soundCheckTime;

public:
	MusicShow(const Show& other, const Crew& musicalManger, int soundCheckTime);
	//MusicShow(const MusicShow& other);
	//~MusicShow();

	void setDirector(const Crew& director);
	void setSoundCheckTime(int soundCheckTime) { this->m_soundCheckTime = soundCheckTime; }

	//const Musician** getMusicians() const { return m_musicians; }
	const Crew& getMusicalManger() const { return m_musicalManger; }
	int getSoundCheckTime() const { return m_soundCheckTime; }

	const MusicShow& operator=(const MusicShow& other);
	//friend ostream& operator<<(ostream& os, const MusicShow& show);
	friend istream& operator>>(istream& in, MusicShow& show);

	virtual void toOs(ostream& os) const;
	virtual void addParticipator(Actor& actor);

	virtual void makeShow()			const;
	virtual bool isShowPossible()	const;
	virtual void talkWithProducer();

	void encore() const;
	void drinkBeerAndSmokeCiggarettes();
};

#endif