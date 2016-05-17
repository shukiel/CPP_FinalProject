#include "Musical.h"
#include "ShowAtVenue.h"
#include "TicketOffice.h"

void main()
{
	TicketOffice* ticketOffice = new TicketOffice(Contact("Shuki Veiss", "1234-567-8888", "roro 3 , toto"));

	Actor** act = new Actor*[5];
	act[0] = new Actor(Participator(Employee(Contact("Moshe Ivgi", "054-6666777", "Ha'Ashachim 8, Tel Aviv"), 1000.0f)), "yulia is the sun and I'm the moon");
	act[1] = new Actor(Participator(Employee(Contact("Sason Gabay", "054-123-4567", "Ha'Pinot 10, Tel Aviv"), 566.9f)), "Yada Yada Yada, this is a very interesting line");
	act[2] = new Actor(Participator(Employee(Contact("Ze'ev Revah", "054-999-9999", "Ha'Tzlaot 15, Tel Aviv"), 123.9f)), "To Be or not to be! This is the question");
	act[3] = new Actor(Participator(Employee(Contact("Zipi Dripo", "054-999-9999", "Ha'Tzlaot 18, Tel Aviv"), 900.0f)), "Turn down the fan I'm too cold :(");

	act[4] = act[3];
	act[4]->setName("Dror Keren"); act[4]->setPhoneNum("054-999-9999"); act[4]->setAddress("Ha'Meshushim 1, Tel Aviv"); act[4]->setSalaryPerHour(789.9f); act[4]->setLine("And they lived happily ever after");


	Musician** mus = new Musician*[3];

	mus[0] = new Musician(Participator(Employee(Contact("Beri Saharof", "066-777-8888", "66 Rock'nroll st. Petach Tikva"), 777.7f)), "Guitar");
	mus[1] = new Musician(Participator(Employee(Contact("Yehuda Poliker", "066-555-6666", "11 Depression st. Rehovot"), 111.1f)), "Boozooki");
	mus[2] = mus[1];
	mus[2]->setName("Idan Raichel"); mus[2]->setPhoneNum("066-111-2222"); mus[2]->setAddress("11 Hofrim st. Natania"); mus[2]->setSalaryPerHour(111.1f); mus[2]->setInstrument("Our nerves");


	Dancer** dan = new Dancer*[2];

	dan[0] = new Dancer(Participator(Employee(Contact("Fred Aster", "054-777-000", "Manchster, England England"), 1.5f)));
	dan[1] = new Dancer(Participator(Employee(Contact("Ohad Naharin", "054-444-6666", "34 Ha'avoda st."), 1.5f)));


	Venue** ven = new Venue*[3];

	ven[0] = new Venue(Contact("Tzipi Pinnes", "077-888-000", "Dizengof 134, TLV"), 1000, 10, 100, "Bet Lesin");
	ven[1] = new Venue(Contact("Yaakov Agmon", "077-1111-2222", "S. Ben Zion 1, TLV"), 1200, 24, 50, "Habima");
	ven[2] = new Venue(Contact("Noam Semel", "077-3333-444", "Shaul Ha'melech 44, TLV"), 800, 20, 40, "Cameri");


	Crew** c = new Crew*[10];

	c[0] = new Crew(Employee(Contact("Keren Grank", "03-3444-222", "momo 4 tlv"), 333.44f));
	c[1] = new Crew(Employee(Contact("Uri Barak", "03-32233-222", "toto 7 tlv"), 222.4f));
	c[2] = new Crew(Employee(Contact("Bambi", "03-34434-222", "gogo 4 tlv"), 123.4f));
	c[3] = new Crew(Employee(Contact("Ziv Lemor", "03-1111-222", "had nes 4 tlv"), 333.5f));
	c[4] = new Crew(Employee(Contact("Mar Pah", "03-123456-77", "yoyo 4 tlv"), 456.3f));


	Show** shows = new Show*[4];

	shows[0] = new TheaterShow(Show("Hair", 120, 600, *c[0], *c[1], *c[3], 200, 0), *c[4]);
	shows[1] = new DanceShow(Show("Swan Lake", 120, 600, *c[4], *c[3], *c[2], 200, 0), *c[1]);
	shows[2] = new MusicShow(Show("U2", 120, 600, *c[2], *c[1], *c[4], 200, 0), *c[3], 150);
	shows[3] = new Musical(Show("Hair", 120, 600, *c[0], *c[1], *c[3], 200, 0), *c[4], *c[3], *c[2], 300);



	//Add participators for the shows!
	for (int i = 0; i < 5; i++)
	{
		shows[0]->addParticipator(*act[i]);
		shows[3]->addParticipator(*act[i]);
	}
	for (int i = 0; i < 2; i++)
	{
		shows[1]->addParticipator(*dan[i]);
		shows[3]->addParticipator(*dan[i]);
	}
	for (int i = 0; i < 3; i++)
	{
		shows[2]->addParticipator(*mus[i]);
		shows[3]->addParticipator(*mus[i]);
	}


	ShowAtVenue** shoAtVen = new ShowAtVenue*[4];

	shoAtVen[1] = new ShowAtVenue(*shows[1], *ven[0], "1/3/2017");
	shoAtVen[2] = new ShowAtVenue(*shows[2], *ven[1], "4/8/1988");
	shoAtVen[3] = new ShowAtVenue(*shows[3], *ven[2], "4/11/1995");
	shoAtVen[0] = new ShowAtVenue(*shows[0], *ven[1], "12/2/1988");


	for (int i = 0; i < 4; i++)
	{
		ticketOffice->ReserveShow(*shoAtVen[i]);
	}


	try{
		ticketOffice->BuyTicket(*shoAtVen[0], 40, Contact("Enosh Cohen", "012-3884-333", "13 Bleecker St. NYC"));
		ticketOffice->BuyTicket(*shoAtVen[0], 20, Contact("Zuhmir ", "012-3884-333", "13 Bleecker St. NYC"));
		ticketOffice->BuyTicket(*shoAtVen[0], 15, Contact("Piposh", "012-3884-333", "13 Bleecker St. NYC"));
		ticketOffice->BuyTicket(*shoAtVen[0], 1, Contact("GOGO", "012-3884-333", "13 Bleecker St. NYC"));
		ticketOffice->BuyTicket(*shoAtVen[0], 44, Contact("sss Cohen", "012-3884-333", "13 Bleecker St. NYC"));
	}
	catch (char * message)
	{
		cout << "\n\n ERROR :: " << message << "\n\n";
	}
}
																															