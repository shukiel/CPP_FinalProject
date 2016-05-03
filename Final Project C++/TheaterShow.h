#ifndef __THEATERSHOW_H
#define __THEATERSHOW_H

#include "Show.h"
#include "Participator.h"

class TheaterShow : public Show
{
private:
	Participator*	 m_actors; 
	Crew			 m_director;

public:
	TheaterShow(const Show& other, const Crew& director, const Participator* actors = NULL);
	TheaterShow(const TheaterShow& other);
	~TheaterShow();

	void setDirector(const Crew& director);

	const Participator* getActors() const { return m_actors; }
	const Crew& getDirector() const { return m_director; }

	const TheaterShow& operator=(const TheaterShow& other);
	friend ostream& operator<<(ostream& os, const TheaterShow& show);
	friend istream& operator>>(istream& in, TheaterShow& show);

	void makeShow() const;
	void makeDrama() const;
};

#endif