#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H

#include "Contact.h"

class Employee : public Contact
{
protected:
	float	m_salaryPerHour;
	int		m_numOfWorkingHours;

public:
	Employee(const Contact& other, float salaryPerHour, int numOfWorkingHours = 0) : Contact(other), m_salaryPerHour(salaryPerHour), m_numOfWorkingHours(numOfWorkingHours) {}

	void setSalaryPerHour(float salaryPerHour)		 { m_salaryPerHour = salaryPerHour; }
	void setNumOfWorkingHours(int numOfWorkingHours) { m_numOfWorkingHours = numOfWorkingHours; }

	float getSalaryPerHour() const	 { return m_salaryPerHour; }
	int getNumOfWorkingHours() const { return m_numOfWorkingHours; }

	friend istream& operator>>(istream& in, Employee& employee);

	virtual void toOs(ostream& os) const;

	float calcSalary() const { return m_numOfWorkingHours*m_salaryPerHour; }
};

#endif