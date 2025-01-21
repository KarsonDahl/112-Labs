#pragma once

#include "Employee.h"
#include "Manager.h"
#include <vector>
#include <string>


class Department
{
	friend std::ostream& operator<<(std::ostream& output, const Department& d);
public:
	Department();

	// full argument constructor
	Department(std::string, int, float, Manager);

	~Department();
	
	// setter functions
	void setname(std::string);
	void setcapacity(int);
	void setproductCost(float);
	void setmanager(Manager);

	// getter functions
	std::string getname() const;
	int getcapacity() const;
	float getproductCost() const;
	Manager getmanager() const;

	//vector manip
	int numEmployees() const;
	void addVEmployee(Employee e);
	void removeVEmployee();
	void printfinal(const Department& d);

private:
	// private variables
	std::string name;
	int cap;
	float productCost;
	Manager manager;
	std::vector<Employee> employees;
};