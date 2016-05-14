#ifndef __PARTICIPATOR_H
#define __PARTICIPATOR_H

#include "Employee.h"

class Participator : public Employee
{
protected:
	int m_egoLevel;
	const float EGO_TRESHOLD = 0.7f;
	const float ADDITION_TO_EGO = 0.1f;


public:
	Participator(const Employee& other, const char* part, int egoLevel = 0) : Employee(other), m_egoLevel(egoLevel) { }

	int getEgoLevel() const { return m_egoLevel; }

	friend istream& operator>>(istream& in, Participator& participator);

	virtual void toOs(ostream& os)	const;

	virtual void doPartInShow()		const = 0;

	void resetEgoLevel() { m_egoLevel = 0; }

	virtual bool isCanPerform() const { return m_egoLevel < EGO_TRESHOLD ;} 
};

#endif