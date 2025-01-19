#pragma once
#include <string>

class CompletedJob
{
public:
	// default constructor
	CompletedJob();

	// full argument constructor
	explicit CompletedJob(int, int, std::string, float, float, float, float);

	// destructor
	~CompletedJob();

	// setters
	void setroomsPainted(int); 
	void setnumCans(int);
	void setinvoiceNum(int);
	void setclientName(std::string);
	void setlaborC(float);
	void setproductC(float); 
	void settravelC(float); 
	void setmileage(float);

	// getters
	int getinvoiceNum() const;
	int getroomsPainted() const; 
	int getnumCans() const;
	std::string getclientName() const;
	float getlaborC() const; 
	float getproductC() const; 
	float gettravelC() const; 
	float getmileage() const;

	// calculate total
	float calcTotal() const;

	// print out
	void printOut(std::ofstream&) const;

private:
	// private variable declaration
	int invoiceNum, roomsPainted, numCans;
	std::string clientName;
	float laborC, productC, travelC, mileage;
};