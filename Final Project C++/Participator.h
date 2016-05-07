#ifndef __PARTICIPATOR_H
#define __PARTICIPATOR_H

#include "Employee.h"

class Participator : public Employee
{
private:
	char* m_part;
	int m_egoLevel;

public:
	Participator(const Employee& other, const char* part, int egoLevel = 0);
	Participator(const Participator& other);
	~Participator();

	void setPart(const char* part);
	void resetEgoLevel() { this->m_egoLevel = 0; }

	const char* getLine() const { return m_part; }
	int getEgoLevel() const { return m_egoLevel; }

	virtual void doPartInShow();
	virtual void toOs(ostream& os) const;

	const Participator& operator=(const Participator& other);
	friend ostream& operator<<(ostream& os, const Participator& participator);
	friend istream& operator>>(istream& in, Participator& participator);
};

#endif