#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H

#include "Contact.h"

class Employee : public Contact
{
private:
	float salaryPerHour;
	int numOfWorkingHours;

public:
	Employee(const Contact& other, float salaryPerHour, int numOfWorkingHours = 0);

	void setSalaryPerHour(float salaryPerHour) { this->salaryPerHour = salaryPerHour; }
	void setNumOfWorkingHours(int numOfWorkingHours) { this->numOfWorkingHours = numOfWorkingHours; }

	float getSalaryPerHour() const { return salaryPerHour; }
	int getNumOfWorkingHours() const { return numOfWorkingHours; }

	friend ostream& operator<<(ostream& os, const Crew& crew);
	friend istream& operator>>(istream& in, Crew& crew);

	float calcSalary() const;
};

#endif