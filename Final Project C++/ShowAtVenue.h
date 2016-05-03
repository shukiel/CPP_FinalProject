#ifndef __SHOWATVENUE_H
#define __SHOWATVENUE_H

#include "Show.h"
#include "Contact.h"

class ShowAtVenue
{
private:
	Show*		m_show;
	char*		m_date;
	int			m_ticketPrice;
	Contact**	m_seatArr;
	bool		m_isFreeSpace(int numOfTickets) const;


public:
	ShowAtVenue(const Show& show, const char* date, int ticketPrice);
	ShowAtVenue(const ShowAtVenue& other);
	~ShowAtVenue();

	void setShow(const Show& show);
	void setDate(const char* date);
	void setTicketPrice(int ticketPrice) { this->m_ticketPrice = ticketPrice; }

	const Show& getShow() const { return *m_show; }
	const char* getDate() const { return m_date; }
	int getTicketPrice() const { return m_ticketPrice; }
	int getNumOfPeopleInAudience() const;


	int GetTotalSalesValue() const;
	void AddSeats(int numOfTickets, const Contact& customer);
	const Contact* getAllCustumers() const;


	const ShowAtVenue& operator=(const ShowAtVenue& other);
	friend ostream& operator<<(ostream& os, const ShowAtVenue& show);
	friend istream& operator>>(istream& in, ShowAtVenue& show);
}

#endif