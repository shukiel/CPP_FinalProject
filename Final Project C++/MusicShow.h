#ifndef __MUSICSHOW_H
#define __MUSICSHOW_H

#include "Show.h"
#include "Participator.h"
class Musician; //Forward declaration

class MusicShow : public Show
{
private:
	Musician** m_musicians; 
	Crew m_musicalManger;
	int m_soundCheckTime;

public:
	MusicShow(const Show& other, const Crew& musicalManger, int soundCheckTime, const Participator* musicians = NULL);
	MusicShow(const MusicShow& other);
	~MusicShow();

	void setDirector(const Crew& director);
	void setSoundCheckTime(int soundCheckTime) { this->m_soundCheckTime = soundCheckTime; }

	const Musician** getMusicians() const { return m_musicians; }
	const Crew& getMusicalManger() const { return m_musicalManger; }
	int getSoundCheckTime() const { return m_soundCheckTime; }

	const MusicShow& operator=(const MusicShow& other);
	friend ostream& operator<<(ostream& os, const MusicShow& show);
	friend istream& operator>>(istream& in, MusicShow& show);

	void makeShow() const;
	void makeShow();
	bool isShowPossible();
	void talkWithProducer();
	float getCost();
	void encore() const;
	void drinkBeerAndSmokeCiggarettes();
	bool addMusician(const Participator& musician);
};

#endif