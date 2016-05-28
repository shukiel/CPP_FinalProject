#include "TicketOffice.h"
#include "ShowAtVenue.h"

TicketOffice::TicketOffice(const Contact& contactDetails) : m_contactDetails(contactDetails)
{
	m_venues = *(new LinkedList<Venue>());
}

TicketOffice::TicketOffice(const TicketOffice& other) : m_contactDetails(other.getContactDetails())
{
	m_venues = *(new LinkedList<Venue>());
	for (int i = 0; i < other.m_venues.getSize(); i++)
		m_venues += other.m_venues[i];
}

void TicketOffice::NotifyAllCustomer(const ShowAtVenue& show, const string& message) const throw (GenericException)
{
	int index = getVenueIndex(show.getVenue());
	if (index == -1)
		throw GenericException( "No Such Venue in the Ticket Office");

	Contact** allCustomers;
	allCustomers = show.getAllCustumers();

	for (int i = 0; i < show.getNumOfPeopleInAudience(); i++)
		cout << "to :" << *allCustomers[i] << message << endl;
}

ostream& operator<<(ostream& os, const TicketOffice& ticketOffice)
{
	os << "Ticket Office " << ticketOffice.getContactDetails() << endl;
	ticketOffice.m_venues.toOs(os);

	return os;
}

ShowAtVenue TicketOffice::ReserveShow(Venue& venue, Show& show, const string& date)
{
	int index = getVenueIndex(venue);
	if (index == -1)
	{
		addVenue(venue);
		index = m_venues.getSize() - 1;
	}

	ShowAtVenue temp(&show, venue, date);
	venue.AddShow(temp);
	m_venues[index].AddShow(temp);
	return temp;
}

void TicketOffice::CancelShow(ShowAtVenue& show) throw (GenericException)
{
	int index = getVenueIndex(show.getVenue());
	if (index == -1)
		throw GenericException( "Venue Does not exist in the Ticket Office");
	
	else
		m_venues[index] -= show;
}
void TicketOffice::BuyTicket(ShowAtVenue& show, int numOfTickets, const Contact& customer) throw (GenericException)
{
	int index = getVenueIndex(show.getVenue());
	if (index == -1)
		throw GenericException("No Such Venue in the Ticket Office");

	(*m_venues[index].findShow(show)).AddSeats(numOfTickets, customer);
}

void TicketOffice::cancelTicket(ShowAtVenue& show, const Contact& customer) throw (GenericException)
{
	int index = getVenueIndex(show.getVenue());
	if (index == -1)
		throw GenericException("No Such Venue in the Ticket Office");

	show.RemoveSeats(customer);
}

void TicketOffice::ChangeShowTime(ShowAtVenue& show, const string& newDate) throw (GenericException)
{
	int index = getVenueIndex(show.getVenue());
	if (index == -1)
		throw GenericException( "No Such Venue in the Ticket Office");
	
	show.setDate(newDate);
}

int TicketOffice::getVenueIndex(const Venue& venue) const 
{
	for (int i = 0; i < m_venues.getSize(); i++)
		if (venue == m_venues[i])
			return i;

	return -1;
}

void TicketOffice::addVenue(Venue& venue)  throw (GenericException)
{
	m_venues += venue;
}

void TicketOffice::makeShows()
{
	for (int i = 0; i < m_venues.getSize(); i++)
		m_venues[i].makeShow();
}