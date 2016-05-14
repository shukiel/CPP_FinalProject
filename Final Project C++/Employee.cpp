#include "Employee.h"

istream& operator>>(istream& in, Employee& employee)
{
	in >> (Contact&) employee;

	cout << "Please insert the employee's salary per hour: ";
	in >> employee.m_salaryPerHour;

	cout << "Please insert the employee's num of working hours: ";
	in >> employee.m_numOfWorkingHours;

	return in;
}

void Employee::toOs(ostream& os) const
{
	Contact::toOs(os);
	os << "Salary per hour: " << m_salaryPerHour << ", Num of working hours: " << m_numOfWorkingHours << endl;
}