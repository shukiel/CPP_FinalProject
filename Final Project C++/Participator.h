#ifndef __PARTICIPATOR_H
#define __PARTICIPATOR_H

#include "Contact.h"

class Participator : public Contact
{
private:
	float salaryPerShow;
	int numOfShows;
	char* line;
	int egoLevel;

public:
	Participator(char* name, char* phoneNum, char* address, 
				 float salaryPerShow, char* line, int numOfShows = 0, int egoLevel = 0);
	Participator(const Participator& other);

	void setSalaryPerShow(float salaryPerShow);
	void setLine(char* line);
	void setNumOfShows(int numOfShows);
	void setEgoLevel(int egoLevel);

	const float getSalaryPerShow() const {return salaryPerShow;}
	const char* getLine() const {return line;}
	const int getNumOfShows() const {return numOfShows;}
	const int getEgoLevel() const {return egoLevel;}

	void show() const;

	const Participator& operator=(const Participator& other);
	friend ostream& operator<<(ostream& os, const Participator& participator);
	friend istream& operator>>(istream& in, Participator& participator);
};

#endif