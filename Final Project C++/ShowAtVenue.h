#ifndef __SHOWATVENUE_H
#define __SHOWATVENUE_H


#include <iostream>
#include "Exceptions.h"


using namespace std;

class Contact;			//Forward declaretion
class Venue;			//Forward declaration 
class Show;				//Forward declaration

class ShowAtVenue
{
private:
	const Show*		m_show;					//Pointer to the Show should not be able to change it
	const Venue*	m_venue;				//Pointer to the Venue of the Show should not be able to change it
	char*			m_date;
	const Contact***      m_seatArr;		//2D array of pointers to Seats(Contacts)
	int				m_numOfPeople;

	bool		isFreeSpace(int numOfTickets) const;
	void		freeAlloc() const;


public:
	ShowAtVenue (const Show *show, const Venue *venue, const char* date, int ticketPrice);
	ShowAtVenue (const ShowAtVenue& other);
	ShowAtVenue() { }
	~ShowAtVenue();

	void setShow(const Show* show);
	void setDate(const char* date);

	int getNumOfPeopleInAudience() { return m_numOfPeople; } const

	const Show& getShow() const { return *m_show; }
	const char* getDate() const { return m_date; }

	float GetTotalSalesValue() const;
	float getProfit() const;
	const Venue* getVenue() const { return m_venue; }


	void AddSeats(int numOfTickets, const Contact *customer);
	void RemoveSeats(Contact* customer);
	const Contact** getAllCustumers() const;  //Will return a array of pointers to all the customers in the show FREE

	const bool operator==(const ShowAtVenue& other)
		{ return ((this->m_show == other.m_show) && m_venue == other.m_venue && strcmp(m_date,other.m_date));};
	const ShowAtVenue& operator=(const ShowAtVenue& other);
	friend ostream& operator<<(ostream& os, const ShowAtVenue& show);
	friend istream& operator>>(istream& in, ShowAtVenue& show);
};

#endif