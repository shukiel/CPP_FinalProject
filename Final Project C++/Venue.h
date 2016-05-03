#ifndef __VENUE_H
#define __VENUE_H

#include "Contact.h"
#include "ShowAtVenue.h"


class Venue {

private:
	Contact		 m_contactDetails;
	int			 m_capacity;
	int			 m_numOfRows;
	int			 m_numOfSeatsPerRow;
	ShowAtVenue* m_showAtVenue; 

public:
	Venue(const Contact& contactDetails, int capacity, int numOfRows, int numOfSeatsPerRow, const ShowAtVenue* showAtVenue);
	Venue(const Venue& other);
	~Venue();

	void setContactDetails(const Contact& contactDetails);
	void setCapacity(int capacity) { this->m_capacity = capacity; }
	void setNumOfRows(int numOfRows) { this->m_numOfRows = numOfRows; }
	void setNumOfSeatsPerRow(int numOfSeatsPerRow) { this->m_numOfSeatsPerRow = numOfSeatsPerRow; }

	const Contact& getContactDetails() const { return m_contactDetails; }
	int getCapacity() const { return m_capacity; }
	int getNumOfRows() const { return m_numOfRows; }
	int getNumOfSeatsPerRow() const { return m_numOfSeatsPerRow; }
	const ShowAtVenue* getShowAtVenue() const { return m_showAtVenue; }

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
}
#endif