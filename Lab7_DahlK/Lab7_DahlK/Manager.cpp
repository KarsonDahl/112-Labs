#include "Manager.h"
#include <iomanip>

Manager::Manager()
{
	Date nullD(0, 0, 0);
	settitle("");
	setpromotion(nullD);
	setsalary(0);
}

Manager::Manager(std::string t, Date p, float s)
{
	settitle(t);
	setpromotion(p);
	setsalary(s);
}

Manager::~Manager() { }

void Manager::settitle(std::string t) { title = t; }
void Manager::setpromotion(Date p) { promotion = p; }
void Manager::setsalary(float s) { salary = s; }

std::string Manager::gettitle() const { return title; }
Date Manager::getpromotion() const { return promotion; }
float Manager::getsalary() const { return salary; }

std::ostream& operator<<(std::ostream& output, const Manager& m)
{
	// TODO: insert return statement here
	std::cout << std::setw(30) << " First Name:       " << std::setw(20) << std::right << m.getfirstName() << std::endl;
	std::cout << std::setw(30) << " Last Name:        " << std::setw(20) << std::right << m.getlastName() << std::endl;
	std::cout << std::setw(30) << " Birthday:         " << std::setw(12) << std::right << m.getbirthday() << std::endl;
	std::cout << std::setw(30) << " Hiring Date:      " << std::setw(12) << std::right << m.gethiringDate() << std::endl;
	std::cout << std::setw(30) << " ID:               " << std::setw(20) << std::right << m.getid() << std::endl;
	std::cout << std::setw(30) << " Promotion Date:   " << std::setw(12) << std::right << m.getpromotion() << std::endl;
	std::cout << std::setw(30) << " Salary:           " << std::setw(20) << std::right << m.getsalary() << std::endl;
	std::cout << std::setw(30) << " Title:            " << std::setw(20) << std::right << m.gettitle() << std::endl << std::endl;
	return output;
}

bool Manager::operator==(const Manager& m)
{
	if (this->salary == m.salary && this->promotion == m.promotion && this->title == m.title)
		return true;
	else
		return false;
}

bool Manager::operator!=(const Manager& m)
{
	if (this->salary != m.salary || this->promotion != m.promotion || this->title != m.title)
		return true;
	else
		return false;
}