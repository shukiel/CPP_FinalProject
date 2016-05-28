#include "Venue.h"
#include "ShowAtVenue.h"

const Venue& Venue::operator=(const Venue& other)
{
	if (this != &other)
	{
		copyEverythingButContact(other);
		m_contactDetails = other.m_contactDetails;
	}
	return *this;
}

void Venue::operator+=(const ShowAtVenue& show) throw (GenericException)	//adds a show to the venue
{
	if (m_showAtVenue.size() < MAX_NUM_OF_SHOWS) //Have room for one more show
		m_showAtVenue.push_back(show);
	else 
		throw GenericException("TooMuchShowsException");
}

void Venue::operator-=(const ShowAtVenue& show) 
{
	vector<ShowAtVenue>::iterator it = m_showAtVenue.begin();
	vector<ShowAtVenue>::iterator itEnd = m_showAtVenue.end();
	vector<ShowAtVenue>::iterator itFind = find(it, itEnd, show);
	if (itFind != itEnd)
		m_showAtVenue.erase(itFind);
}//removes a show from a venue

ostream& operator<<(ostream& os, const Venue& venue)
{
	os << "Venue Name : " << venue.m_name << ", Capacity: " << venue.m_capacity << endl << "Contact " << venue.m_contactDetails << endl;
	if (venue.m_showAtVenue.size() > 0)
	{
		os << "Shows at venue: " << endl;
		vector<ShowAtVenue>::const_iterator it = venue.m_showAtVenue.begin();
		vector<ShowAtVenue>::const_iterator itEnd = venue.m_showAtVenue.end();
		for (; it != itEnd; ++it)
			os << *it << endl;
	}
	return os;
}

istream& operator>>(istream& in, Venue& venue)
{
	in >> venue.m_name >> (Contact&)venue.m_contactDetails >> venue.m_capacity >> venue.m_numOfRows >> venue.m_numOfSeatsPerRow;
	return in;
}

int Venue::getSalesRevenue() const //Gets the profit of the show
{
	int sum = 0 ;
	vector<ShowAtVenue>::const_iterator it = m_showAtVenue.begin();
	vector<ShowAtVenue>::const_iterator itEnd = m_showAtVenue.end();
	for (; it != itEnd; ++it)
		sum += (*it).getProfit();
	return sum;
}

void Venue::copyEverythingButContact(const Venue& other)
{
	m_capacity = other.m_capacity;
	m_name = other.m_name;
	m_numOfRows = other.getNumOfRows();
	m_numOfSeatsPerRow = other.getNumOfSeatsPerRow();

	m_showAtVenue.clear();
	m_showAtVenue.reserve(other.m_showAtVenue.size());

	vector<ShowAtVenue>::const_iterator it = other.m_showAtVenue.begin();
	vector<ShowAtVenue>::const_iterator itEnd = other.m_showAtVenue.end();
	for (; it != itEnd; ++it)
		m_showAtVenue.push_back(*it);
}

void Venue::makeShow()
{
	vector<ShowAtVenue>::iterator it = m_showAtVenue.begin();
	vector<ShowAtVenue>::iterator itEnd = m_showAtVenue.end();
	for (; it != itEnd; ++it)
		(*it).makeShow();
}

vector<ShowAtVenue>::iterator Venue::findShow(const ShowAtVenue& show)
{
	vector<ShowAtVenue>::iterator it = m_showAtVenue.begin();
	vector<ShowAtVenue>::iterator itEnd = m_showAtVenue.end();
	vector<ShowAtVenue>::iterator itFind = find(it, itEnd, show);
	return itFind;
}