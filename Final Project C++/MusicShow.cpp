#include "MusicShow.h"

istream& operator>>(istream& in, MusicShow& show)
{
	in >> (Show&)show >> (Crew&)show.m_musicalManager >> show.m_soundCheckTime;
	return in;
}

void MusicShow::toOs(ostream& os) const
{
	Show::toOs(os);	
	os << "Musical manager: " << getMusicalManager() << ", Sound check time: " << getSoundCheckTime() << endl;
}

void MusicShow::addParticipator(Musician& musician)
{
	if (!(m_numOfParticipant + 1 > MAX_NUM_OF_MUSICIANS))
	{
		musician.setNumOfWorkingHours(m_duration + m_soundCheckTime);
		Show::addParticipator(musician);
	}
	throw "No more room for this musician :(";
}

bool MusicShow::isShowPossible() const
{
	return Show::isShowPossible() && !(m_musicalManager.isTooDrunk());
}

void MusicShow::talkWithProducer()
{
	Show::talkWithProducer();
	m_musicalManager.soberUp();
}

void MusicShow::encore() 
{
	cout << "Thank you so much you guys are amazing audience!";
	this->makeShow();
}

void MusicShow::loadInTime()
{
	Show::loadInTime();
	m_musicalManager.drinkBeers();
}
