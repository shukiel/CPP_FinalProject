#include "TicketOffice.h"
#include "ShowAtVenue.h"

TicketOffice::TicketOffice(const Contact& contactDetails) : m_contactDetails(contactDetails)
{
	m_numOfVenues = 0;
	m_venues = new Venue*[MAX_NUM_OF_VENUES];
	for (int i = 0; i < MAX_NUM_OF_VENUES; i++)
		m_venues[i] = NULL;
}

TicketOffice::TicketOffice(const TicketOffice& other) : m_contactDetails(other.getContactDetails())
{
	m_venues = new Venue*[other.MAX_NUM_OF_VENUES];
	m_numOfVenues = other.m_numOfVenues;
	for (int i = 0; i < m_numOfVenues; i++)
		*m_venues[i] = *other.m_venues[i];
}

void TicketOffice::NotifyAllCustomer(const ShowAtVenue& show, const char* message) const throw (const char*)
{
	int index = getVenueIndex(show.getVenue());
	if (index == -1)
		throw "No Such Venue in the Ticket Office";

	Contact** allCustomers;
	allCustomers = show.getAllCustumers();

	for (int i = 0; i < show.getNumOfPeopleInAudience(); i++)
		cout << "to :" << *allCustomers[i] << message << endl;
}

ostream& operator<<(ostream& os, const TicketOffice& ticketOffice)
{
	os << "Ticket Office " << ticketOffice.getContactDetails() << endl;

	for (int i = 0; i < ticketOffice.m_numOfVenues; i++)
		os << *ticketOffice.m_venues[i] << endl;

	return os;
}

ShowAtVenue TicketOffice::ReserveShow(Venue& venue, const Show& show, const char* date)
{
	if (getVenueIndex(venue) == -1)
		addVenue(venue);

	ShowAtVenue temp(show, venue, date);
	venue.AddShow(temp);
	return temp;
}

void TicketOffice::CancelShow(ShowAtVenue& show) throw (const char*)
{
	int index = getVenueIndex(show.getVenue());
	if (index == -1)
		throw "Venue Does not exist in the Ticket Office";
	
	else
		*m_venues[index] -= show;
}
void TicketOffice::BuyTicket(ShowAtVenue* show, int numOfTickets, const Contact& customer) throw (const char*)
{
	int index = getVenueIndex(show->getVenue());
	if (index == -1)
		throw "No Such Venue in the Ticket Office";

	int num = m_venues[index]->getNumOfShows();
	ShowAtVenue* sav = m_venues[index]->getShowAtVenue();

	for (int i = 0; i < num; i++)
		if (*show == sav[i])
			sav[i].AddSeats(numOfTickets, customer);
}

void TicketOffice::cancelTicket(ShowAtVenue& show, const Contact& customer) throw (const char*)
{
	int index = getVenueIndex(show.getVenue());
	if (index == -1)
		throw "No Such Venue in the Ticket Office";

	show.RemoveSeats(customer);
}

void TicketOffice::ChangeShowTime(ShowAtVenue& show, const char* newDate) throw (const char*)
{
	int index = getVenueIndex(show.getVenue());
	if (index == -1)
		throw "No Such Venue in the Ticket Office";
	
	show.setDate(newDate);
}

int TicketOffice::getVenueIndex(const Venue& venue) const 
{
	for (int i = 0; i < m_numOfVenues; i++)
		if (venue == *m_venues[i])
			return i;

	return -1;
}

void TicketOffice::addVenue(Venue& venue)  throw (const char*)
{
	if (m_numOfVenues >= MAX_NUM_OF_VENUES)
		throw "Not enougth room for another room";
	
	m_venues[m_numOfVenues++] = &venue;
}

void TicketOffice::makeShows()
{
	for (int i = 0; i < m_numOfVenues; i++)
		m_venues[i]->makeShow();
}