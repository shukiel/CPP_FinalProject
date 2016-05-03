#include "Venue.h"


void main()
{
	Contact c ("Aviad", "050987846", "TA");
	Crew cr ("Enosh", "05167", "PT", 50);
	Crew cr1 = cr;
	cr1.setSalaryPerHour(67);
	Crew cr2 ("David", "05425167", "Beer Sheva", 83);
	ShowAtVenue* sav[3];

	//Venue v(c,500, 5, 100, *sav);
}