#ifndef __PARTICIPATOR_H
#define __PARTICIPATOR_H

#include "Employee.h"

class Participator : public Employee
{
private:
	char* line;
	int egoLevel;

public:
	Participator(const Employee& other, const char* line, int egoLevel = 0);
	Participator(const Participator& other);
	~Participator();

	void setLine(const char* line);
	void setEgoLevel(int egoLevel) { this->egoLevel = egoLevel; }

	const char* getLine() const { return line; }
	int getEgoLevel() const { return egoLevel; }

	const Participator& operator=(const Participator& other);
	friend ostream& operator<<(ostream& os, const Participator& participator);
	friend istream& operator>>(istream& in, Participator& participator);
};

#endif