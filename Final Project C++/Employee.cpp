#include "Employee.h"

	istream& operator>>(istream& in, Employee& employee)
	{
		in >> (Contact&) employee >> employee.m_salaryPerHour >> employee.m_numOfWorkingHours;
		return in;
	}

	void Employee::toOs(ostream& os)
	{
		os << "Salary per hour: " << m_salaryPerHour << ", Num of working hours: " << m_numOfWorkingHours << endl;
	}