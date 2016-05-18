#include "ShowAtVenue.h"
#include "Exceptions.h"

ShowAtVenue::ShowAtVenue(Show& show, const Venue& venue, const char* date) : m_venue(venue), m_date(NULL)
{
	Musical* tempM = dynamic_cast<Musical*>(&show);
	if (tempM)
		m_show = new Musical(*tempM);
	else
	{
		DanceShow* tempD = dynamic_cast<DanceShow*>(&show);
		if (tempD)
			m_show = new DanceShow(*tempD);
		else
		{
			TheaterShow* tempT = dynamic_cast<TheaterShow*>(&show);
			if (tempT)
				m_show = new TheaterShow(*tempT);
			else
			{
				MusicShow* temp = dynamic_cast<MusicShow*>(&show);
				if (temp)
					m_show = new MusicShow(*temp);
			}
		}
	}

	m_date = _strdup(date);
	m_numOfPeople = 0;

	m_seatArr = new Contact**[venue.getNumOfRows()]; //Dynamic allocate the Seats array ROWS

	for (int i = 0; i < venue.getNumOfRows(); i++)
	{
		m_seatArr[i] = new Contact*[venue.getNumOfSeatsPerRow()];
		for (int j = 0; j < venue.getNumOfSeatsPerRow(); j++)
			m_seatArr[i][j] = NULL;					//If seat is not taken the value is NULL
	}
}

void ShowAtVenue::AddSeats(int numOfTickets, const Contact& customer) throw (GenericException)
{//Curently work in very meh way, you probably won't seat with your buddies
	if (isFreeSpace(numOfTickets))
	{
		for (int i = 0; i < m_venue.getNumOfRows(); i++)
			for (int j = 0; j < m_venue.getNumOfSeatsPerRow(); j++)
				if (!m_seatArr[i][j])			//Free Seat :)
				{
					m_seatArr[i][j] = new Contact(customer);
					m_numOfPeople++;
					if (--numOfTickets == 0)
						return;
				}
	}
	else
		throw GenericException("NoMoreRoomException");
}

void ShowAtVenue::RemoveSeats(const Contact& customer)
{
	for (int i = 0; i < m_venue.getNumOfRows(); i++)
		for (int j = 0; j < m_venue.getNumOfSeatsPerRow(); j++)
			if (m_seatArr[i][j])			//Somebody's seat
				if (*m_seatArr[i][j] == customer)
				{
					m_seatArr[i][j] = NULL;
					m_numOfPeople--;
				}
}

Contact** const ShowAtVenue::getAllCustumers() const
{
	Contact ** temp = new Contact*[m_numOfPeople];	
	int count = 0;
	for (int i = 0; i < m_venue.getNumOfRows(); i++)
		for (int j = 0; j < m_venue.getNumOfSeatsPerRow(); j++)
			if (m_seatArr)
				temp[count] = m_seatArr[i][j];
	return temp;
}

const ShowAtVenue& ShowAtVenue::operator=(const ShowAtVenue& other)
{
	if (this == &other)
		return *this;

	freeAlloc();	//free the current array

	if (!m_date)
		delete[] m_date;
	m_date = _strdup(other.m_date);
	m_numOfPeople = other.m_numOfPeople;
	m_show = other.m_show;
	m_venue = other.m_venue;

	m_seatArr = new Contact**[other.m_venue.getNumOfRows()];
	for (int i = 0; i < other.m_venue.getNumOfRows(); i++)
	{
		m_seatArr[i] = new Contact*[other.m_venue.getNumOfSeatsPerRow()];
		for (int j = 0; j < other.m_venue.getNumOfSeatsPerRow(); j++)
			m_seatArr[i][j] = other.m_seatArr[i][j];					//Copys the Array content
	}
	return *this;
}

void ShowAtVenue::freeAlloc()
{
	for (int i = 0; i < m_venue.getNumOfRows(); i++)
		if (!m_seatArr[i])
			delete[] m_seatArr[i];
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
	Musical* tempM = dynamic_cast<Musical*>(m_show);
	if (tempM)
	{
		tempM->makeShow();
		return;
	}

	DanceShow* tempD = dynamic_cast<DanceShow*>(m_show);
	if (tempD)
	{
		tempD->makeShow();
		return;
	}

	TheaterShow* tempT = dynamic_cast<TheaterShow*>(m_show);
	if (tempT)
	{
		tempT->makeShow();
		return;
	}

	MusicShow* temp = dynamic_cast<MusicShow*>(m_show);
	if (temp)
		temp->makeShow();
}