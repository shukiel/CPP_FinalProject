#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H

#include "Contact.h"

class Employee : public Contact
{
private:
	float	m_salaryPerHour;
	int		m_numOfWorkingHours;

public:
	Employee(const Contact& other, float salaryPerHour, int numOfWorkingHours = 0);

	void setSalaryPerHour(float salaryPerHour) { this->m_salaryPerHour = salaryPerHour; }
	void setNumOfWorkingHours(int numOfWorkingHours) { this->m_numOfWorkingHours = numOfWorkingHours; }

	float getSalaryPerHour() const { return m_salaryPerHour; }
	int getNumOfWorkingHours() const { return m_numOfWorkingHours; }

	friend ostream& operator<< (ostream& os, const Employee& emp);
	friend istream& operator>> (istream& in, Employee& emp);

	float calcSalary() const;
};

#endif