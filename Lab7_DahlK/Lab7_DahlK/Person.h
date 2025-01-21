#pragma once
#include "Date.h"

class Person
{
public:
	Person();

	Person(std::string, std::string, Date, Date, int);

	~Person();

	// setter functions
	void setfirstName(std::string);
	void setlastName(std::string);
	void sethiringDate(Date);
	void setbirthday(Date);
	void setid(int);

	// getter functions
	std::string getfirstName() const;
	std::string getlastName() const;
	Date gethiringDate() const; 
	Date getbirthday() const;
	int getid() const;
private:
	// private variables
	std::string firstName, lastName;
	Date hiringDate, birthday;
	int id;
};