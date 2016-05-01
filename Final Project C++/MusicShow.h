#ifndef __MUSICSHOW_H
#define __MUSICSHOW_H

#include "Show.h"
#include "Participator.h"

class MusicShow : public Show
{
private:
	Participator* musicians; 
	Crew musicalManger;
	int soundCheckTime;

public:
	MusicShow(const Show& other, const Crew& musicalManger, int soundCheckTime, const Participator* musicians = NULL);
	MusicShow(const MusicShow& other);
	~MusicShow();

	void setDirector(const Crew& director);
	void setSoundCheckTime(int soundCheckTime) { this->soundCheckTime = soundCheckTime; }

	const Participator* getMusicians() const { return musicians; }
	const Crew& getMusicalManger() const { return musicalManger; }
	int getSoundCheckTime() const { return soundCheckTime; }

	const MusicShow& operator=(const MusicShow& other);
	friend ostream& operator<<(ostream& os, const MusicShow& show);
	friend istream& operator>>(istream& in, MusicShow& show);

	void makeShow() const;
	void encore() const;
	void drinkBeerAndSmokeCiggarettes();
	bool addMusician(const Participator& musician);
};

#endif