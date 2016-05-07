
#include "TheaterShow.h"
#include "Actor.h"
TheaterShow::TheaterShow(const Show& other, const Crew& director) : Show(other), m_director(director)
{
	m_numOfParticipant = 0;
}

TheaterShow::TheaterShow(const TheaterShow& other) : Show(other), m_director(other.m_director)
{
	m_actors = new Actor*[other.MAX_NUM_OF_ACTORS];
	for (int i = 0; m_numOfParticipant; i++)
	{
		m_actors[i] = other.m_actors[i];
	}
}

TheaterShow::~TheaterShow()
{
	delete[] m_actors;
}

void TheaterShow::setDirector(const Crew& director){ m_director = director; }


const TheaterShow& TheaterShow::operator=(const TheaterShow& other)
{
	if (this != &other)
	{
		(Show&)(*this) = other; //Call - operator of the parent

		m_actors = new Actor*[other.MAX_NUM_OF_ACTORS];
		for (int i = 0; m_numOfParticipant; i++)
		{
			m_actors[i] = other.m_actors[i];
		}
	}
}

void TheaterShow::addActor(Actor& actor)
{
	if (!(m_numOfParticipant + 1 > MAX_NUM_OF_ACTORS))
	{
		m_actors[m_numOfParticipant] = &actor;
	}
	throw "No more room for this actor :(";
}

ostream& operator<<(ostream& os, const TheaterShow& show)
{
	Show::toOs(os);		//?!?! Why is it not working?! worked fine in Employee
	os << show.getDirector();
	return os;
}
istream& operator>>(istream& in, TheaterShow& show)
{

}

void TheaterShow::makeShow()
{
	cout << "The Show " << m_name << "Is now starting please turn off your phones\n";
	for (int i = 0; i < m_numOfParticipant; i++)
	{
		m_actors[i]->doPartInShow();
	}
}

bool TheaterShow::isShowPossible()
{//Checks if all actors dont have too high Ego Level! And if the Crew is not too drunk

}
void TheaterShow::talkWithProducer()
{//Set All Ego Back to 0 for the participator And number of beers drank to 

}
float TheaterShow::getCost()
{
	float sum = 0;
	for (int i = 0; i < m_numOfParticipant; i++)
	{
		//get the cost of each actor * time he worked
	}
	return  sum + Show::getCost();
}


