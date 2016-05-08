#ifndef __MUSICIAN__H
#define __MUSICIAN__H

#include "Participator.h"
class Musician : public Participator
{
private:
	char* m_instrument;

public:
	Musician(Participator& participator, char * instrument) : Participator(participator), m_instrument(NULL) { setInstrument(instrument); }
	Musician(const Musician& other) : Participator(other), m_instrument(NULL) { *this = other; }
	virtual ~Musician() { delete[] m_instrument; }

	void setInstrument(const char* instrument);

	const char* getInstrument() const { return m_instrument; }

	const Musician& operator=(const Musician& other);
	friend istream& operator>>(istream& in, Musician& musician);

	virtual void doPartInShow() const;
	virtual void toOs(ostream& os) const;
};

#endif //__MUSICIAN__H