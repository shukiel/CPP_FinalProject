#ifndef __CREW_H
#define __CREW_H

#include "Employee.h"

class Crew : public Employee
{
private:
	int numOfBeersDrank;

public:
	Crew(const Employee& other, int numOfBeersDrank = 0);

	void setNumOfBeersDrank(int numOfBeersDrank) { this->numOfBeersDrank = numOfBeersDrank; }

	int getNumOfBeersDrank() const { return numOfBeersDrank; }

	friend ostream& operator<<(ostream& os, const Crew& crew);
	friend istream& operator>>(istream& in, Crew& crew);

	void soberUp();
};

#endif