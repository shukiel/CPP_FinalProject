#ifndef __SHOWATVENUE_H
#define __SHOWATVENUE_H

#include "Show.h"
#include "Venue.h"
#include "Exceptions.h"

class ShowAtVenue
{
private:
	Show			m_show;			
	Venue			m_venue;	
	char*			m_date;
	Contact***		m_seatArr;		//2D array of pointers to Seats(Contacts)
	int				m_numOfPeople;

	bool isFreeSpace(int numOfTickets) const;
	void freeAlloc();

public:
	ShowAtVenue(const Show& show, const Venue& venue, const char* date);
	ShowAtVenue(const ShowAtVenue& other) { *this = other; }
	ShowAtVenue() { }
	~ShowAtVenue() { freeAlloc(); }

//	void setShow(const Show* show);
	void setDate(const char* date);

	int getNumOfPeopleInAudience()	const { return m_numOfPeople; } 
	const Show& getShow()			const { return m_show; }
	const char* getDate()			const { return m_date; }
	const Venue& getVenue()			const { return m_venue; }

	float GetTotalSalesValue() const;
	float getProfit() const;

	void AddSeats(int numOfTickets, const Contact& customer);
	void RemoveSeats(const Contact& customer);
	Contact** const getAllCustumers() const;  //Will return a array of pointers to all the customers in the show FREE

	bool operator==(const ShowAtVenue& other) const
		{ return ((getShow() == other.getShow()) && (getVenue() == other.getVenue()) && strcmp(getDate(), other.getDate()) == 0); }
	bool operator!=(const ShowAtVenue& other) const { return !(*this == other); }

	const ShowAtVenue& operator=(const ShowAtVenue& other);

	friend ostream& operator<<(ostream& os, const ShowAtVenue& show);
	friend istream& operator>>(istream& in, ShowAtVenue& show);
};

#endif