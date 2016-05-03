#ifndef __TICKETOFFICE_H
#define __TICKETOFFICE_H

#include "Venue.h"
#include "Contact.h"

class TicketOffice
{
private:
	Venue*			m_venues;
	ShowAtVenue*	m_shows;
	Contact			m_contactDetails;

	void NotifyAllCustomer (const ShowAtVenue& show, const char* message) const;

public:
	TicketOffice(const Venue* venues, const ShowAtVenue* shows, const Contact& contactDetails);
	TicketOffice(const TicketOffice& other);
	~TicketOffice();

	void setContactDetails(const Contact& contactDetails);

	const Contact& getContactDetails() const { return m_contactDetails; }
	const Venue* getVenues() const { return m_venues; }
	const ShowAtVenue* getShows() const { return m_shows; }

	const TicketOffice& operator=(const TicketOffice& other);
	friend ostream& operator<<(ostream& os, const TicketOffice& ticketOffice);
	friend istream& operator>>(istream& in, TicketOffice& ticketOffice);

	const ShowAtVenue* ReserveShow(const Venue& venue, const Show& show, const char* date);
	bool CancelShow();
	bool BuyTicket(const ShowAtVenue& show, int numOfTickets, const Contact& customer);
	bool cancelTicket(const ShowAtVenue& show, const Contact& customer);
	void ChangeShowTime(const ShowAtVenue& show, const char* newDate);
};

#endif