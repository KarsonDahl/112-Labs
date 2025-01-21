#pragma once
#include "Person.h"
#include <vector>

class Employee : public Person
{
	friend std::ostream& operator<<(std::ostream& output, const Employee& e);
public:
	Employee();

	Employee(int, float, std::vector<float>);

	~Employee();

	// setter functions
	void setmilesTraveled(int);
	void setemployeeRating(float);
	void setJobs(std::vector<float>);

	// getter functions
	int getmilesTraveled() const;
	float getemployeeRating() const;
	std::vector<float> getJobs() const;

	// vector manipulation
	float totalRev() const;
	void addJob(float j);

	// overload the function
	bool operator<(const Employee&);
//	bool operator!=(const Employee&);

private:
	// private variables
	int milesTraveled;
	float employeeRating;
	std::vector<float> Jobs;
};