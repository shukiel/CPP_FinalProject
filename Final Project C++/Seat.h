#ifndef __SEAT_H
#define __SEAT_H

#include "Contact.h"

class Seat
{
private:
	bool isOccupied;
	Contact customer;

public:
	Seat(Contact customer, bool isOccupied = false);
	Seat(const Seat& other);

	void setIsOccupied(bool isOccupied);
	void setCustomer(Contact customer);

	const bool getIsOccupied() const {return isOccupied;}
	const Contact getCustomer() const {return customer;}

	void show() const;

	const Seat& operator=(const Seat& other);
	friend ostream& operator<<(ostream& os, const Seat& seat);
	friend istream& operator>>(istream& in, Seat& seat);
};

#endif