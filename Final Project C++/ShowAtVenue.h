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

	bool isFreeSpace(int numOfTickets) const;

public:
	ShowAtVenue(const Show& show, const char* date, int ticketPrice);
	ShowAtVenue(const ShowAtVenue& other);
	~ShowAtVenue();

	void setShow(const Show& show);
	void setDate(const char* date);
	void setTicketPrice(int ticketPrice) { this->ticketPrice = ticketPrice; }

	const Show& getShow() const { return show; }
	const char* getDate() const { return date; }
	int getTicketPrice() const { return ticketPrice; }

	int GetTotalSalesValue() const;
	void AddSeats(int numOfTickets, const Contact& customer);
	const Contact* getAllCustumers() const;

	const ShowAtVenue& operator=(const ShowAtVenue& other);
	friend ostream& operator<<(ostream& os, const ShowAtVenue& show);
	friend istream& operator>>(istream& in, ShowAtVenue& show);
}

#endif