#ifndef __TICKETOFFICE_H
#define __TICKETOFFICE_H

#include "ShowAtVenue.h"
#include "Contact.h"
#include "LinkedList.h"

class TicketOffice
{
private:
	LinkedList<Venue>	m_venues;
	Contact				m_contactDetails;

	int getVenueIndex(const Venue& venue) const;	//return the index of the venue in the venues array, -1 if does not exist
	void NotifyAllCustomer(const ShowAtVenue& show, const string& message) const;
	void addVenue(Venue& venue);

public:
	TicketOffice(const Contact& contactDetails);
	TicketOffice(const TicketOffice& other);

	void setContactDetails(const Contact& contactDetails) {	m_contactDetails = contactDetails; }

	const Contact& getContactDetails()	const { return m_contactDetails; }

	const TicketOffice& operator=(const TicketOffice& other);
	friend ostream& operator<<(ostream& os, const TicketOffice& ticketOffice);
	friend istream& operator>>(istream& in, TicketOffice& ticketOffice);

	ShowAtVenue ReserveShow(Venue& venue, Show& show, const string& date);
	void CancelShow(ShowAtVenue& show);
	void BuyTicket(ShowAtVenue& show, int numOfTickets, const Contact& customer);
	void cancelTicket(ShowAtVenue& show, const Contact& customer);
	void ChangeShowTime(ShowAtVenue& show, const string& newDate);
	void makeShows();
};

#endif