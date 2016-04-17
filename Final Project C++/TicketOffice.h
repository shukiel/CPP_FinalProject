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

	const void NotifyAllCustomer (ShowAtVenue show, char* message);

public:
	TicketOffice(Venue* venues, ShowAtVenue* shows, Contact contactDetails);
	TicketOffice(const TicketOffice& other);
	~TicketOffice();

	void setContactDetails(Contact contactDetails);

	const Contact getContactDetails() const {return contactDetails;}
	const Venue* getVenues() const {return venues;}
	const ShowAtVenue* getShows() const {return shows;}

	void show() const;

	const TicketOffice& operator=(const TicketOffice& other);
	friend ostream& operator<<(ostream& os, const TicketOffice& ticketOffice);
	friend istream& operator>>(istream& in, TicketOffice& ticketOffice);

	ShowAtVenue* ReserveShow(Venue venue, Show show, char* date);
	bool CancelShow();
	bool BuyTicket(ShowAtVenue show, int numOfTickets, Contact customer);
	bool cancelTicket(ShowAtVenue show, Contact customer);
	void ChangeShowTime(ShowAtVenue show, char* newDate);
};

#endif