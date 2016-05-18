#ifndef	 __DANCER__H
#define	 __DANCER__H

#include "Participator.h"

class Dancer : public Participator
{
private:
	bool m_isInjured;
	const int CHANCE_TO_ACROBATICS = 30;
	const int CHANCE_TO_INJURE = 5;

public:
	Dancer(Participator& participator, bool isInjured = false) : Participator(participator), m_isInjured(isInjured) { };
	Dancer() { }

	void setIsInjured(bool isInjured) { m_isInjured = isInjured; }

	bool getIsInjured() const { return m_isInjured; }

	friend istream& operator>>(istream& in, Dancer& dancer);

	virtual void toOs(ostream& os)	const;
	virtual bool isCanPerform()		const;
	
	virtual void doPartInShow();

	void makeInjury()	{ cout << "OMG! " << getName() << " have been injured!" << endl; setIsInjured(true); }
	void recover()		{ cout << "Thank goodness! " << getName() << " have recovered from his injury!" << endl; setIsInjured(false); }
	
	void makeAcrobatics();		//Ego might go up!

	const int CHANCE_TO_RECOVER = 50;
};

#endif// __DANCER__H