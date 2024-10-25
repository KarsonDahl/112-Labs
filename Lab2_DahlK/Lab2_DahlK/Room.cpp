// NO MAIN
// file will be used to store function definitions
// called an implementation file

#include "Room.h"
#include <iomanip>
#include <iostream>

const int PAINT = 400;

// Default constructor

Room::Room()
{
	height = 0;
	width = 0;
	length = 0;
	coats = 0;
}

// full argument constructor

Room::Room(float w,float h,float l, int c)
{
	width = w;
	height = h;
	length = l;
	coats = c;
}

// Set functions

void Room::setHeight(float h)
{
	height = h;
}

void Room::setLength(float l)
{
	length = l;
}

void Room::setWidth(float w)
{
	width = w;
}

void Room::setCoat(int c)
{
	coats = c;
}

// Get functions

float Room::getHeight() const
{
	return height;
}

float Room::getLength() const
{
	return length;
}

float Room::getWidth() const
{
	return width;
}

int Room::getCoat() const
{
	return coats;
}

// simple calculation funciton
float Room::calcVolume() const
{
	// volume does not have to be stored beyond this function
	// that makes it easy to leave it as a variable for here and no where else
	float volume = length * width * height;
	return volume;
}

// calculating paintable area function
float Room::calcPaintedArea() const
{
	// much like volume, paintable area does not have to be stored beyond this function
	// that makes it easy to leave it as a variable for here and no where else
	float paintable = (2 * (height * width)) + (2 * (height * length));
	return paintable;
}

float Room::gallonsNeeded() const
{
	return ceil(getCoat() * (calcPaintedArea()/PAINT));
}

// simple function made exclusively out of cout and constant pulling functions.
void Room::showData() const
{
	std::cout << std::endl << "Here are the values you input: " << std::endl;

	// these three use the getX as opposed to just X as it is less permission and priviledge
	// that works becuase they are constant

	std::cout << std::setw(40) << std::left << "Length: " << std::setw(20) << std::right << getLength() << std::endl;
	std::cout << std::setw(40) << std::left << "Width: " << std::setw(20) << std::right << getWidth() << std::endl;
	std::cout << std::setw(40) << std::left << "Height: " << std::setw(20) << std::right << getHeight() << std::endl;

	std::cout << std::setw(40) << std::left << "Number of coats: " << std::setw(20) << std::right << getCoat() << std::endl;
	// these two can just pull our caclulation functions becuase those are constant

	std::cout << std::setw(40) << std::left << "Volume of your space: " << std::setw(20) << std::right << calcVolume() << std::endl;
	std::cout << std::setw(40) << std::left << "How much of your area can be painted: " << std::setw(20) << std::right << calcPaintedArea() << std::endl << std::endl;
	std::cout << std::setw(40) << std::left << "Paint Required:" << std::setw(12) << std::right << gallonsNeeded() << " gallons" << std::endl;

}