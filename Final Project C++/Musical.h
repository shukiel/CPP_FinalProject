#ifndef __MUSICAL_H
#define __MUSICAL_H

#include "DanceShow.h"
#include "MusicShow.h"
#include "TheaterShow.h"

class Musical : public DanceShow, MusicShow, TheaterShow
{
public:
	Musical(const DanceShow& dance, const MusicShow& music, const TheaterShow& theater) : DanceShow(dance), MusicShow(music), TheaterShow(theater) { }

	friend istream& operator>>(istream& in, Musical& show);

	virtual void toOs(ostream& os) const;
	virtual void addParticipator(Participator& participator);

	virtual void makeShow()			const;
	virtual bool isShowPossible()	const;
	virtual void talkWithProducer();
};
#endif