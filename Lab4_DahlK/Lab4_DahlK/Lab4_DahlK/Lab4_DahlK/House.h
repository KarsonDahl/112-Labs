#pragma once

#include <string>
#include <vector>
#include "Room.h"

class House
{
public:

	// default constructor
	House();

	// full constructor

	House(int, std::string, float);

	// destruction
	~House();

	// set functions
	void setName(std::string);
	void setRooms(int);
	void setDist(float);

	// get functions
	std::string getName() const;
	int getRooms() const;
	float getDist() const;

	//other functions
	int roomCount() const;

	// adding room to vector
	void addRoom(float l, float w, float h, int c); 

	// just return roomVect.size()
	void listRooms() const;

	// cout for user
	void printInvoice() const;

	// looping through adding the total # of coats
	int numCoats() const;
	
	// out to a file!!
	void printToFile() const;

private:
	// private variables
	std::vector<Room> roomVect;
	std::string name;
	float dist;
	int numRooms;

};