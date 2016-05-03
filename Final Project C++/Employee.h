#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H

#include "Contact.h"

class Employee : public Contact
{
private:
	float salaryPerHour;
	int numOfWorkingHours;

public:
	Employee(const Contact& other, float salaryPerHour, int numOfWorkingHours = 0) : Contact(other), salaryPerHour(salaryPerHour), numOfWorkingHours(numOfWorkingHours) {}

	void setSalaryPerHour(float salaryPerHour) { this->salaryPerHour = salaryPerHour; }
	void setNumOfWorkingHours(int numOfWorkingHours) { this->numOfWorkingHours = numOfWorkingHours; }

	float getSalaryPerHour() const { return salaryPerHour; }
	int getNumOfWorkingHours() const { return numOfWorkingHours; }

	friend istream& operator>>(istream& in, Employee& employee);

	virtual void toOs(ostream& os);

	float calcSalary() const { return numOfWorkingHours*salaryPerHour; }
};

#endif