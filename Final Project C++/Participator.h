#ifndef __PARTICIPATOR_H
#define __PARTICIPATOR_H

#include "Employee.h"

#define EGO_TRESHOLD 0.7f
#define ADDITION_TO_EGO 0.1f


class Participator : public Employee
{
protected:
	float m_egoLevel;

public:
	Participator(const Employee& other, float egoLevel = 0) : Employee(other), m_egoLevel(egoLevel) { }
	Participator() { }

	float getEgoLevel() const { return m_egoLevel; }

	friend istream& operator>>(istream& in, Participator& participator);

	virtual void toOs(ostream& os) const;

	virtual void doPartInShow();

	void resetEgoLevel() { m_egoLevel = 0; }

	virtual bool isCanPerform() const { return m_egoLevel < EGO_TRESHOLD; } 
};

#endif