#include "Musical.h"

istream& operator>>(istream& in, Musical& show)
{
	in >> (DanceShow&)show >> (MusicShow&)show >> (TheaterShow&)show;
	return in;
}

void Musical::toOs(ostream& os) const
{
	DanceShow::toOs(os);
	MusicShow::toOs(os);
	TheaterShow::toOs(os);
}

void Musical::addParticipator(Participator& participator)
{
	Dancer* tempD = dynamic_cast<Dancer*>(&participator);
	if(tempD)
	{
		DanceShow::addParticipator(*tempD);
		return;
	}

	Musician* tempM = dynamic_cast<Musician*>(&participator);
	if(tempM)
	{
		MusicShow::addParticipator(*tempM);
		return;
	}

	Actor* tempA = dynamic_cast<Actor*>(&participator);
	if(tempA)
		TheaterShow::addParticipator(*tempA);
}

void Musical::makeShow() const
{
	DanceShow::makeShow();
	MusicShow::makeShow();
	TheaterShow::makeShow();
}

bool Musical::isShowPossible() const
{
	return DanceShow::isShowPossible() && MusicShow::isShowPossible() && TheaterShow::isShowPossible();
}

void Musical::talkWithProducer()
{
	DanceShow::talkWithProducer();
	MusicShow::talkWithProducer();
	TheaterShow::talkWithProducer();
}