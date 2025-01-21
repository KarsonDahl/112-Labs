#include "Employee.h" 
#include <iomanip>
#include <algorithm> // included for sorting
#include "Department.h"

Employee::Employee() //default constructor
{
	setmilesTraveled(0);
	setemployeeRating(0);
}

Employee::Employee(int mt, float er, std::vector<float> j) // full argument contstructor
{
	setmilesTraveled(mt);
	setemployeeRating(er);
	setJobs(j);
}
// destructor
Employee::~Employee() { }

// setters
void Employee::setmilesTraveled(int mt) { milesTraveled = mt; }
void Employee::setemployeeRating(float s) { employeeRating = s; }
void Employee::setJobs(std::vector<float> j) { Jobs = j; }

// getters
int Employee::getmilesTraveled() const { return milesTraveled; }
float Employee::getemployeeRating() const { return employeeRating; }
std::vector<float> Employee::getJobs() const { return Jobs; }

// adding job push back on the job vector
void Employee::addJob(float j) { Jobs.push_back(j); }

// this function makes it so that it will automatically sort
bool Employee::operator<(const Employee& e) { return this->getlastName() < e.getlastName(); }

// reveneue calculator that loops through
float Employee::totalRev() const
{
	float temp = 0.0;
	for (const auto &job : Jobs)
	{
		temp += job;
	}
	return temp;
}

// overloading the extraction operator
std::ostream& operator<<(std::ostream& output, const Employee& e)
{
	// TODO: insert return statement here
	output << std::setw(30) << " First Name:       " << std::setw(20) << std::right << e.getfirstName() << std::endl;
	output << std::setw(30) << " Last Name:        " << std::setw(20) << std::right << e.getlastName() << std::endl;
	output << std::setw(30) << " Birthday:         " << std::setw(12) << std::right << e.getbirthday() << std::endl;
	output << std::setw(30) << " Hiring Date:      " << std::setw(12) << std::right << e.gethiringDate() << std::endl;
	output << std::setw(30) << " ID:               " << std::setw(20) << std::right << e.getid() << std::endl;
	output << std::setw(30) << " Miles Traveled:   " << std::setw(20) << std::right << e.getmilesTraveled() << std::endl;
	output << std::setw(30) << " Rating:           " << std::setw(20) << std::right << e.getemployeeRating() << std::endl;
	output << std::setw(30) << " Job Revenue:      " << std::setw(20) << std::right << e.totalRev() << std::endl;

	return output;
}

// I dont actually need to overload this
//bool Employee::operator!=(const Employee& e)
//{
//	if (this->milesTraveled != e.milesTraveled || this->employeeRating != e.employeeRating || this->Jobs != e.Jobs)
//		return true;
//	else
//		return false;
//}