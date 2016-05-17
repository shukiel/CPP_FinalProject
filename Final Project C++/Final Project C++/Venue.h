#ifndef __VENUE_H
#define __VENUE_H

#include "Contact.h"

#define MAX_NUM_OF_SHOWS 100

class ShowAtVenue;	//Forward declaration

class Venue{
private:
	char*			m_name;
	Contact			m_contactDetails;
	int				m_capacity;
	int				m_numOfRows;
	int				m_numOfSeatsPerRow;
	int				m_numOfShows;
	ShowAtVenue*	m_showAtVenue;				//Array Of shows 

	void copyEverythingButContact(const Venue& other);

public:
	Venue(const Contact& contactDetails, int capacity, int numOfRows, int numOfSeatsPerRow, const char* name);
	Venue(const Venue& other) : m_contactDetails(other.m_contactDetails), m_showAtVenue(NULL) { copyEverythingButContact(other); }
	Venue() { }
	~Venue();

	void setContactDetails(const Contact& contactDetails)	{ m_contactDetails = contactDetails; }
	void setCapacity(int capacity)							{ m_capacity = capacity; }
	void setNumOfRows(int numOfRows)						{ m_numOfRows = numOfRows; }
	void setNumOfSeatsPerRow(int numOfSeatsPerRow)			{ m_numOfSeatsPerRow = numOfSeatsPerRow; }

	const Contact& getContactDetails()		const { return m_contactDetails; }
	int getCapacity()						const { return m_capacity; }
	int getNumOfRows()						const { return m_numOfRows; }
	int getNumOfSeatsPerRow()				const { return m_numOfSeatsPerRow; }
	int getNumOfShows()						const { return m_numOfShows; }
	const char* getVenueName()				const { return m_name; }
	ShowAtVenue* getShowAtVenue()			const { return m_showAtVenue; }

	bool operator==(const Venue& other) const 
		{ return strcmp(getVenueName(), other.getVenueName()) == 0 && getContactDetails() == other.getContactDetails(); }
	bool operator!=(const Venue& other) const { return !(*this == other); }

	const Venue& operator=(const Venue& other);
	void operator+=(const ShowAtVenue& show);	//adds a show to the venue
	void operator-=(const ShowAtVenue& show);	//removes a show from a venue

	friend ostream& operator<<(ostream& os, const Venue& venue);
	friend istream& operator>>(istream& in, Venue& venue);

	void AddShow(const ShowAtVenue& show)		{ *this += show; }
	void RemoveShow(const ShowAtVenue& show)	{ *this -= show; }
	void makeShow();

	float getSalesRevenue() const;
};

#endif