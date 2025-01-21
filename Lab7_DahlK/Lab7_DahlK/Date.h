#pragma once
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <stdexcept>

class Date
{
	friend std::ostream& operator<<(std::ostream& output, Date d);
public:
	Date(int d = 0, int m = 0, int yyyy = 0)
	{
		setDate(d, m, yyyy);
	}
	~Date() {}
	void setDate(int d, int m, int yyyy)
	{
			day = d;
			month = m;
			year = yyyy;
	}

	// == overload
	bool operator==(const Date& d)
	{
		if (this->day == d.day && this->month == d.month && this->year == d.year)
			return true;
		else
			return false;
	}	
	
	bool operator!=(const Date& d)
	{
		if (this->day != d.day || this->month != d.month && this->year != d.year)
			return true;
		else
			return false;
	}
private:
	// private variables
	int day;
	int month;
	int year;
};
inline std::ostream& operator<<(std::ostream& output, Date d)
{
	output << d.month << "/" << d.day << "/" << d.year;
	return output;
}