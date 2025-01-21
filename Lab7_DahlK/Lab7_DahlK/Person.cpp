#include <iostream>
#include "Date.h"
#include "Person.h"

Person::Person()
{
	Date nullD(0, 0, 0);
	setfirstName("NULL");
	setlastName("NULL");
	sethiringDate(nullD);
	setbirthday(nullD);
	setid(0);
}

Person::Person(std::string fn, std::string ln, Date hd, Date bd, int i)
{
	setfirstName(fn);
	setlastName(ln);
	sethiringDate(hd);
	setbirthday(bd);
	setid(i);
}

Person::~Person() { }

void Person::setfirstName(std::string fn) { firstName = fn; }
void Person::setlastName(std::string ln) { lastName = ln; }
void Person::sethiringDate(Date hd) { hiringDate = hd; }
void Person::setbirthday(Date bd) { birthday = bd; }
void Person::setid(int i) { id = i; }

std::string Person::getfirstName() const { return firstName; }
std::string Person::getlastName() const { return lastName; }
Date Person::gethiringDate() const { return hiringDate; }
Date Person::getbirthday() const { return birthday; }
int Person::getid() const { return id; }

