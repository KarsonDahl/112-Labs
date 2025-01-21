#include "Paint.h" // paint
#include "Flat.h" // flat
#include "Eggshell.h" // eggshell
#include "Satin.h" // satin
#include "SemiGloss.h" // semi gloss
#include "HighGloss.h" // high gloss
#include <iostream>
#include <iomanip>
#include <fstream> // for file manipulation
#include <random> // for random generation device and such

using namespace std;

// general function definitions
string errorCheckString(string); // error check
template<class T>
T errorCheckNum(T, T, T); // error check with template, used for int and floats

// first menu interactions
void printmenu(); // print funciton
void addFromFile(Paint* paints[]); // add all paints from file
template<class T>
T addColor(int c); // adding manually with templates

// second menu interactions
void sinistersecondmenu(); // sinister, evil, sick, and twisted SECOND print funciton
void adjust(Paint* paints[]); // change the # of cans
void printInventory(Paint* paints[]); // simple for loop with cout
void viewHelp(Paint* paints[]); // print help() for the given paint object
void printToFile(Paint* paints[]); // same as cout print, but to a file

int main()
{
	// variable declaration
	int choice{ 0 };
	Paint* paints[7]{};
	
	// first loop
	cout << "Please enter 7 paints. manually or from a file.   " << endl << endl;
	for (int x = 0; x < 7; x++)
	{
		// print menu and prompt user
		printmenu();
		cout << endl << "Enter your selection: ";
		cin >> choice;
		choice = errorCheckNum<int>(choice, 0, 6);

		// switch case with different prompts from menu
		switch (choice)
		{
		case 1:
			// flat paint
			system("CLS");
			cout << "Flat paint" << endl;
			// set the paint array at position x (looping condition) to be equal to the 
			// new object assosciated with choice, and addColor using the same type, while
			// passing in the choice to determine gloss level
			paints[x] = new Flat(addColor<Flat>(choice)); 
			cout << "Paint #" << x + 1 << endl;
			cout << *paints[x] << endl;
			break;
		case 2:
			// Eggshell paint
			system("CLS");
			cout << "Eggshell paint" << endl;
			// set the paint array at position x (looping condition) to be equal to the 
			// new object assosciated with choice, and addColor using the same type, while
			// passing in the choice to determine gloss level
			paints[x] = new Eggshell(addColor<Eggshell>(choice));
			cout << "Paint #" << x + 1 << endl;
			cout << *paints[x] << endl;
			break;
		case 3:
			system("CLS");
			cout << "Satin paint" << endl;
			// set the paint array at position x (looping condition) to be equal to the 
			// new object assosciated with choice, and addColor using the same type, while
			// passing in the choice to determine gloss level
			paints[x] = new Satin(addColor<Satin>(choice));
			cout << "Paint #" << x + 1 << endl;
			cout << *paints[x] << endl;
			// Satin paint
			break;
		case 4:
			system("CLS");
			cout << "Semi-Gloss paint" << endl;
			// set the paint array at position x (looping condition) to be equal to the 
			// new object assosciated with choice, and addColor using the same type, while
			// passing in the choice to determine gloss level
			paints[x] = new SemiGloss(addColor<SemiGloss>(choice));
			cout << "Paint #" << x + 1 << endl;
			cout << *paints[x] << endl;
			// Semigloss paint
			break;
		case 5:
			system("CLS");
			cout << "High-Gloss paint" << endl;
			// set the paint array at position x (looping condition) to be equal to the 
			// new object assosciated with choice, and addColor using the same type, while
			// passing in the choice to determine gloss level
			paints[x] = new HighGloss (addColor<HighGloss>(choice));
			cout << "Paint #" << x + 1 << endl;
			cout << *paints[x] << endl;
			// Highgloss paint
			break;
		case 6:
			// check if user has already begun manual entry of paints and colors
		if (paints[0] == NULL)
		{
			system("CLS");
			cout << "Load from a file" << endl;
			// add to a file, passing in the array of pointers directly
			addFromFile(paints);
			x = 7;
		}
		else
		{
			// inform user that the current loop is manual
			cout << "Manual entry already initiated. Please finish entering values manually. " << endl;
 		}
			break;
		default:
			system("CLS");
			//cout << "Input invalid. Try again: " << endl;
		}
	}

	// clean up from the first menu loop
	system("pause");
	system("CLS");

	// second menu loop
	// a while loop works better because this loop does not need to run an exact # of times
	while (choice != 5)
	{
		// print second menu and prompt user for choice
		sinistersecondmenu();
		cout << endl << "Enter your selection: ";
		cin >> choice;
		choice = errorCheckNum<int>(choice, 0, 5);

		switch (choice)
		{
		case 1:
			// adjust inventory
			system("CLS");
			printInventory(paints);
			adjust(paints);
			break;
		case 2:
			// view help for current selection
			system("CLS");
			printInventory(paints);
			viewHelp(paints);
			system("pause");
			break;
		case 3:
			// view current inventory
			system("CLS");
			cout << "Total Inventory" << endl << endl;
			printInventory(paints);
			break;
		case 4:
			// print to a file	
			system("CLS");
			printToFile(paints);
			break;
		case 5:
			// quit
			cout << "Exiting program." << endl;
			break;
		}
		system("CLS");
		// loop through the paints[] array printing to console
		for (int i = 0; i < 7; i++)
		{
			cout << "#     " << "Paint Color   " << "Number of Cans" << "    Gloss Level (%)" << endl;
			cout << fixed << setw(5) << left << i + 1
				<< setw(12) << right << paints[i]->getColor()
				<< setprecision(1) << setw(17) << paints[i]->getNumCans()
				<< setprecision(4) << setw(19) << paints[i]->getGlossLevel()
				<< endl << endl;
			paints[i]->help();
			cout << endl << endl;
		}
	}
	// end program
	return 0;
}

void printmenu()
{
	// print menu to console
	cout << "     Menu" << endl
		<< "1 -- Flat Paint" << endl
		<< "2 -- Eggshell Paint" << endl
		<< "3 -- Satin Paint" << endl
		<< "4 -- Semi-Gloss Paint" << endl
		<< "5 -- High-GLoss Paint" << endl
		<< "6 -- Load Inventory from a File" << endl;
}

void sinistersecondmenu()
{
	// print menu to console
	cout << "    Secondary Menu" << endl
		<< "1 -- Adjust Inventory" << endl
		<< "2 -- View Help for Selction" << endl
		<< "3 -- View Current Inventory" << endl
		<< "4 -- Print Inventory to a File" << endl
		<< "5 -- Quit" << endl;
}

template<class T>
T errorCheckNum(T value, T lowcap, T upcap)
{
	// a lowcap and an upcap allow this function to be specilazed for each value
	while (cin.fail() || value < lowcap || value > upcap)
	{
		cin.clear();
		cin.ignore(numeric_limits< streamsize>::max(), '\n'); // gotta have it
		cout << "Error. Please enter a valid value betwen " << lowcap << " and " << upcap << "." << endl;
		cin >> value;
	}
	return value;
}

string errorCheckString(string s)
{
	// error checking that takes strings
	// strings are taken in with getline so this theoretically should not be ran
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits< streamsize>::max(), '\n'); // gotta have it
		cout << "Error. Please re enter a valid string value. " << endl;
		cin >> s;
	}
	return s;
}

template<class T>
T addColor(int c)
{
	// the object that is created by the function call is new
	float nc, g;
	string color;
	// paint type is a template, and is set to the type according to the selection
	// of the user in the switch case in main
	T type;
	// create a paint object that points to the address of whatever new object is created
	Paint *p = &type;

	// clean up the input stream
	cin.clear();
	cin.ignore(100000000, '\n');
	// set the color 
	cout << "Color:" << endl;
	getline(cin, color);
	color = errorCheckString(color);
	p->setColor(color);
	
	// set number of cans 
	cout << "Number of Cans: " << endl;
	cin >> nc;
	nc = errorCheckNum<float>(nc, 0, 100000000);
	p->setNumCans(nc);

	// random device info for gloss
	// I got help with this from Davis King
	random_device random{};
	default_random_engine num{ random()};

	// logic for gloss random generation
	if (c == 1) {
		// flat paint
		uniform_real_distribution<float> flatGloss{ 0.1, 5.0 };
		p->setGlossLevel(flatGloss(num));
	}
	else if (c == 2) {
		// Eggshell paint
		uniform_real_distribution<float> eggshellGloss{ 10.5, 25.0 };
		p->setGlossLevel(eggshellGloss(num));
	}
	else if (c == 3) {
		// Satin paint
		uniform_real_distribution<float> satinGloss{ 25.5, 35.0 };
		p->setGlossLevel(satinGloss(num));
	}
	else if (c == 4) {
		// Semigloss paint
		uniform_real_distribution<float> semiGloss{ 35.5, 70.0 };
		p->setGlossLevel(semiGloss(num));
	}
	else if (c == 5) {
		// Highgloss paint
		uniform_real_distribution<float> highGloss{ 85.0, 95.0 };
		p->setGlossLevel(highGloss(num));
	}

	return type;
}

void addFromFile(Paint* paints[])
{
	string c, fname, empty;
	float nc, g;
	// paint type is a template

	cout << "what file would you like to use? " << endl;
	cin.ignore(100000000, '\n');
	getline(cin, fname);
	fname = errorCheckString(fname);



	ifstream inFile;
	inFile.open(fname);
	
		if (!inFile.fail())
		{
			// if the file opens correctly (!fail)
			for (int i = 0; i < 7; i++)
			{
				// Get inputs first
				// Check gloss to determine type of paint
				inFile >> c;
				inFile >> nc;
				inFile >> g;

				// for paint from file, the gloss level determines the type
				// after gloss has been saved, the object will be saved to
				// the corresponding class of paint object
				if (g >= 85 && g <= 95)
				{
					paints[i] = new HighGloss(c, g, nc);
				}
				else if (g >= 35.5 && g <= 70)
				{
					paints[i] = new SemiGloss(c, g, nc);
				}
				else if (g >= 25.5 && g <= 35)
				{
					paints[i] = new Satin(c, g, nc);
				}
				else if (g >= 10.5 && g <= 25)
				{
					paints[i] = new Eggshell(c, g, nc);
				}
				else if (g >= 0.1 && g <= 5)
				{
					paints[i] = new Flat(c, g, nc);
				}

				getline(inFile, empty);
			}
		}

		if (!inFile.eof() && inFile.fail())
		{
			// if the file is not over, and the file does not open
			cout << "File did not open correctly. Please retry." << endl;
			addFromFile(paints);
		}

	// clean up
	inFile.close();
}

void adjust(Paint* paints[])
{
	// changing the number of cans for 1 value
	int choice{ 0 };
	float newCans{ 0 };

	// user selects which # to change
	cout << endl  << "Which Paint # would you like to adjust: " << endl;
	cin >> choice;
	choice = errorCheckNum<int>(choice, 1, 7);

	// show user the info for the object they have selected
	cout << "Current information for #" << choice << ": " << endl;
	cout << *paints[--choice] << endl;

	// let user change value
	cout << "How many cans should there be: " << endl;
	cin >> newCans;
	newCans = errorCheckNum<float>(newCans, 0, 1000000000);
	paints[choice]->setNumCans(newCans);

	system("CLS");
	// display updated information for user
	cout << "The new information for #" << ++choice << ": " << endl;
	cout << *paints[--choice] << endl;

}

void printInventory(Paint* paints[])
{
	// print info for user
	cout << "#     " << "Paint Color   " << "Number of Cans" << "    Gloss Level (%)" << endl;
	
	// loop through the paints[] array printing to console
	for (int i = 0; i < 7; i++)
	{
		cout << fixed << setw(5) << left << i + 1
			<< setw(12) << right << paints[i]->getColor()
			<< setprecision(1) << setw(17) << paints[i]->getNumCans()
			<< setprecision(4) << setw(19) << paints[i]->getGlossLevel()
			<< endl;
	}
}

void viewHelp(Paint* paints[])
{
	// show user the help message for their selection
	int choice{ 0 };
	cout << endl << "Which Paint # would you like to see the help message for: ";
	cin >> choice;
	choice = errorCheckNum<int>(choice, 1, 7);

	// show user the paint object they have selected
	cout << *paints[--choice] << endl << endl;

	// print help message
	paints[choice]->help();
}

void printToFile(Paint* paints[])
{
	// print to a file
	string fname;
	cout << "Name of file to be created:" << endl;
	cin.ignore(10000, '\n');
	getline(cin, fname);
	fname = errorCheckString(fname);

	// open the file
	ofstream outfile;
	outfile.open(fname);

	// if the file opening does not fail
	if (!outfile.fail())
	{
		// same logic is printInventory()
		outfile << "#     " << "Paint Color   " << "Number of Cans" << "    Gloss Level (%)" << endl;
		for (int i = 0; i < 7; i++)
		{
			outfile << fixed << setw(5) << left << i + 1
				<< setw(12) << right << paints[i]->getColor()
				<< setprecision(1) << setw(17) << paints[i]->getNumCans()
				<< setprecision(4) << setw(19) << paints[i]->getGlossLevel()
				<< endl;
		}
		cout << "file created sucessfully." << endl;
	}
	else
		// if the file does not create sucessfully, inform user
		cout << "file creation failed." << endl;
}