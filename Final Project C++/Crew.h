#ifndef __CREW_H
#define __CREW_H

#include "Employee.h"
#include "Exceptions.h"

#define MAX_NUM_OF_BEERS 10
#define CHANCE_TO_DRINK_BEER 0.2f

class Crew : public Employee
{
protected:
	int m_numOfBeersDrank;
	
public:
	Crew(const Employee& other, int numOfBeersDrank = 0) : Employee(other), m_numOfBeersDrank(numOfBeersDrank) { }
	Crew() { }

	void setNumOfBeersDrank(int numOfBeersDrank) { m_numOfBeersDrank = numOfBeersDrank; }

	int getNumOfBeersDrank() const { return m_numOfBeersDrank; }

	friend istream& operator>>(istream& in, Crew& crew);

	const Crew& operator+=(int num);

	virtual void toOs(ostream& os) const;
	
	void soberUp() { m_numOfBeersDrank = 0; }
	void drinkBeers();

	bool isTooDrunk() const { return m_numOfBeersDrank > MAX_NUM_OF_BEERS; }
};

#endif