#include "MusicShow.h"

//const MusicShow& MusicShow::operator=(const MusicShow& other)
//{
//	if (this != &other)
//	{
//		(Show&)(*this) = other; //Call - operator of the parent
//		setMusicalManager(other.getMusicalManager());
//		setSoundCheckTime(other.getSoundCheckTime());
//	}
//	return *this;
//}

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

void MusicShow::makeShow() const
{
	Show::makeShow();
	for(int i = 0; i < m_numOfParticipant; i++)
	{
		Musician* temp = dynamic_cast<Musician*>(m_participators[i]);
		if(temp)
			temp->makeSolo();
	}
}

bool MusicShow::isShowPossible() const
{
	return Show::isShowPossible() && m_musicalManager.getNumOfBeersDrank() > 3;
}

void MusicShow::talkWithProducer()
{
	Show::talkWithProducer();
	m_musicalManager.soberUp();
}

void MusicShow::encore() const
{

}

void MusicShow::drinkBeerAndSmokeCiggarettes()
{

}
