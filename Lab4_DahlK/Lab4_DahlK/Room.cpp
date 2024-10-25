// NO MAIN
// file will be used to store function definitions
// called an implementation file

#include "Room.h"
#include <iomanip>
#include <iostream>

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

// simple function made exclusively out of cout and constant pulling functions.
void Room::showData() const
{
	std::cout << std::endl << "Here are the values you input: " << std::endl;

	// these three use the getX as opposed to just X as it is less permission and priviledge
	// that works becuase they are constant

	std::cout << "Height: " << getHeight() << std::endl;
	std::cout << "Length: " << getLength() << std::endl;
	std::cout << "Width: " << getWidth() << std::endl;

	std::cout << "Number of coats: " << getCoat() << std::endl;
	// these two can just pull our caclulation functions becuase those are constant

	std::cout << "Volume of your space: " << calcVolume() << std::endl;
	std::cout << "How much of your area can be painted: " << calcPaintedArea() << std::endl << std::endl;

}