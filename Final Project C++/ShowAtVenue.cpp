#include "ShowAtVenue.h"
#include "Contact.h"

ShowAtVenue::ShowAtVenue (const Show *show, const Venue *venue, const char* date, int ticketPrice) 
{
	m_show =  show;
	m_date = _strdup(date);
	m_venue = venue;
	m_numOfPeople = 0;

	m_seatArr = new Contact**[venue->getNumOfRows()]; //Dynamic allocate the Seats array ROWS

	for (int i = 0; i < venue->getNumOfRows(); i++)
	{
		m_seatArr[i] = new Contact*[venue->getNumOfSeatsPerRow()];
		for (int j = 0; j < venue->getNumOfSeatsPerRow(); j++)
		{
			m_seatArr[i][j] = NULL;					//If seat is not taken the value is NULL
		}
	}
}

ShowAtVenue::ShowAtVenue(const ShowAtVenue& other)
{
	*this = other;
}


ShowAtVenue::~ShowAtVenue()
{
	freeAlloc();
}

void ShowAtVenue::setShow(const Show* show)
{
	this->m_show = show;
}
void ShowAtVenue::setDate(const char* date)
{
	this->m_date = _strdup(date);
}

int		ShowAtVenue::GetTotalSalesValue() const
{
	return m_numOfPeople * m_show->getTicketPrice();
}


void	ShowAtVenue::AddSeats(int numOfTickets, const Contact* customer) throw (NoMoreRoomException)
{//Curently work in very meh way, you probably won't seat with your buddies
	if (isFreeSpace(numOfTickets))
	{
		for (int i = 0; i < m_venue->getNumOfRows(); i++)
		{
			for (int j = 0; j < m_venue->getNumOfSeatsPerRow(); j++)
			{
				if (!m_seatArr[i][j])			//Free Seat :)
				{
					m_seatArr[i][j] = customer;
					m_numOfPeople++;
					if (--numOfTickets == 0)
						return;
				}
			}
		}
	}
	else
	{
		throw NoMoreRoomException(customer);
	}
}

void ShowAtVenue::RemoveSeats(Contact* customer)
{
	for (int i = 0; i < m_venue->getNumOfRows(); i++)
	{
		for (int j = 0; j < m_venue->getNumOfSeatsPerRow(); j++)
		{
			if (m_seatArr[i][j])			//Somebody's seat
			{
				if (*m_seatArr[i][j] == *customer)
				{
					m_seatArr[i][j] = NULL;
					m_numOfPeople--;
				}
			}
		}
	}
}


const Contact** ShowAtVenue::getAllCustumers() const
{
	const Contact ** temp = new Contact*[m_numOfPeople];
	int count =0;
	for (int i = 0; i < m_venue->getNumOfRows(); i++)
	{
		for (int j = 0; j < m_venue->getNumOfSeatsPerRow(); j++)
		{
			if (m_seatArr)
			{
				temp[count] = m_seatArr[i][j];
			}
		}
	}
	return temp;
}


const ShowAtVenue& ShowAtVenue::operator=(const ShowAtVenue& other)
{
	if (this == &other)
	{
		return *this;
	}

	freeAlloc();	//free the current array

	this->m_date = _strdup(other.m_date);
	this->m_numOfPeople = other.m_numOfPeople;
	this->m_show = other.m_show;
	this->m_venue = other.m_venue;

	for (int i = 0; i < other.m_venue->getNumOfRows(); i++)
	{
		m_seatArr[i] = new Contact*[other.m_venue->getNumOfSeatsPerRow()];
		for (int j = 0; j < other.m_venue->getNumOfSeatsPerRow(); j++)
		{
			m_seatArr[i][j] = other.m_seatArr[i][j];					//Copys the Array content
		}
	}

}

void ShowAtVenue::freeAlloc() const
{
	for (int i = 0; i < m_venue->getNumOfRows(); i++)
	{
		delete[] m_seatArr[i];
	}
}

bool ShowAtVenue::isFreeSpace(int numOfTickets) const
{
	return m_numOfPeople + numOfTickets < m_venue->getCapacity();
}

ostream& operator<<(ostream& os, const ShowAtVenue& show)
{
	os << "Show Name :" << show.m_show->getName() << " | At Venue : " << show.m_venue->getVenueName() << endl;
}
istream& operator>>(istream& in, ShowAtVenue& show)
{

}
