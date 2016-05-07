#ifndef __MUSICIAN__H
#define __MUSICIAN__H

#include "Participator.h"
class Musician : public Participator
{
private:
	char* m_instrument;

public:
	Musician(Employee& emp, char* part, char * instrument) : Participator(emp, part, 0), m_instrument(NULL) { setInstrument(instrument); }

	void setInstrument(const char* instrument);

	const char* getInstrument() const { return m_instrument; }

	virtual void toOs(ostream& os) const; 
	void doPartInShow();
};

#endif //__MUSICIAN__H