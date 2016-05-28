#include "ShowAtVenue.h"
#include "Exceptions.h"
#include <algorithm>

ShowAtVenue::ShowAtVenue(Show* show, const Venue& venue, const string& date) : m_venue(venue)
{
	m_show = show;
	setDate(date);
	m_numOfPeople = 0;

	m_seatArr.reserve(venue.getNumOfRows());
	vector<vector<Contact>>::iterator it = m_seatArr.begin();
	vector<vector<Contact>>::iterator itEnd = m_seatArr.end();
	for (; it != itEnd; ++it)
		(*it).reserve(venue.getNumOfSeatsPerRow());
}

void ShowAtVenue::AddSeats(int numOfTickets, const Contact& customer) throw (GenericException)
{//Curently work in very meh way, you probably won't seat with your buddies
	if (isFreeSpace(numOfTickets))
	{
		vector<vector<Contact>>::iterator it = m_seatArr.begin();
		vector<vector<Contact>>::iterator itEnd = m_seatArr.end();
		for (; it != itEnd; ++it)
		{
			vector<Contact>::iterator it2 = (*it).begin();
			vector<Contact>::iterator itEnd2 = (*it).end();
			for (; it2 != itEnd2; ++it2)
				if ((*it2).getName().compare("") != 0)			//Free Seat :)
				{
					(*it2) = *(new Contact(customer));
					m_numOfPeople++;
					if (--numOfTickets == 0)
						return;
				}
		}
	}
	else
		throw GenericException("NoMoreRoomException");
}

void ShowAtVenue::RemoveSeats(const Contact& customer)
{
	vector<vector<Contact>>::iterator it = m_seatArr.begin();
	vector<vector<Contact>>::iterator itEnd = m_seatArr.end();
	for (; it != itEnd; ++it)
	{
		vector<Contact>::iterator it2 = (*it).begin();
		vector<Contact>::iterator itEnd2 = (*it).end();
		for (; it2 != itEnd2; ++it2)
			if ((*it2).getName().compare("") != 0)			//Somebody's seat
				if ((*it2) == customer)
				{
					(*it2) = *(new Contact());
					m_numOfPeople--;
				}
	}
}

Contact** const ShowAtVenue::getAllCustumers() const
{
	Contact ** temp = new Contact*[m_numOfPeople];	
	int count = 0;
	vector<vector<Contact>>::const_iterator it = m_seatArr.begin();
	vector<vector<Contact>>::const_iterator itEnd = m_seatArr.end();
	for (; it != itEnd; ++it)
	{
		vector<Contact>::const_iterator it2 = (*it).begin();
		vector<Contact>::const_iterator itEnd2 = (*it).end();
		for (; it2 != itEnd2; ++it2)
			if ((*it2).getName().compare("") == 0)
				*(temp[count++]) = (*it2);
	}
	return temp;
}

const ShowAtVenue& ShowAtVenue::operator=(const ShowAtVenue& other)
{
	if (this == &other)
		return *this;

	setDate(other.m_date);
	m_numOfPeople = other.m_numOfPeople;
	m_show = other.m_show;
	m_venue = other.m_venue;

	m_seatArr.reserve(other.m_venue.getNumOfRows());
	vector<vector<Contact>>::iterator it = m_seatArr.begin();
	vector<vector<Contact>>::iterator itEnd = m_seatArr.end();
	vector<vector<Contact>>::const_iterator it2 = other.m_seatArr.begin();
	vector<vector<Contact>>::const_iterator itEnd2 = other.m_seatArr.end();
	for (; it != itEnd || it2 != itEnd2; ++it, ++it2)
	{
		vector<Contact>::iterator it3 = (*it).begin();
		vector<Contact>::iterator itEnd3 = (*it).end();
		vector<Contact>::const_iterator it4 = (*it2).begin();
		vector<Contact>::const_iterator itEnd4 = (*it2).end();
		(*it).clear();
		(*it).reserve(other.m_venue.getNumOfSeatsPerRow());
		for (; it3 != itEnd3 || it4 != itEnd4; ++it3, ++it4)
			(*it3) = (*it4);
	}

	return *this;
}

ostream& operator<<(ostream& os, const ShowAtVenue& show)
{
	os << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
	os << "Show Name :" << show.m_show->getName() << " | At Venue : " << show.m_venue.getVenueName() << endl;
	os << "Number of people in Audience: " << show.getNumOfPeopleInAudience() << endl;
	os << "Show Cost " << (show.getShow()).getCost() << " Show Income: " << show.GetTotalSalesValue() << endl;
	os << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
	return os;
}

istream& operator>>(istream& in, ShowAtVenue& show)
{
	return in;
}

void ShowAtVenue::makeShow()
{
	m_show->makeShow();
}