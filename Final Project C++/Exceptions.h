//In this file we'll declare and implement our exceptions classes
#ifndef __EXCEPTIONS_H
#define __EXCEPTIONS_H

#include <iostream>
#include <fstream>
#include "Contact.h"

#define LOG_FILE_NAME "log.txt"

//Forward declarations
class ShowAtVenue;
class Contact;


class Exception //Abstract class - > Super class for all exceptions
{
public :
	virtual void printErrorToConsole() = 0;
	virtual void printErrorToLogFile() = 0;
};
class NoMoreRoomException : public Exception
{
public:
	const Contact* m_customer;
	NoMoreRoomException(const Contact* customer) : m_customer(customer){}

	void printErrorToConsole()
	{
		cout << "This Customer have no free spot -> " << *m_customer << endl;
	}
	
	void printErrorToLogFile()
	{
		ofstream log(LOG_FILE_NAME, ios::app);
		log << "This Customer have no free spot -> " << *m_customer << endl;
		log.close();
	}
};

class TooMuchShowsException : public Exception
{
private:
	const ShowAtVenue* m_show;
public:
	TooMuchShowsException(const ShowAtVenue &show) : m_show(&show) {}

	void printErrorToConsole()
	{
		cout << "This Show have no free spot -> " << m_show << endl;
	}

	void printErrorToLogFile()
	{
		ofstream log(LOG_FILE_NAME, ios::app);
		log << "This Show have no free spot -> " << m_show << endl;
		log.close();
	}

};


#endif //__EXCEPTIONS_H