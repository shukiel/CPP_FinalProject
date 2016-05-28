#ifndef __MUSICIAN__H
#define __MUSICIAN__H

#include "Participator.h"

#define CHANCE_TO_SOLO 30

class Musician : public Participator
{
private:
	string m_instrument;

public:
	Musician(Participator& participator, string& instrument) : Participator(participator) { setInstrument(instrument); }
	Musician() { }
	
	void setInstrument(const string& instrument) { m_instrument = instrument; }

	const string& getInstrument() const { return m_instrument; }

	friend istream& operator>>(istream& in, Musician& musician);

	virtual void toOs(ostream& os)	const;
	virtual bool isCanPerform()		const { return Participator::isCanPerform(); }

	virtual void doPartInShow();

	void makeSolo();		//Ego might go up!
};

#endif //__MUSICIAN__H