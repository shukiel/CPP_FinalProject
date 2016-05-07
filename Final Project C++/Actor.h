#ifndef __ACTOR__H
#define __ACTOR__H

#include "Exceptions.h"
#include "Participator.h"
class Actor : public Participator
{
public:
	Actor(Employee& emp, char* part) : Participator(emp, part, 0){};
	void doPartInShow();
	void makeDrama();
};


#endif //__ACTOR__H
