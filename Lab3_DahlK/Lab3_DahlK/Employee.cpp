#include "Employee.h" // header
#include <iostream> // gotta have cin/cout
#include <fstream> // for file stuff
#include <iomanip> // for print functions
#include <algorithm> // sort

// NOOOO "using namespace std"

// construction
Employee::Employee()
{
	// empty sets
	employeeCity = "";
	employeeName = "";
	employeeID = "";
}

// construction
Employee::Employee(std::string c, std::string n, std::string i)
{
	// fully defined sets
	employeeCity = c;
	employeeName = n;
	employeeID = i;
}

// setters
void Employee::setName(std::string n)
{
	employeeName = n;
}
void Employee::setCity(std::string c)
{
	employeeCity = c;
}
void Employee::setID(std::string i)
{
	employeeID = i;
}

// getters
std::string Employee::getName() const
{
	return employeeName;
}
std::string Employee::getCity() const
{
	return employeeCity;
}
std::string Employee::getID() const
{
	return employeeID;
}

// adding scores to the vector
void Employee::addScore(float x)
{
	// this is specifically for the values that are coming in from the file
	if(x >= 0 && x <= 5)
	{
		// pushback is the way to add values
		satisfactionScore.push_back(x);
	}
	else
	{
		// this should theoretically never come up since the infile stuff has error checking
		std::cout << "Please enter a value between 0 and 5." << std::endl;
	}
}

// for sorting the scores
void Employee::sortScores()
{
	// looping through the sort
	for (int x = 0; x < satisfactionScore.size(); x++)
	{
		// this sorts
		std::sort(satisfactionScore.begin(), satisfactionScore.end());
	}
}

// calculating the average for vector values
float Employee::average() const
{
	float avg = 0;

	for (auto x : satisfactionScore)
	{
		avg += x;
	}

	// simple calculation that takes all values
	return avg / (float)numScores();
}

// lowest value calculation
float Employee::lowestScore() const
{
	// this is 5 so no matter what it will be lower
	float mn = 5;
	for (int i = 0; i < numScores(); i++)
	{
		if (satisfactionScore[i] < mn)
		{
			mn = satisfactionScore[i];
		}
	}
	// return that vaule
	return mn;
}

// highest value calculation
float Employee::highestScore() const
{
	// this is 0 becuase no moatter what it will be more
	float mx = 0;

	for (int i = 0; i < numScores(); i++)
	{
		if (satisfactionScore[i] > mx)
		{
			mx = satisfactionScore[i];
		}
	}
	// return that vaule
	return mx;
}

// getting the # of scores as an int
int Employee::numScores() const
{
	// easy!
	auto x = 0;
	x = satisfactionScore.size();
	return x;
}

// saving to a file works better from the Employee.cpp
void Employee::saveToFile(Employee e)
{
	// the inclusion of + ".txt" guarantees a text file that is identifiable 
	std::ofstream out(e.getName() + ".txt");

	// out makes it more flexible
	if (out.is_open())
	{
		// easy for taking the values taht are alreadt being stored from the class
		out << e.getName() << std::endl;
		out << e.getCity() << std::endl;
		out << e.getID() << std::endl;

		for (int x = 0; x < satisfactionScore.size(); x++)
		{
			// this has all the scores in there
				out << satisfactionScore.at(x) << std::endl;
		}
		
		// close the out of course
		out.close();
	}

	else
	{
		// this shouldnt be reached but oh well
		std::cout << "Error." << std::endl;
	}
}

// removing duplicate value
void Employee::removeScore(int x)
{
	if (x == 0)
	{
		// if there is only one value, making numScore() = 1, this makes x (the sum of numScore() - 1) into 0
		// in that case no value needs to be erased
		return;
	}
	else
	{
		// Removing a score from the vector and error checking within range
		satisfactionScore.erase(satisfactionScore.begin() + x);
	}

}

// clear the employee class
void Employee::resetEmployee()
{
	// basically blank slate for default constructor
	employeeCity = "";
	employeeName = "";
	employeeID = "";
	satisfactionScore.clear();
}

// print out employee information
void Employee::printEmployeeInfo()
{
	// very simple printing
	std::cout << std::fixed << std::setprecision(1) << std::endl;
	std::cout << "**************************************************" << std::endl;
	std::cout << std::setw(20) << "Name: " << getName() << std::endl;
	std::cout << std::setw(20) << "City: " << getCity() << std::endl;
	std::cout << std::setw(20) << "Employee ID: " << getID() << std::endl;
	std::cout << "**************************************************" << std::endl;
	std::cout << std::setw(40) << std::right << "Customer Satisfaction Info" << std::endl;
	std::cout << std::setw(35) << std::left << "Average Score:" << average() << std::endl;
	std::cout << std::setw(35) << std::left << "Highest Score:" << highestScore() << std::endl;
	std::cout << std::setw(35) << std::left << "Lowest Score:" << lowestScore() << std::endl;
	std::cout << "List of all recorded scores:" << std::endl;
	// loop through printing and sorting
	for (int x = 0; x < satisfactionScore.size(); x++)
	{
			sortScores();
			std::cout << satisfactionScore.at(x) << std::endl;
	}
	std::cout << std::setw(20) << std::right << "End of Information for " << getName() << std::endl;
	std::cout << std::endl << "**************************************************" << std::endl;
}