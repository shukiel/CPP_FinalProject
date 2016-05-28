#ifndef __SHOWATVENUE_H
#define __SHOWATVENUE_H

#include "Musical.h"
#include "Venue.h"
#include "Exceptions.h"
#include <vector>

class ShowAtVenue
{
private:
	Show*					m_show;
	Venue					m_venue;
	string					m_date;
	vector<vector<Contact>>	m_seatArr;		//2D array of pointers to Seats(Contacts)
	int						m_numOfPeople;

	bool isFreeSpace(int numOfTickets) const { return m_numOfPeople + numOfTickets < m_venue.getCapacity(); }

public:
	ShowAtVenue(Show* show, const Venue& venue, const string& date);
	ShowAtVenue(const ShowAtVenue& other) { *this = other; }
	ShowAtVenue() { }

	void setDate(const string& date) { m_date = date; }

	int getNumOfPeopleInAudience()	const { return m_numOfPeople; }
	const Show& getShow()			const { return *m_show; }
	const string& getDate()			const { return m_date; }
	const Venue& getVenue()			const { return m_venue; }

	bool operator==(const ShowAtVenue& other) const
		{ return ((getShow() == other.getShow()) && (getVenue() == other.getVenue()) && getDate().compare(other.getDate()) == 0); }
	bool operator!=(const ShowAtVenue& other) const { return !(*this == other); }

	const ShowAtVenue& operator=(const ShowAtVenue& other);
	friend ostream& operator<<(ostream& os, const ShowAtVenue& show);
	friend istream& operator>>(istream& in, ShowAtVenue& show);

	int GetTotalSalesValue()	const { return (int)m_numOfPeople * m_show->getTicketPrice(); }
	int getProfit()				const { return GetTotalSalesValue() - m_show->getCost(); }

	void AddSeats(int numOfTickets, const Contact& customer);
	void RemoveSeats(const Contact& customer);
	void makeShow();

	Contact** const getAllCustumers() const;  //Will return a array of pointers to all the customers in the show FREE
};

#endif