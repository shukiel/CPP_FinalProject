#ifndef	 __DANCER__H
#define	 __DANCER__H

#include "Participator.h"

#define CHANCE_TO_ACROBATICS 0.2f
#define CHANCE_TO_INJURE 0.1f

class Dancer : public Participator
{
private:
	bool m_isInjured;

public:
	Dancer(Participator& participator, bool isInjured = false) : Participator(participator), m_isInjured(isInjured) { };
	Dancer() { }

	void setIsInjured(bool isInjured) { m_isInjured = isInjured; }

	bool getIsInjured() const { return m_isInjured; }

	friend istream& operator>>(istream& in, Dancer& dancer);
	
	void makeInjury() { cout << "OMG! " << getName() << " have been injured!" << endl; setIsInjured(true); }
	void recover() { cout << "Thank goodness! " << getName() << " have recovered from his injury!" << endl; setIsInjured(false); }
	void makeAcrobatics();		//Ego might go up!

	virtual void doPartInShow();

	virtual void toOs(ostream& os) const; 

	virtual bool isCanPerform() const { return Participator::isCanPerform() && !m_isInjured; }
};

#endif// __DANCER__H