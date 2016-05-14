#ifndef __TICKETOFFICE_H
#define __TICKETOFFICE_H

#include "Venue.h"
#include "Contact.h"

class TicketOffice
{
private:
	Venue**			m_venues;
	Contact			m_contactDetails;
	int m_numOfVenues;
	const int MAX_NUM_OF_VENUES = 100;

	int getVenueIndex(const Venue& venue)const ;	//return the index of the venue in the venues array, -1 if does not exist
	void NotifyAllCustomer (const ShowAtVenue& show, const char* message) const;
	void addVenue(Venue& venue);

public:
	TicketOffice(const Contact& contactDetails);
	TicketOffice(const TicketOffice& other);
	~TicketOffice();

	void setContactDetails(const Contact& contactDetails);

	const Contact& getContactDetails() const { return m_contactDetails; }
	Venue** const getVenues() const { return m_venues; }

	const TicketOffice& operator=(const TicketOffice& other);
	friend ostream& operator<<(ostream& os, const TicketOffice& ticketOffice);
	friend istream& operator>>(istream& in, TicketOffice& ticketOffice);

	const ShowAtVenue* ReserveShow(Venue* venue, const Show* show, const char* date, int ticketPrice);
	void CancelShow(ShowAtVenue& show);
	void BuyTicket(ShowAtVenue& show, int numOfTickets, const Contact& customer);
	bool cancelTicket(ShowAtVenue& show, const Contact& customer);
	void ChangeShowTime(ShowAtVenue& show, const char* newDate);
};

#endif