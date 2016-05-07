#ifndef	 __DANCER__H
#define	 __DANCER__H

#include "Participator.h"

class Dancer : public Participator
{
private:
	bool m_isInjured;

public:
	Dancer(Participator& participator, bool isInjured = false) : Participator(participator), m_isInjured(isInjured) { };

	void setIsInjured(bool isInjured) { m_isInjured = isInjured; }

	bool getIsInjured() const { return m_isInjured; }

	friend istream& operator>>(istream& in, Dancer& dancer);
	
	void makeInjury() { setIsInjured(true); }

	virtual void doPartInShow() const;
	virtual void toOs(ostream& os) const; 
};

#endif// __DANCER__H