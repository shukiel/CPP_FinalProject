#include "Venue.h"
#include "ShowAtVenue.h"

Venue::Venue(const Contact& contactDetails, int capacity, int numOfRows, int numOfSeatsPerRow, const char* name) :
	m_contactDetails(contactDetails), m_capacity(capacity), m_numOfRows(numOfRows), m_numOfSeatsPerRow(m_numOfSeatsPerRow)
{
	m_numOfShows = 0;
	this->m_showAtVenue = new ShowAtVenue[MAX_NUM_OF_SHOWS];
	m_name = _strdup(name);
}
Venue::Venue(const Venue& other) : m_contactDetails(other.m_contactDetails), m_showAtVenue(NULL)
{
	this->copyEverythingButContact(other);
}

Venue::~Venue()
{
	delete[] m_name;
	delete[] m_showAtVenue;
}

const Venue& Venue::operator=(const Venue& other)
{
	if (this != &other)
	{
		this->copyEverythingButContact(other);
		this->m_contactDetails = other.m_contactDetails;
	}
	return *this;
}
bool Venue::operator==(const Venue& other) const
{
	return (strcmp(this->m_name, other.m_name) && m_contactDetails == other.getContactDetails());
}

bool Venue::operator!=(const Venue& other) const
{
	return !(*this == other);
}

//bool operator>(const Venue& other) const;
//bool operator<(const Venue& other) const;
//bool operator>=(const Venue& other) const;
//bool operator<=(const Venue& other) const;

void Venue::operator+=(const ShowAtVenue& show) throw (TooMuchShowsException)	//adds a show to the venue
{
	if (!(m_numOfShows + 1 > MAX_NUM_OF_SHOWS)) //Have room for one more show
	{
		m_showAtVenue[m_numOfShows++] = *(new ShowAtVenue(show));
	}
	else 
		throw(TooMuchShowsException(show));
}

void Venue::operator-=(const ShowAtVenue& show) 
{
	int i;
	for (i = 0; i < m_numOfShows; i++)
	{
		if (m_showAtVenue[i] == show)
		{
			m_numOfShows--;
			break;
		}
	}
	for (; i < m_numOfShows; i++)	//close the holes
	{
		m_showAtVenue[i] = m_showAtVenue[i + 1];
	}
}//removes a show from a venue

ostream& operator<<(ostream& os, const Venue& venue)
{
	os << "Venue Name : " << venue.m_name << "Contact : " << venue.m_contactDetails;
	return os;
}
istream& operator>>(istream& in, Venue& venue)
{
	in >> venue.m_name >> (Contact&)venue.m_contactDetails >> venue.m_capacity >> venue.m_numOfRows >> venue.m_numOfSeatsPerRow;
	return in;
}

float	Venue::getSalesRevenue() const //Gets the profit of the show
{
	float sum = 0 ;
	for (int i = 0; i < m_numOfShows; i++)
	{
		sum += m_showAtVenue[i].getProfit();
	}
	return sum;
}

void Venue::copyEverythingButContact(const Venue& other)
{
	m_capacity = other.m_capacity;
	m_name = _strdup(other.m_name);
	m_numOfRows = other.getNumOfRows();
	m_numOfSeatsPerRow = other.getNumOfSeatsPerRow();
	m_numOfShows = other.m_numOfShows;

	delete[] m_showAtVenue;
	m_showAtVenue = new ShowAtVenue[MAX_NUM_OF_SHOWS];

	for (int i = 0; i < other.m_numOfShows;i++)
	{
		m_showAtVenue = other.m_showAtVenue;
	}
}
