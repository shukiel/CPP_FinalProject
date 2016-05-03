#ifndef __CREW_H
#define __CREW_H

#include "Employee.h"

class Crew : public Employee
{
private:
	int m_numOfBeersDrank;

public:
	Crew(const Employee& other, int numOfBeersDrank = 0);
	Crew(const char* name, const char* phoneNum, const char* address, int m_salaryPerHour);

	void setNumOfBeersDrank(int numOfBeersDrank) { this->m_numOfBeersDrank = numOfBeersDrank; }

	int getNumOfBeersDrank() const { return m_numOfBeersDrank; }

	friend ostream& operator<<(ostream& os, const Crew& crew);
	friend istream& operator>>(istream& in, Crew& crew);

	void soberUp();
};

#endif