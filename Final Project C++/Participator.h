#ifndef __PARTICIPATOR_H
#define __PARTICIPATOR_H

#include "Employee.h"

class Participator : public Employee
{
private:
	int m_egoLevel;

public:
	Participator(const Employee& other, const char* part, int egoLevel = 0) : Employee(other), m_egoLevel(egoLevel) { }

	int getEgoLevel() const { return m_egoLevel; }

	friend istream& operator>>(istream& in, Participator& participator);

	virtual void toOs(ostream& os)	const;

	virtual void doPartInShow()		const = 0;

	void resetEgoLevel() { m_egoLevel = 0; }
};

#endif