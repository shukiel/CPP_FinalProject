#ifndef __ACTOR__H
#define __ACTOR__H

#include "Exceptions.h"
#include "Participator.h"

class Actor : public Participator
{
private:
	char* m_line;

public:
	Actor(Participator& participator, const char* line) : Participator(participator), m_line(NULL) { setLine(line); }
	Actor(const Actor& other) : Participator(other), m_line(NULL) { setLine(other.getLine()); };
	virtual ~Actor() { delete[] m_line; }

	void setLine(const char* line);

	const char* getLine() const { return m_line; }

	const Actor& operator=(const Actor& other);
	friend istream& operator>>(istream& in, Actor& actor);

	void makeDrama() const;

	virtual void doPartInShow() const;
	virtual void toOs(ostream& os) const;
};

#endif //__ACTOR__H
