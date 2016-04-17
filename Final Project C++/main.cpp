#include "Venue.h"


void main()
{
	Contact c ("Aviad", "050987846", "TA");
	Crew cr ("Enosh", "05167", "PT", 50);
	Crew cr1 = cr;
	cr1.setSalaryPerHour(67);
	Crew cr2 ("David", "05425167", "Beer Sheva", 83);
	Show s ("show", 3, 5, cr, cr2, cr1, 150, 3, 7);
	ShowAtVenue* sav[3];
	for(int i = 0; i < 3; i++)
		*sav[i] = ShowAtVenue(s, "7/5/20016", 150);
	Venue v (c,500, 5, 100, *sav);
}