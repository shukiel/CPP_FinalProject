#ifndef __SHOWATVENUE_H
#define __SHOWATVENUE_H

#include "Show.h"
#include "Contact.h"

class ShowAtVenue
{
private:
	Show show;
	char* date;
	int ticketPrice;

	const bool isFreeSpace(int numOfTickets) const;

public:
	ShowAtVenue(Show show, char* date, int ticketPrice);
	ShowAtVenue(const ShowAtVenue& other);
	~ShowAtVenue();

	void setShow(Show show);
	void setDate(char* date);
	void setTicketPrice(int ticketPrice);

	const Show getShow() const {return show;}
	const char* getDate() const {return date;}
	const int getTicketPrice() const {return ticketPrice;}

	const int GetTotalSalesValue() const;
	void AddSeats(int numOfTickets, Contact customer);
	const Contact* getAllCustumers() const;

	void show() const;

	const ShowAtVenue& operator=(const ShowAtVenue& other);
	friend ostream& operator<<(ostream& os, const ShowAtVenue& show);
	friend istream& operator>>(istream& in, ShowAtVenue& show);
}

#endif