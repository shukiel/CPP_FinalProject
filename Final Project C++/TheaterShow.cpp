#include "TheaterShow.h"

//TheaterShow::TheaterShow(const TheaterShow& other) : Show(other), m_director(other.m_director)
//{
//	m_actors = new Actor*[MAX_NUM_OF_ACTORS];
//	for (int i = 0; i < m_numOfParticipant; i++)
//	{
//		m_actors[i] = other.m_actors[i];
//	}
//}
//
//TheaterShow::~TheaterShow()
//{
//	delete[] m_actors;
//}

//const TheaterShow& TheaterShow::operator=(const TheaterShow& other)
//{
//	if (this != &other)
//	{
//		(Show&)(*this) = other; //Call - operator of the parent
//		setDirector(other.getDirector());
//	}
//	return *this;
//}

void TheaterShow::addParticipator(Actor& actor)
{
	if (!(m_numOfParticipant + 1 > MAX_NUM_OF_ACTORS))
	{
		actor.setNumOfWorkingHours(m_duration);
		Show::addParticipator(actor);
	}
	throw "No more room for this actor :(";
}

void TheaterShow::toOs(ostream& os) const
{
	Show::toOs(os);	
	os << "Director: " << getDirector() << endl;
}

istream& operator>>(istream& in, TheaterShow& show)
{
	in >> (Show&)show >> (Crew&)show.m_director;
	return in;
}

void TheaterShow::makeShow() const
{
	Show::makeShow();
}

bool TheaterShow::isShowPossible() const
{//Checks if all actors dont have too high Ego Level! And if the Crew is not too drunk
	return Show::isShowPossible() && m_director.getNumOfBeersDrank() > 3;
}

void TheaterShow::talkWithProducer()
{//Set All Ego Back to 0 for the participator And number of beers drank to 
	Show::talkWithProducer();
	m_director.soberUp();
}