#ifndef __PARTICIPATOR_H
#define __PARTICIPATOR_H

#include "Employee.h"

#define EGO_TRESHOLD 10
#define ADDITION_TO_EGO 5


class Participator : public Employee
{
protected:
	int m_egoLevel;

public:
	Participator(const Employee& other, int egoLevel = 0) : Employee(other), m_egoLevel(egoLevel) { }
	Participator() { }

	int getEgoLevel() const { return m_egoLevel; }

	friend istream& operator>>(istream& in, Participator& participator);

	virtual void toOs(ostream& os)	const;
	virtual bool isCanPerform()		const;

	virtual void doPartInShow() { cout << getName() << ": "; }

	void resetEgoLevel() { m_egoLevel = 0; }
};

#endif