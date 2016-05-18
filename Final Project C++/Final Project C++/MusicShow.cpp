#include "MusicShow.h"
#include "Exceptions.h"

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

void MusicShow::addParticipator(Participator& participator) throw (GenericException)
{
	if (m_numOfParticipant < MAX_NUM_OF_MUSICIANS)
	{
		if (typeid(participator) == typeid(Musician))
		{
			participator.setNumOfWorkingHours(m_soundCheckTime);
			Show::addParticipator(participator);
		}

		else
			 new GenericException( "The participant is not a musician.");
	}

	else
		 new GenericException( "No more room for this musician :(");
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

void MusicShow::makeShow()
{
	loadInTime();
	Show::makeShow();
	m_musicalManager.setNumOfWorkingHours(m_musicalManager.getNumOfWorkingHours() + m_duration);
}