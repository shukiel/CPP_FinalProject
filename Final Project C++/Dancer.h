#ifndef	 __DANCER__H
#define	 __DANCER__H

#include "Participator.h"

class Dancer : public Participator
{
private:
	bool m_isInjured;
	const float CHANCE_TO_ACROBATICS = 0.2f;
	const float CHANCE_TO_INJURE = 0.1f;

public:
	Dancer(Participator& participator, bool isInjured = false) : Participator(participator), m_isInjured(isInjured) { };

	void setIsInjured(bool isInjured) { m_isInjured = isInjured; }

	bool getIsInjured() const { return m_isInjured; }

	friend istream& operator>>(istream& in, Dancer& dancer);
	
	void makeInjury() { setIsInjured(true); }
	void makeAcrobatics();		//Ego might go up!

	virtual void doPartInShow()	;
	virtual void toOs(ostream& os)	const; 

	bool isCanPerform() const { return Participator::isCanPerform() && !m_isInjured; }
};

#endif// __DANCER__H