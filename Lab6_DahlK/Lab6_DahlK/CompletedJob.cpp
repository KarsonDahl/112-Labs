#include "CompletedJob.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

CompletedJob::CompletedJob()
	{
	//default construction
		roomsPainted = 0; numCans = 0;
		clientName = "";
		laborC = 0; productC = 0; travelC = 0; mileage = 0;
	}

CompletedJob::CompletedJob(int rp, int nc, std::string cn, float lc, float pc, float tc, float m)
{
	// full arguemnt constructor
	// calls set functions
	setroomsPainted(rp);
	setnumCans(nc);
	setclientName(cn);
	setlaborC(lc);
	setproductC(pc);
	settravelC(tc);
	setmileage(m);
}


CompletedJob::~CompletedJob()
{
 // empty
}

// setters
void CompletedJob::setinvoiceNum(int in) { invoiceNum = in; }
void CompletedJob::setroomsPainted(int rp) {  if (!std::cin.fail() || rp > 0)  roomsPainted = rp; else std::cout << "Error. please reenter the number of rooms: " << std::endl; }
void CompletedJob::setnumCans(int nc) { if (!std::cin.fail() || nc > 0)  numCans = nc;  else std::cout << "Error. please reenter the number of cans:" << std::endl; }
void CompletedJob::setclientName(std::string cn) {  clientName = cn; }
void CompletedJob::setlaborC(float lc) { if (!std::cin.fail() || lc >= 0) laborC = lc;  else std::cout << "Error. please reenter the labor charges: " << std::endl; }
void CompletedJob::setproductC(float pc) { if (!std::cin.fail() || pc >= 0) productC = pc;  else std::cout << "Error. please reenter the product charges: " << std::endl; }
void CompletedJob::settravelC(float tc) { if (!std::cin.fail() || tc >= 0) travelC = tc;  else std::cout << "Error. please reenter the travel charges: " << std::endl; }
void CompletedJob::setmileage(float m) { if (!std::cin.fail() || m >= 0) mileage = m;  else std::cout << "Error. please reenter the mileage: " << std::endl; }

// getters
int CompletedJob::getinvoiceNum() const { return  invoiceNum; }
int CompletedJob::getroomsPainted() const { return  roomsPainted; }
int CompletedJob::getnumCans() const { return  numCans; }
std::string CompletedJob::getclientName() const { return  clientName; }
float CompletedJob::getlaborC() const { return  laborC; }
float CompletedJob::getproductC() const { return  productC; }
float CompletedJob::gettravelC() const { return  travelC; }
float CompletedJob::getmileage() const { return  mileage; }

// simple computation for total
float CompletedJob::calcTotal() const
{
	float temp = (getlaborC() + getproductC() + gettravelC());
	return temp;
}

// print out that will be looped through
// passing in the out parameter
void CompletedJob::printOut(std::ofstream& out) const
{
	out << std::setw(33) << std::left << "Client Name: " << std::setw(20) << std::right << getclientName() << std::endl;
	out << std::setw(33) << std::left << "   Rooms Painted: " << std::setw(20) << std::right << getroomsPainted() << std::endl;
	out << std::setw(33) << std::left << "   Labor Charges: " << std::setw(20) << std::right << getlaborC() << std::endl;
	out << std::setw(33) << std::left << "   Paint Cans: " << std::setw(20) << std::right << getnumCans() << std::endl;
	out << std::setw(33) << std::left << "   Product Charges: " << std::setw(20) << std::right << getproductC() << std::endl;
	out << std::setw(33) << std::left << "   Mileage: " << std::setw(20) << std::right << getmileage() << std::endl;
	out << std::setw(33) << std::left << "   Travel Charges: " << std::setw(20) << std::right <<  gettravelC() << std::endl;
	out << std::setw(33) << std::left << "   Total Cost: " << std::setw(20) << std::right << calcTotal() << std::endl;
}
