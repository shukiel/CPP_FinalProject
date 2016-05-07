#ifndef __CREW_H
#define __CREW_H

#include "Employee.h"
#include "Exceptions.h"

class Crew : public Employee
{
private:
	int m_numOfBeersDrank;

public:
	Crew(const Employee& other, int numOfBeersDrank = 0) : Employee(other), m_numOfBeersDrank(numOfBeersDrank) { }
	//Crew(const char* name, const char* phoneNum, const char* address, int m_salaryPerHour);

	void setNumOfBeersDrank(int numOfBeersDrank) { m_numOfBeersDrank = numOfBeersDrank; }

	int getNumOfBeersDrank() const { return m_numOfBeersDrank; }

	friend istream& operator>>(istream& in, Crew& crew);

	virtual void toOs(ostream& os);

	void soberUp();
};

#endif