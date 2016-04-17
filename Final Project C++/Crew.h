#ifndef __CREW_H
#define __CREW_H

#include "Contact.h"

class Crew : public Contact
{
private:
	int salaryPerHour;
	int numOfWorkingHours;
	int numOfBeersDrank;

public:
	Crew(char* name, char* phoneNum, char* address, 
		 int salaryPerHour, int numOfWorkingHours = 0, int numOfBeersDrank = 0);
	Crew(const Crew& other);

	void setSalaryPerHour(int salaryPerHour);
	void setNumOfWorkingHours(int numOfWorkingHours);
	void setNumOfBeersDrank(int numOfBeersDrank);

	const int getSalaryPerHour() const {return salaryPerHour;}
	const int getNumOfWorkingHours() const {return numOfWorkingHours;}
	const int getNumOfBeersDrank() const {return numOfBeersDrank;}

	void show() const;

	const Crew& operator=(const Crew& other);
	friend ostream& operator<<(ostream& os, const Crew& crew);
	friend istream& operator>>(istream& in, Crew& crew);

	void soberUp();
};

#endif