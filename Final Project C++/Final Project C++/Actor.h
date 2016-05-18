#ifndef __ACTOR__H
#define __ACTOR__H

#include "Exceptions.h"
#include "Participator.h"



class Actor : public Participator
{
private:
	char* m_line;
	const int CHANCE_TO_DRAMA = 15;

public:
	Actor(Participator& participator, const char* line) : Participator(participator), m_line(NULL) { setLine(line); }
	Actor(const Actor& other) : Participator(other), m_line(NULL) { *this = other; }
	Actor() { }
	virtual ~Actor() { delete[] m_line; }

	void setLine(const char* line) { m_line = _strdup(line); }

	const char* getLine() const { return m_line; }

	const Actor& operator=(const Actor& other);
	friend istream& operator>>(istream& in, Actor& actor);

	virtual void toOs(ostream& os)	const;
	virtual bool isCanPerform()		const { return Participator::isCanPerform(); }

	virtual void doPartInShow();

	void makeDrama();		//Ego might go up!
};

#endif //__ACTOR__H
