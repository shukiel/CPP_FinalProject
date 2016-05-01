#ifndef __TICKETOFFICE_H
#define __TICKETOFFICE_H

#include "Venue.h"
#include "Contact.h"

class TicketOffice
{
private:
	Venue* venues;
	ShowAtVenue* shows;
	Contact contactDetails;

	void NotifyAllCustomer (const ShowAtVenue& show, const char* message) const;

public:
	TicketOffice(const Venue* venues, const ShowAtVenue* shows, const Contact& contactDetails);
	TicketOffice(const TicketOffice& other);
	~TicketOffice();

	void setContactDetails(const Contact& contactDetails);

	const Contact& getContactDetails() const { return contactDetails; }
	const Venue* getVenues() const { return venues; }
	const ShowAtVenue* getShows() const { return shows; }

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