#ifndef __THEATERSHOW_H
#define __THEATERSHOW_H

#include "Show.h"
#include "Participator.h"

class TheaterShow : public Show
{
private:
	Participator* actors; 
	Crew director;

public:
	TheaterShow(const Show& other, const Crew& director, const Participator* actors = NULL);
	TheaterShow(const TheaterShow& other);
	~TheaterShow();

	void setDirector(const Crew& director);

	const Participator* getActors() const { return actors; }
	const Crew& getDirector() const { return director; }

	const TheaterShow& operator=(const TheaterShow& other);
	friend ostream& operator<<(ostream& os, const TheaterShow& show);
	friend istream& operator>>(istream& in, TheaterShow& show);

	void makeShow() const;
	void makeDrama() const;
};

#endif