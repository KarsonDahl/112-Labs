/*
getline for invoice name
max # of rooms to be painted
distance from office?

class house with class(es) room inside with paintable 
paint cost value in class, not a global or in main

switch case for add (a) list (l) and quit (q)
add will add a room to the current house
- using code from lab 2 for room.h and room.cpp

list will list all of the rooms
quit will exit the program
switch case with tolower or toupper will work great for that

House.h House.cpp Room.h Room.cpp main.cpp
constant variable for cost per gallon will be in the class (.h)
for class constants:
static const datatype VARIABLENAME = value;
available to every object of the class and ___

room class needs:
# of coats of paint
length
width
height

readout:
all prior values for room
volume
paintable area
gallons of paint required (ciel)

at the end of the # of rooms, cout total paint required 

a vector with classes for rooms?
use the value for max # of rooms in a loop checking for if it has been reached, and if it has cout error statment if switchcase is A

numeric error checking in main
use bool for error checking set functs (in class cpps, return false if false)
class should NOT be asking users to re-enter information

quit function will print full invoice with:
city info for store
phone #
website

invoice user name

labor charges:
# of rooms
hourly rate
subtotal for labor

product charges:
paint cans requred
cost per paint can
amount per room

travel charges:
miles away from store
rate per mile
total for travel

final total
ONLY PUT DOLLAR SIGNS ON SUBTOTALS AND FINAL TOTAL
*/

#include "House.h"
#include <iomanip>
#include <iostream>
#include <cctype>

using namespace std;

void userInput(string&, float&, int&);
void printMenu();
void addARoom(House&);


int main() 
{
	char cases = ' ';
	string name = " ";
	float dist = 0;
	int roomC = 0;

	userInput(name, dist, roomC);

	House h((int)roomC, name, dist);

	do
	{
		// always print the menu each time
		printMenu();

		cin >> cases;
		cases = toupper(cases);
		while (cin.fail() || cases != 'A' && cases != 'L' && cases != 'Q')
		{
			cin.clear();
			cin.ignore(numeric_limits< streamsize>::max(), '\n'); // gotta have it
			cout << "Error. Please enter either an A, an L, or a Q. " << endl;
			cin >> cases;
			cases = toupper(cases);
		}

		switch (cases)
		{
			case 'A':
				// add a room and re run the dowhile
				cout << endl << endl;
				addARoom(h);

				break;

			case 'L':
				// list rooms that have been created
					h.listRooms();
				break;
		}

	} while (cases != 'Q');

	h.printInvoice();

	cout << endl << "Would you like to print to a file?" << endl;

	// switch case for whether file save or not
	cin >> cases;
	cases = toupper(cases);
	while (cin.fail() || cases != 'Y' && cases != 'N')
	{
		cin.clear();
		cin.ignore(numeric_limits< streamsize>::max(), '\n'); // gotta have it
		cout << "Error. Please enter a Y or an N. " << endl;
		cin >> cases;
		cases = toupper(cases);
	}

	// if they choose to save to a file, run file function
	switch (cases)
	{
		case 'Y':
			h.printToFile();
			break;
	// if they choose not to, just break
		case 'N':
			cout << "No file created." << endl;
			break;
	}

		system("pause");
		return 0;
	
}

void userInput(string& name, float& dist, int& roomC)
{
	// cin with getline, necassary and not error checkable
	cout << "What is the name for the invoice?" << endl;
	getline(cin, name);

	// get maximum # of rooms for a house
	// to be used for addARoom function
	cout << "How many rooms will be in the house?" << endl;
	cin >> roomC;
	while (cin.fail() || roomC <= 0)
	{
		cin.clear();
		cin.ignore(numeric_limits< streamsize>::max(), '\n'); // gotta have it
		cout << "Error. Please enter a valid number of rooms. " << endl;
		cin >> roomC;
	}

	// get distance from user
	cout << "How far (in miles) is the house from the store?" << endl;
	cin >> dist;
	while (cin.fail() || dist < 0)
	{
		cin.clear();
		cin.ignore(numeric_limits< streamsize>::max(), '\n'); // gotta have it
		cout << "Error. Please enter a valid distance. " << endl;
		cin >> dist;
	}

}

void printMenu()
{
	// simple cout of a menu to be repeated
	cout << "Please select one of the following options: " << endl;
	cout << "A - add a room to the current house." << endl;
	cout << "L - list all rooms in the current house." << endl;
	cout << "Q - quit the program and print final invoice." << endl;
}

void addARoom(House& h)
{
	// temp variables
	// this notation with commas is not one I typically use, but it is more efficient and shorter
	float length, width, height;
	int numCoats;

	// checking for if there is 'room' for another room
if (h.roomCount() < h.getRooms())
	{ 
		// prompt for: length
		cout << "Length: ";
		cin >> length;

		// Error check
		while (cin.fail() || length <= 0)
		{
			cin.clear(); // clears the error from the input stream
			cin.ignore(numeric_limits< streamsize>::max(), '\n'); // remove anything remaining in the stream
			cout << "Error. Please enter a number greater than 0: ";
			cin >> length;
		}
		// prompt for: width
		cout << "Width: ";
		cin >> width;

		// Error check
		while (cin.fail() || width <= 0)
		{
			cin.clear(); // clears the error from the input stream
			cin.ignore(numeric_limits< streamsize>::max(), '\n'); // remove anything remaining in the stream
			cout << "Error. Please enter a number greater than 0: ";
			cin >> width;
		}
		// prompt for: height
		cout << "Height: ";
		cin >> height;

		// Error check
		while (cin.fail() || height <= 0)
		{
			cin.clear(); // clears the error from the input stream
			cin.ignore(numeric_limits< streamsize>::max(), '\n'); // remove anything remaining in the stream
			cout << "Error. Please enter a number greater than 0: ";
			cin >> height;
		}

		// prompt for: coats
		cout << "Number of coats of paint: ";
		cin >> numCoats;

		// Error check
		while (cin.fail() || numCoats <= 0)
		{
			cin.clear(); // clears the error from the input stream
			cin.ignore(numeric_limits< streamsize>::max(), '\n'); // remove anything remaining in the stream
			cout << "Error. Please enter a number greater than 0: ";
			cin >> numCoats;
		}

		h.addRoom(length, width, height, numCoats);
	}

// If the limit that was previously set is reached, this else statement will run
else
{
	cout << endl << "room limit reached." << endl << endl;
}

}
