#ifndef __DANCESHOW_H
#define __DANCESHOW_H

#include "Show.h"
#include "Participator.h"

class DanceShow : public Show
{
private:
	Participator* m_dancers; 
	Participator m_choreograph;

public:
	DanceShow(const Show& other, const Participator choreograph, const Participator* dancers = NULL);
	DanceShow(const DanceShow& other);
	~DanceShow();

	void setChoreograph(Participator choreograph);

	const Participator* getDancers() const { return m_dancers; }
	const Participator& getChoreograph() const { return m_choreograph; }

	const DanceShow& operator=(const DanceShow& other);
	friend ostream& operator<<(ostream& os, const DanceShow& show);
	friend istream& operator>>(istream& in, DanceShow& show);

	void makeShow() const;
	void dancerInjured(const Participator& dancer); 
};

#endif