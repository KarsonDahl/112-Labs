#pragma once
//pragma once goota have it 


// vector and string
#include <vector>
#include <string>

// class
class Employee
{
public:
	Employee();
	// consturction
	Employee(std::string, std::string, std::string);

	// setters
	void setName(std::string);
	void setCity(std::string);
	void setID(std::string);

	// getters
	std::string getName() const;
	std::string getCity() const;
	std::string getID() const;


	// other public functions 
	void resetEmployee();
	void addScore(float);
	int numScores() const;
	void printEmployeeInfo();
	void sortScores();
	void saveToFile(Employee);
	void removeScore(int);

private:
	
	// private variables 
	std::string employeeName;
	std::string employeeCity;
	std::string employeeID;
	std::vector<float> satisfactionScore;

	// private functions
	float lowestScore() const;
	float highestScore() const;
	float average() const;
};
