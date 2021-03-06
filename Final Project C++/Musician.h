#ifndef __MUSICIAN__H
#define __MUSICIAN__H

#include "Participator.h"

#define CHANCE_TO_SOLO 0.3f

class Musician : public Participator
{
private:
	char* m_instrument;

public:
	Musician(Participator& participator, char * instrument) : Participator(participator), m_instrument(NULL) { setInstrument(instrument); }
	Musician(const Musician& other) : Participator(other), m_instrument(NULL) { *this = other; }
	Musician() { }
	virtual ~Musician() { delete[] m_instrument; }

	void setInstrument(const char* instrument) { m_instrument = _strdup(instrument); }

	const char* getInstrument() const { return m_instrument; }

	const Musician& operator=(const Musician& other);
	friend istream& operator>>(istream& in, Musician& musician);

	void makeSolo();		//Ego might go up!

	virtual void doPartInShow();

	virtual void toOs(ostream& os)	const;
	virtual bool isCanPerform()		const { return Participator::isCanPerform(); }
};

#endif //__MUSICIAN__H