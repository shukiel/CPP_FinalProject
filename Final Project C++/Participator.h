#ifndef __PARTICIPATOR_H
#define __PARTICIPATOR_H

#include "Employee.h"

class Participator : public Employee
{
private:
	int m_egoLevel;

public:
	Participator(const Employee& other, const char* part, int egoLevel = 0) : Employee(other), m_egoLevel(egoLevel) { }

	void resetEgoLevel() { m_egoLevel = 0; }

	int getEgoLevel() const { return m_egoLevel; }

	virtual void doPartInShow() const = 0;
	virtual void toOs(ostream& os) const;

	friend istream& operator>>(istream& in, Participator& participator);
};

#endif