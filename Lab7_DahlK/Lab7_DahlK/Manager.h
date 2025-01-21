#pragma once
#include "Person.h"

class Manager : public Person
{
	friend std::ostream& operator<<(std::ostream& output, const Manager& m);
public:
	Manager();

	Manager(std::string, Date, float);

	~Manager();

	// setter functions
	void settitle(std::string);
	void setpromotion(Date);
	void setsalary(float);

	// getter functions
	std::string gettitle() const;
	Date getpromotion() const;
	float getsalary() const;

	bool operator==(const Manager&);
	bool operator!=(const Manager&);

private:
	// private variables
	std::string title;
	Date promotion;
	float salary;
};