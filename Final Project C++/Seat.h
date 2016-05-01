#ifndef __SEAT_H
#define __SEAT_H

#include "Contact.h"

class Seat
{
private:
	bool isOccupied;
	Contact customer;

public:
	Seat(const Contact& customer, bool isOccupied = false);
	Seat(const Seat& other);
	~Seat();

	void setIsOccupied(bool isOccupied) { this->isOccupied = isOccupied; }
	void setCustomer(const Contact& customer);

	bool getIsOccupied() const { return isOccupied; }
	const Contact& getCustomer() const { return customer; }

	const Seat& operator=(const Seat& other);
	friend ostream& operator<<(ostream& os, const Seat& seat);
	friend istream& operator>>(istream& in, Seat& seat);
};

#endif