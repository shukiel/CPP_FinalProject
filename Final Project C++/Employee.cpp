#include "Employee.h"

	istream& operator>>(istream& in, Employee& employee)
	{
		in >> (Contact&) employee >> employee.salaryPerHour >> employee.numOfWorkingHours;
		return in;
	}

	void Employee::toOs(ostream& os)
	{
		os << "Salary per hour: " << salaryPerHour << ", Num of working hours: " << numOfWorkingHours << endl;
	}