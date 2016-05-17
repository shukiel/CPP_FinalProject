#include "MusicShow.h"

istream& operator>>(istream& in, MusicShow& show)
{
	in >> (Show&)show >> (Crew&)show.m_musicalManager >> show.m_soundCheckTime;
	return in;
}

void MusicShow::toOs(ostream& os) const
{
	Show::toOs(os);	
	os << "Musical manager: " << getMusicalManager() << "Sound check time: " << getSoundCheckTime() << endl;
}

void MusicShow::addParticipator(Participator& participator) throw (const char*)
{
	if (m_numOfParticipant < MAX_NUM_OF_MUSICIANS)
	{
		if (typeid(participator) == typeid(Musician))
		{
			participator.setNumOfWorkingHours(m_soundCheckTime);
			Show::addParticipator(participator);
		}

		else
			throw "The participant is not a musician.";
	}

	else
		throw "No more room for this musician :(";
}

void MusicShow::talkWithProducer()
{
	Show::talkWithProducer();
	m_musicalManager.soberUp();
}

void MusicShow::encore() 
{
	cout << "Thank you so much you guys are amazing audience!" << endl;
	makeShow();
}

void MusicShow::loadInTime()
{
	Show::loadInTime();
	m_musicalManager.drinkBeers();
}