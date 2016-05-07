#ifndef __MUSICIAN__H
#define __MUSICIAN__H

#include "Participator.h"
class Musician : public Participator
{
public:
	char* m_instrument;

	Musician(Employee& emp, char* part, char * instrument) : Participator(emp, part, 0){ m_instrument = _strdup(instrument);}
	void doPartInShow();
};

#endif //__MUSICIAN__H