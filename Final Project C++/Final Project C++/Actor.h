#ifndef __ACTOR__H
#define __ACTOR__H

#include "Exceptions.h"
#include "Participator.h"

class Actor : public Participator
{
private:
	string m_line;
	const int CHANCE_TO_DRAMA = 15;

public:
	Actor(Participator& participator, const string& line) : Participator(participator) { setLine(line); }
	Actor() { }

	void setLine(const string& line) { m_line = line; }

	const string& getLine() const { return m_line; }

	friend istream& operator>>(istream& in, Actor& actor);

	virtual void toOs(ostream& os)	const;
	virtual bool isCanPerform()		const { return Participator::isCanPerform(); }

	virtual void doPartInShow();

	void makeDrama();		//Ego might go up!
};

#endif //__ACTOR__H
