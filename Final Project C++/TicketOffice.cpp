#include "TicketOffice.h"
#include "ShowAtVenue.h"



TicketOffice::TicketOffice(const Contact& contactDetails) : 
							m_contactDetails(contactDetails)
{
	m_numOfVenues = 0;
	m_venues = new Venue*[MAX_NUM_OF_VENUES];
}

TicketOffice::TicketOffice(const TicketOffice& other) : m_contactDetails(other.getContactDetails())
{
	m_venues = new Venue*[other.MAX_NUM_OF_VENUES];
	this->m_numOfVenues = other.m_numOfVenues;
	for (int i = 0; i < m_numOfVenues; i++)
	{
		m_venues[i] = other.m_venues[i];
	}
}

TicketOffice::~TicketOffice()
{
	delete[] m_venues;
}

void TicketOffice::NotifyAllCustomer(const ShowAtVenue& show, const char* message) const
{
	const Venue* temp = show.getVenue();
	int index = getVenueIndex(*temp);
	if (index == -1)
	{
		throw "No Such Venue in the Ticket Office";
	}
	
	const Contact** allCustomers;
	allCustomers = show.getAllCustumers();

	for (int i = 0; i < show.getNumOfPeopleInAudience(); i++)
	{
		cout << "to :" << *allCustomers[i] << message << endl;
	}
}

void TicketOffice::setContactDetails(const Contact& contactDetails)
{
	m_contactDetails = contactDetails;
}

ostream& operator<<(ostream& os, const TicketOffice& ticketOffice)
{
	cout << "Ticket Office " << ticketOffice.getContactDetails();
	for (int i = 0; i < ticketOffice.m_numOfVenues; i++)
	{
		cout << *ticketOffice.m_venues[i];
	}
	return os;
}

const ShowAtVenue* TicketOffice::ReserveShow(Venue* venue, const Show* show, const char* date, int ticketPrice)
{
	if (getVenueIndex(*venue) == -1)
	{
		addVenue(*venue);
	}

	ShowAtVenue* temp = new ShowAtVenue(show, venue, date, ticketPrice);
	venue->AddShow(*temp);
	return temp;
}

void TicketOffice::CancelShow(ShowAtVenue& show)
{
	int index = getVenueIndex(*show.getVenue());
	if (index == -1)
	{
		throw "Venue Does not exist in the Ticket Office";
	}
	else
	{
		*m_venues[index] -= show;
	}
}
void TicketOffice::BuyTicket(ShowAtVenue& show, int numOfTickets, const Contact& customer)
{
	const Venue* temp = show.getVenue();
	int index = getVenueIndex(*temp);
	if (index == -1)
	{
		throw "No Such Venue in the Ticket Office";
	}
	show.AddSeats(numOfTickets, &customer);
}

bool TicketOffice::cancelTicket(ShowAtVenue& show, const Contact& customer)
{
	const Venue* temp = show.getVenue();
	int index = getVenueIndex(*temp);
	if (index == -1)
	{
		throw "No Such Venue in the Ticket Office";
	}
	show.RemoveSeats(&customer);
}

void TicketOffice::ChangeShowTime(ShowAtVenue& show, const char* newDate)
{
	const Venue* temp = show.getVenue();
	int index = getVenueIndex(*temp);
	if (index == -1)
	{
		throw "No Such Venue in the Ticket Office";
	}
	show.setDate(newDate);
}

int TicketOffice::getVenueIndex(const Venue& venue) const 
{
	for (int i = 0; i < m_numOfVenues; i++)
	{
		if (venue == *m_venues[i])
			return i;
	}
	return -1;
}

void TicketOffice::addVenue(Venue& venue) 
{
	if (m_numOfVenues >= MAX_NUM_OF_VENUES)
	{
		throw "Not enougth room for another room";
	}
	m_venues[m_numOfVenues++] = &venue;
}