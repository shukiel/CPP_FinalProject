#ifndef	 __DANCER__H
#define	 __DANCER__H

#include "Participator.h"
class Dancer : public Participator

{
public:
	int isNotHurt();

	Dancer(Employee& emp, char* part) : Participator(emp, part, 0){};
	void doPartInShow();
	void makeGetHurt();
};

#endif// __DANCER__H