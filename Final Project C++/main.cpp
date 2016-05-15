#include "Venue.h"
#include "Crew.h"
#include "Actor.h"
#include "Musician.h"
#include "Dancer.h"
#include "Musical.h"
#include "ShowAtVenue.h"

void main()
{
	Dancer c(Participator(Employee(Contact("sace", "023654189", "WDC"), 35.2f)));
	Actor c1(Participator(Employee(Contact("sace", "023654189", "WDC"), 35.2f)), "bla bla bla...");
	Musician c2(Participator(Employee(Contact("sace", "023654189", "WDC"), 35.2f)), "Drums.");
	//Dancer c1 = c;
	//c1.setName("fd");
	//c1.setNumOfWorkingHours(5);
	//
	//cout << c << endl << c1 << endl;

	//if (c1.getIsInjured())
	//	c1.recover();
	//else
	//	c1.doPartInShow();

	//cout << c1 << endl;

	Crew cr (Employee(Contact("Enosh", "0541676943", "PT"), 52.5));
	Crew cr1 = cr;
	cr1.setSalaryPerHour(67);
	cr1.setName("Nir");
	Crew cr2 (Employee(Contact("David", "0542516745", "Beer Sheva"), 83));
	Crew cr3 (Employee(Contact("Miki", "0523648571", "NYC"), 46.2f));

	//Show s("Hamlet", 3, 5, cr, cr1, cr2, 150, 5);
	Musical th(Show("Hamlet", 4, 2, cr, cr1, cr2, 150, 5), cr3, cr3, cr3, 6);

	th.addParticipator(c);
	th.addParticipator(c1);
	th.addParticipator(c2);

	//cout << th;

	//cout << s.getCost() << endl;

	//try{
	//	th.makeShow();
	//	th.talkWithProducer();
	//}
	//catch (const char* msg)
	//{
	//	cout << msg << endl;
	//	th.talkWithProducer();
	//}

	//th.dancerInjured(c);

	//cout << th;

	//Show s1 = s;
	//s1.setName("fdlkj");

	//if (s != s1)
	//	cout << "wow" << endl;
	//else
	//	cout << "not wow" << endl;

	//cout << s;

	//th.addParticipator(Actor(Participator(Employee(Contact("Yossi", "0234915748", "LA"), 53.4f)), "Never to speak of this that you have seen, Swear by my sword."));

	Contact con("Yuri", "0123456789", "SomeWhere");
	Contact con1("Avi", "0123456789", "SomeWhere");
	Contact con2("David", "0123456789", "SomeWhere");

	Venue v(con, 500, 5, 100, "Habima");

	ShowAtVenue sav(th, v, "06/04/2016");
	sav.AddSeats(8, &con);
	sav.AddSeats(45, &con1);
	sav.AddSeats(2, &con2);

	v.AddShow(sav);

	cout << v;
}