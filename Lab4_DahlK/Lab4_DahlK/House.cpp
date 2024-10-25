
#include "House.h"
#include <iomanip>
#include <iostream>
#include <fstream>

// instead of being in teh room class, my calculation is in here
// therefore, global declaration makes more sense with the others here
const int PAINT = 400;
const double HOURLY_RATE = 18.50;
const double MILAGE_COST = 0.67;
const double PAINT_COST = 70.35;

// default constuction
House::House()
{
	name = "";
	numRooms = 0;
	dist = 0;
}

// full argument constructor
House::House(int r, std::string n, float d)
{
	setName(n);
	setRooms(r);
	setDist(d);
}

// destructor
House::~House()
{
	
}

// set name
void House::setName(std::string n)
{
	name = n;
}

// set rooms
void House::setRooms(int r)
{
	numRooms = r;
}

// set distance
void House::setDist(float d)
{
	dist = d;
}

// get name
std::string House::getName() const
{
	return name;
}

// get rooms
int House::getRooms() const
{
	return numRooms;
}

// get distance
float House::getDist() const
{
	return dist;
}

void House::addRoom(float l, float w, float h, int c)
{
	Room r(w, h, l, c);
	roomVect.push_back(r);
}

// number of rooms
int House::roomCount() const
{
	return roomVect.size();
}


void House::listRooms() const
{
	// list client information
	std::cout << std::setw(40) << std::left << std::endl << std::endl << "Client:" << std::setw(20) << std::setw(20) << std::right << getName() << std::endl;
	std::cout << std::setw(40) << std::left << "Total Rooms: " << std::setw(20) << std::right << getRooms() << std::endl;
	std::cout << std::setw(40) << std::left << "Current Rooms: " << std::setw(20) << std::right << roomCount() << std::endl;
	std::cout << std::setw(40) << std::left << "Distance from Office: " << std::setw(20) << std::right << getDist() << std::endl;

	if (roomCount() > 0)
	{
		std::cout << std::endl << "Room Info" << std::endl;
		for (const auto& x : roomVect)
		{
			// loop through the vector and use the showData() function from Room.cpp
			x.showData();
		}
	}
	// formatting
	std::cout << std::endl << std::endl << std::endl;

}

// Number of coats of paint in a single job
int House::numCoats() const
{
	int temp = 0;

	// For every room, add number of coats to temp total
	for (const auto& i : roomVect)
	{
		temp += i.getCoat();
	}

	return temp;
}

// the formatting on these is what took me so long, and its not quite right
void House::printInvoice() const
{
	// Invoice specific information
	std::cout << std::setprecision(2) << std::fixed;
	std::cout << "------------------------------------------------------" << std::endl;
	std::cout << std::setw(36) << std::right << getName() << std::endl;
	std::cout << std::setw(35) << std::right << "Final Invoice" << std::endl;
	std::cout << "------------------------------------------------------" << std::endl << std::endl;
	// General painting company information
	std::cout << "WePaintHouses LLC" << std::endl;
	std::cout << "1971 University Blvd" << std::endl;
	std::cout << "Lynchburg, VA 24502" << std::endl;
	std::cout << "(434) 4554-545" << std::endl;
	std::cout << "wepainthousesllc.com" << std::endl << std::endl;

	std::cout << "Billed to: " << getName() << std::endl << std::endl;

	std::cout << "-----------------------------------------------------" << std::endl;
	std::cout << std::setw(31) << std::right << "Labor Charges" << std::endl;
	std::cout << std::setw(32) << std::right << "-----------------" << std::endl;

	// Calculate labor charges
	double laborCharges = (numCoats() * HOURLY_RATE);
	std::cout << std::setw(10) << std::left << "Rooms" << std::right << "Number of coats" << std::setw(15) << "Hourly Rate" << std::setw(13) << "Total" << std::endl;
	std::cout << std::setw(10) << std::left << getRooms() << std::right << numCoats() << std::setw(22) << HOURLY_RATE << std::setw(13) <<std::right  << "$" << std::right << laborCharges << std::endl;
	std::cout << std::endl << std::setw(31) << std::right << "Product Charges" << std::endl;
	std::cout << std::setw(32) << std::right << "-----------------" << std::endl;
	std::cout << std::setw(10) << std::left << "Room #" << std::right << "Paint Cans" << std::setw(18) << "Unit Cost" << std::setw(15) << "Amount" << std::endl;
	
	// Initialize product charges variable
	double productCharges = 0;
	for (int i = 0; i < roomCount(); i++)
	{
		// temp variables
		int coats = 0;
		float pArea = 0;
		double roomCharge = 0;

		const Room& x = roomVect.at(i);

		// For every room, add number of coats to temp total
		coats = x.getCoat();

		// For every room, add paintable area to temp2 total
		pArea = x.calcPaintedArea();

		// this calculates the number of cans required per room and multiplies it by the cost per can
		// you told us in class that we should use ciel, even though it is differnet from the instructions and it makes more sense unless all the rooms are the same color
		roomCharge = (PAINT_COST * ceil(coats * (pArea / PAINT)));

		// keeping full product charge in line with each iteration and addition to the total
		productCharges += roomCharge;

		std::cout << std::setw(10) << std::left << i + 1 << std::left << std::setprecision(0) << std::setw(8) << ceil(coats *(pArea / PAINT)) << std::setw(16) << std::right << std::setprecision(2) << PAINT_COST << std::setw(19) << std::right << roomCharge << std::endl;

		// Add current vector iterations charge to total
	}

	std::cout << "Total Product Charges: " << std::setw(22) << "$" << std::right << productCharges << std::endl << std::endl;
	std::cout << std::setw(31) << std::right << "Travel Charges" << std::endl;
	std::cout << std::setw(32) << std::right << "-----------------" << std::endl;

	// travel charge calculations
	double travelCharges = dist * MILAGE_COST;
	std::cout << std::setw(10) << std::left << "Mileage" << std::setw(32) << std::right << "Rate Per Mile" << std::setw(11) << std::right << "Total" << std::endl;
	std::cout << std::setw(10) << std::left << getDist() << std::setw(23) << std::right << MILAGE_COST << std::setw(14) << std::right << "$" << travelCharges << std::endl << std::endl;

	// grand total
	std::cout << std::setw(27) << std::left << "Final Total: " << std::setw(18)  << std::right << "$" << (laborCharges + productCharges + travelCharges) << std::endl;
	std::cout << "-----------------------------------------------------" << std::endl << std::endl;
}

void House::printToFile() const
{
	// same as print invoice, only outfile instead of cout
	std::ofstream outfile(getName() + ".txt");

	// Invoice specific information
	outfile << std::setprecision(2) << std::fixed;
	outfile << "------------------------------------------------------" << std::endl;
	outfile << std::setw(36) << std::right << getName() << std::endl;
	outfile << std::setw(35) << std::right << "Final Invoice" << std::endl;
	outfile << "------------------------------------------------------" << std::endl << std::endl;
	// General painting company information
	outfile << "WePaintHouses LLC" << std::endl;
	outfile << "1971 University Blvd" << std::endl;
	outfile << "Lynchburg, VA 24502" << std::endl;
	outfile << "(434) 4554-545" << std::endl;
	outfile << "wepainthousesllc.com" << std::endl << std::endl;

	outfile << "Billed to: " << getName() << std::endl << std::endl;

	outfile << "-----------------------------------------------------" << std::endl;
	outfile << std::setw(31) << std::right << "Labor Charges" << std::endl;
	outfile << std::setw(32) << std::right << "-----------------" << std::endl;

	// Calculate labor charges
	double laborCharges = (numCoats() * HOURLY_RATE);
	outfile << std::setw(10) << std::left << "Rooms" << std::right << "Number of coats" << std::setw(15) << "Hourly Rate" << std::setw(13) << "Total" << std::endl;
	outfile << std::setw(10) << std::left << getRooms() << std::right << numCoats() << std::setw(22) << HOURLY_RATE << std::setw(13) << std::right << "$" << std::setw(1) << laborCharges << std::endl;
	outfile << std::endl << std::setw(31) << std::right << "Product Charges" << std::endl;
	outfile << std::setw(32) << std::right << "-----------------" << std::endl;
	outfile << std::setw(10) << std::left << "Room #" << std::right << "Paint Cans" << std::setw(18) << "Unit Cost" << std::setw(15) << "Amount" << std::endl;

	// Initialize product charges variable
	double productCharges = 0;
		for (int i = 0; i < roomCount(); i++)
		{
			// temp variables
			int coats = 0;
			float pArea = 0;
			double roomCharge = 0;

			// creating an array with the values of roomVect by reference
			const Room& x = roomVect.at(i);

			// For every room, add number of coats to temp total
			coats = x.getCoat();

			// For every room, add paintable area to temp2 total
			pArea = x.calcPaintedArea();

			// this calculates the number of cans required per room and multiplies it by the cost per can
			roomCharge = (PAINT_COST * ceil(coats * (pArea / PAINT)));


			productCharges += roomCharge;

			outfile << std::setw(10) << std::left << i + 1 << std::left << std::setprecision(0) << std::setw(8) << ceil(coats * (pArea / PAINT)) << std::setw(16) << std::right << std::setprecision(2) << PAINT_COST << std::setw(19) << std::right << roomCharge << std::endl;

			// Add current vector iterations charge to total
		}

	outfile << "Total Product Charges: " << std::setw(22) << "$" << productCharges << std::endl << std::endl;
	outfile << std::setw(31) << std::right << "Travel Charges" << std::endl;
	outfile << std::setw(32) << std::right << "-----------------" << std::endl;

	// travel charge calculations
	double travelCharges = dist * MILAGE_COST;
	outfile << std::setw(10) << std::left << "Mileage" << std::setw(32) << std::right << "Rate Per Mile" << std::setw(11) << std::right << "Total" << std::endl;
	outfile << std::setw(10) << std::left << getDist() << std::setw(23) << std::right << MILAGE_COST << std::setw(14) << std::right << "$" << travelCharges << std::endl << std::endl;

	// grand total
	outfile << std::setw(27) << std::left << "Final Total: "  << std::setw(18) << std::right << '$' << (laborCharges + productCharges + travelCharges) << std::endl;
	outfile << "-----------------------------------------------------" << std::endl << std::endl;
	// let user know it was successful.
	std::cout << "File made sucessfully." << std::endl;
}
