#include "Department.h"
#include <iomanip>
#include <cctype>
#include <iomanip>

const float BASE_RATE = 45000;
const float MILEAGE_RATE = 0.87;

Department::Department() 
{
	Manager m;

	setname("NULL");
	setcapacity(0);
	setproductCost(0);
	setmanager(m);

}

// full argument constructor
Department::Department(std::string n, int c, float pc, Manager m)
{
	setname(n);
	setcapacity(c);
	setproductCost(pc);
	setmanager(m);
}

Department::~Department() {}

void Department::setname(std::string n) { name = n; }
void Department::setcapacity(int c) { cap = c; }
void Department::setproductCost(float pc) { productCost = pc; }
void Department::setmanager(Manager m) { manager = m; }

std::string Department::getname() const { return name;}
int Department::getcapacity() const { return cap;}
float Department::getproductCost() const { return productCost;}
Manager Department::getmanager() const { return manager;}

int Department::numEmployees() const
{
	return employees.size();
}

void Department::addVEmployee(Employee e)
{
	employees.push_back(e);
}

void Department::removeVEmployee() // function to remove a given employee from the vector 
{
	int id;
	bool itemFound{ false };
	char confirm;
	if (employees.size() == 0)
		std::cout << "There are no employees in this department to remove." << std::endl;
	else
	{
		std::cout << "Please enter the ID of the employee that you would like to remove: ";
		std::cin >> id;

		for (int i = 0; i < employees.size(); ++i)
		{
			if (id == employees[i].getid())
			{//save its position to assign to the iterator
				itemFound = true;

				std::cout << "\nYou have chosen to remove this employee from the department: " << std::endl;
				std::cout << employees[i] << std::endl;
				std::cout << "\nAre you sure you want to remove this employee from the department? (Y or N): ";
				std::cin >> confirm;
				confirm = toupper(confirm);
				if (confirm == 'Y')
					employees.erase(employees.begin() + i);
				break;
			}
		}
		if (!itemFound)
			std::cout << "Employee was not found in the department." << std::endl;

		else if (confirm == 'Y')
			std::cout << "\nEmployee successfully removed." << std::endl << std::endl;
		else
			std::cout << "\nRemoval cancelled by user." << std::endl << std::endl;
	}

	//std::vector<Employee>::iterator it = dept_employees.begin() + id; // use an iterator to get to the correct employee

	//dept_employees.erase(it); // remove that employee from the vector 
}

std::ostream& operator<<(std::ostream& output, const Department& d)
{
	// TODO: insert return statement here
	output << std::endl;
	output << std::setw(30) << "Department Name:              " << std::setw(20) << std::right << d.getname() << std::endl;
	output << std::setw(30) << "Department Capacity:          " << std::setw(20) << std::right << d.getcapacity() << std::endl;
	output << std::setw(30) << "Department Total Product Cost:" << std::setw(20) << std::right << std::fixed << std::setprecision(2) << d.getproductCost() << std::endl;
	
	if (d.getmanager() != Manager())
	{
		output << std::setw(30) << "Department Manager:           " << std::endl << d.getmanager() << std::endl;
	}
	
	if (d.numEmployees() != 0)
	{
		output << std::setw(30) << "Department Employees:         " << std::endl;
		for (const auto& emp : d.employees)
		{
			output << emp << std::endl;
		}
	}
	output << std::endl;
	return output;
}

void Department::printfinal(const Department& d)
{
	// this is for the variables that apply from hte employee vector
	// this includes the income, distance, and rating average
	float finalincome = 0.0, finaldist = 0.0, finalrating = 0;
	if (d.numEmployees() > 0)
	{
		for (const auto& temp : d.employees)
		{
			finalincome += temp.totalRev();
			finaldist += temp.getmilesTraveled();
			finalrating += temp.getemployeeRating();
		}
		finalrating /= d.numEmployees();
		// only divide if d.numEmployees() > 0
	}
	else
	// compound equivalance 

	// print out department info
	std::cout << std::fixed << std::setprecision(2) << std::endl;
	std::cout << std::setw(30) << "Department Name:              " << std::setw(20) << std::right << d.getname() << std::endl;
	std::cout << std::setw(30) << "Department Capacity:          " << std::setw(20) << std::right << d.getcapacity() << std::endl;

	// only happens if a manager exists
	if (d.getmanager() != Manager())
	{
		std::cout << std::setw(30) << "Department Manager:           " << std::setw(20) << std::right << d.manager.getfirstName() + " " + d.manager.getlastName() << std::endl;
	}

	std::cout << std::setw(30) << "Total Income:                     $" << std::setw(15) << std::right << finalincome << std::endl;
	std::cout << std::setw(30) << "Cost of Products:                 $" << std::setw(15) << std::right << d.getproductCost() << std::endl;
	std::cout << std::setw(30) << "Cost of Labor:                    $" << std::setw(15) << std::right << (d.manager.getsalary() + d.numEmployees() * BASE_RATE) << std::endl;
	std::cout << std::setw(30) << "Cost of Travel:                   $" << std::setw(15) << std::right << (finaldist * MILEAGE_RATE) << std::endl;
	std::cout << std::setw(30) << "Average Employee Rating:           " << std::setw(15) << std::right << finalrating << std::endl;
	std::cout << std::setw(30) << "Final Profit:                     $" << std::setw(15) << std::right << (finalincome - ((d.numEmployees() * BASE_RATE) + (finaldist * MILEAGE_RATE) + d.getproductCost())) << std::endl << std::endl;

}