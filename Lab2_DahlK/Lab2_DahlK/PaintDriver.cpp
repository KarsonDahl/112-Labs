// Karson Dahl CSCN 112 Lab 2

/*
Painting Class: Calculating the cost to paint a house

This lab will be taking the class painting information and using it for the measurements of a room
There will be setting ad getting unctions to pull out of the class that will be in a separate cpp file
This class will have:

0 argument constructor
full argument constructor


goals of algorithm:

This program will prompt the user for the dimensions of the room--height, width, and length.
This information will be used to determine dimensions, volume, and paintable area (floor and ceiling is excluded).
Then it will print the information for the user.
The final step will be a calculation of how many gallons of paint will be required.
This process will be repeatable until the user enters a '-1'.

remember:
error check
get functions are constant
dont use 'using namespace std' in header file
calculation funcitons won't pass in the values, use get functions.

*/

#include <iostream>
#include <fstream>
#include <iomanip>

#include "Room.h"
// including the header file

using namespace std;

const int PAINT = 400;

int main()
{
	// variable declairations
	float w = 0;
	float l = 0;
	float h = 0;

	// array initialization
	Room room[1];

	// constructor
	Room();

	cout << "--------------------------------------------------" << endl;
	cout << fixed << setprecision(2) << "Welcome to the WePaintHouses LLC Calculator!" << endl;
	cout << "Enter a '-1' to exit the calculator." << endl;
	// users need to know that they can leave the loop
	cout << "--------------------------------------------------" << endl;
	
	while (room[0].setRoom(l, w, h))
	// having the setroom function return a bool keeps this loop working, as cin -1 will return false
	{
		cout << "--------------------------------------------------" << endl;
		
		// using an array allows the looping and calling of functions to work
		// this would also work with creating another class and it could be made better by using a variable that is within the looping to determine which instance of the array is being changed
		room[0].showData();
		
		// the math with ceil is easy to do here and therefore does not need its own variable to be stored in.
		cout << endl  << "You will need " << ceil(room[0].calcPaintedArea() / PAINT) << " gallons of paint." << endl;
		cout << "--------------------------------------------------" << endl;
	}

	cout << "--------------------------------------------------" << endl;
	cout << endl << "Thank you for using the Paint Company Calculator :)" << endl;
	// gotta be nice to users :)
}
