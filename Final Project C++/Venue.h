#ifndef __VENUE_H
#define __VENUE_H

#include "Contact.h"
#include "ShowAtVenue.h"

class Venue
{
private:
	Contact contactDetails;
	int capacity;
	int numOfRows;
	int numOfSeatsPerRow;
	ShowAtVenue* showAtVenue; 

public:
	Venue(const Contact& contactDetails, int capacity, int numOfRows, int numOfSeatsPerRow, const ShowAtVenue* showAtVenue);
	Venue(const Venue& other);
	~Venue();

	void setContactDetails(const Contact& contactDetails);
	void setCapacity(int capacity) { this->capacity = capacity; }
	void setNumOfRows(int numOfRows) { this->numOfRows = numOfRows; }
	void setNumOfSeatsPerRow(int numOfSeatsPerRow) { this->numOfSeatsPerRow = numOfSeatsPerRow; }

	const Contact& getContactDetails() const { return contactDetails; }
	int getCapacity() const { return capacity; }
	int getNumOfRows() const { return numOfRows; }
	int getNumOfSeatsPerRow() const { return numOfSeatsPerRow; }
	const ShowAtVenue* getShowAtVenue() const { return showAtVenue; }

	const Venue& operator=(const Venue& other);
	bool operator==(const Venue& other) const;
	bool operator!=(const Venue& other) const;
	bool operator>(const Venue& other) const;
	bool operator<(const Venue& other) const;
	bool operator>=(const Venue& other) const;
	bool operator<=(const Venue& other) const;
	friend ostream& operator<<(ostream& os, const Venue& venue);
	friend istream& operator>>(istream& in, Venue& venue);

	bool AddShow(const Show& show);
	bool RemoveShow(const Show& show);
	int getSalesRevenue() const;
	bool isAvailable(const char* date, const Show& show) const;
};

#endif