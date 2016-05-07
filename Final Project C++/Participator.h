#ifndef __PARTICIPATOR_H
#define __PARTICIPATOR_H

#include "Employee.h"

class Participator : public Employee
{
private:
	char* m_part;
	int m_egoLevel;

public:
	Participator(const Employee& other, const char* part, int egoLevel = 0) : Employee(other), m_part(NULL), m_egoLevel(egoLevel) { setPart(part); }
	Participator(const Participator& other) : Employee(other), m_part(NULL),  m_egoLevel(other.m_egoLevel) { setPart(other.m_part); }
	virtual ~Participator() { delete []m_part; }

	void setPart(const char* part);
	void resetEgoLevel() { m_egoLevel = 0; }

	const char* getLine() const { return m_part; }
	int getEgoLevel() const { return m_egoLevel; }

	virtual void doPartInShow();
	virtual void toOs(ostream& os) const;

	const Participator& operator=(const Participator& other);
	friend istream& operator>>(istream& in, Participator& participator);
};

#endif