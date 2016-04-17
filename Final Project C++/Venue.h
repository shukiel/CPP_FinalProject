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
	Venue(Contact contactDetails, int capacity, int numOfRows, int numOfSeatsPerRow, ShowAtVenue* showAtVenue);
	Venue(const Venue& other);
	~Venue();

	void setContactDetails(Contact contactDetails);
	void setCapacity(int capacity);
	void setNumOfRows(int numOfRows);
	void setNumOfSeatsPerRow(int numOfSeatsPerRow);

	const Contact getContactDetails() const {return contactDetails;}
	const int getCapacity() const {return capacity;}
	const int getNumOfRows() const {return numOfRows;}
	const int getNumOfSeatsPerRow() const {return numOfSeatsPerRow;}
	const ShowAtVenue* getShowAtVenue() const {return showAtVenue;}

	void show() const;

	const Venue& operator=(const Venue& other);
	bool operator==(const Venue& other) const;
	bool operator!=(const Venue& other) const;
	bool operator>(const Venue& other) const;
	bool operator<(const Venue& other) const;
	bool operator>=(const Venue& other) const;
	bool operator<=(const Venue& other) const;
	friend ostream& operator<<(ostream& os, const Venue& venue);
	friend istream& operator>>(istream& in, Venue& venue);

	bool AddShow(Show show);
	bool RemoveShow(Show show);
	const int getSalesRevenue() const;
	const bool isAvailable(char* date, Show show) const;
};

#endif