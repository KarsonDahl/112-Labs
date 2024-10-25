/*
CSCN 112 Lab 3 Composition and Vectors

The algorithmic logic behind this program will be focused on tracking satifaction rates within a class 'Employee'.
This will be accomplished through six main points of interaction from the user- promping for:
1 - Switch/Open Employee File
2 - Create New Employee
3 - Add Score to Current Employee
4 - Save Current Employee Info to File
5 - Print Employee Info
6 - Quit
starting with the first option, the user will have the opportunity to ammend an already existing file.
the second will allow the user to start a new employee file.
the thrid will allow them to add scores to an employee, as long as there is one listed.
four will save the employee and hte new scores.
five will be a cout with all of the information applying to an employee-
this will include the average, high, low, and entire list of scores as well as name, city, and ID.
six will allow the user to exit the program.
there will be logic as for the maintaining of values as they are taken in with a vector that is wihtin the privacy of hte class.


*/

#include <iostream>
#include <fstream>
#include <string> 
#include <iomanip>
#include "Employee.h" // inclusion of header

using namespace std;

// function declarations
void printMenu();
void saveCheck(Employee&);
void openFile(Employee&);
void newEmployee(Employee&);
void AddScore(Employee&);
void wait();

int main()
{
	// variable initialization
	Employee e;
	int cases = 0;

	// looping for the entire program
	while (cases != 6)
	{
		// switch case that has printing as default
		switch (cases)
		{
		case 1: // switch or open
			saveCheck(e);
			openFile(e);
			printMenu();
			break;
		case 2: // create new
			saveCheck(e);
			newEmployee(e);
			printMenu();
			break;
		case 3: // add score to current
			AddScore(e);
			break;
		case 4: // save
			e.saveToFile(e);
			printMenu();
			break;
		case 5: // print
			e.printEmployeeInfo();
			printMenu();
			break;
		default: // default menu print
			printMenu();
		}

		// user inputs
		cout << "Please enter your selection: " << endl;
		cin >> cases;

		// obligatory error checking
		while (cin.fail() || cases > 6 || cases < 1)
		{
			cin.clear();
			cin.ignore(numeric_limits< streamsize>::max(), '\n'); // gotta have it
			cout << "Error. Please enter a value between 1 and 6. " << endl;
			cin >> cases;
		}
	}

	// wait function
	wait();
	return 0;
}

// prints the original menu
void printMenu()
{
	// simple cout stuff with some iomanip
	cout << endl << "**************************************************" << endl;
	cout << fixed << right << setw(27) << "MENU" << endl;
	cout << "Current Employee:" << endl << endl;
	cout << "1 - Switch/Open Employee File" << endl;
	cout << "2 - Create New Employee" << endl;
	cout << "3 - Add Score to Current Employee" << endl;
	cout << "4 - Save Current Employee Info to File" << endl;
	cout << "5 - Print Employee Info" << endl;
	cout << "6 - Quit" << endl << endl;
	cout << "**************************************************" << endl << endl;
}

// see if user desires to save their additions
void saveCheck(Employee& e)
{
	// check if there is already a name loaded
	if (e.getName() != "")
	{
		// easy user input
		char temp;
		cout << "There is already an employee listed: " << e.getName() << ". Would you like to save for this employee?" << endl;
		cout << "Enter a Y for yes and N for no: " << endl;
		cin >> temp;

		// using a separate char is not needed but i dont trust toupper
		char tempUp = toupper(temp);

		while (cin.fail() || tempUp != 'Y' && tempUp != 'N')
		{
			// obligatory error checking
			cin.clear();
			cin.ignore(numeric_limits< streamsize>::max(), '\n');
			cout << "Error. Please enter either Y or N. " << endl;
			cin >> temp;
		}

		// if user wants to save
		if (tempUp == 'Y')
		{
			// saves to file for the current employee
			e.saveToFile(e);
			cout << "Saved." << endl << endl;
		}
		else
		{
			// if user does not want to save
			cout << "Did not save." << endl << endl;
		}
	}
}

// opening a file and reading the values to the program
void openFile(Employee& e)
{
	// infiling
	ifstream infile;
	string file, tempS;
	float tempf = 0;

	// just in case there is anything left in the stream
	cin.clear();
	cin.ignore(numeric_limits< streamsize>::max(), '\n');

	cout << "Enter the name of the employee's file (please include the file extention): " << endl;
	// input file's name
	getline(cin, file, '\n');

	// try to open the file!
	infile.open(file);


	// !fail is the same as if it works but instead pain
	if (!infile.fail())
	{
		// reset temps
		e.resetEmployee();

		// 3 becuase 3 lines of file for name ciy ID
		for (int i = 0; i < 3; i++)
		{
			// getline because it is from a file
			getline(infile, tempS, '\n');

			// If file is empty check
			if (tempS == "")
			{
				cout << "Empty file... Exiting program" << endl;
				exit(0);
			}
			switch (i)
			{
			case 0:
				//getting in the name 
				e.setName(tempS);
				break;
			case 1:
				//getting in the city 
				e.setCity(tempS);
				break;
			case 2:
				//getting in the ID
				e.setID(tempS);
				break;
			}

		}
	}
	else
	{
		// obligatory else error statements
		cout << "Unable to locate file." << endl;
	}


	while (!infile.fail() && tempf >= 0)
	{

		infile >> tempf; //read in a value from the file 
		
		//If the file object goes into the fail state, but the eof has not been reached, then the problem is due to reading a non-numeric value into a variable designed to hold a numeric value.

		//If non-numeric value
		if (infile.fail() && !infile.eof())
		{
			cout << "A non-numeric value was found in the scores. Please use a different file. " << endl;
			return;
		}

		// If the file object goes into the fail state, and the eof has been reached, the file object is in the fail state because the program has read past the end of the file.
		// This can occur if the file is empty. 
		// If the file is empty and you try to read in anything, the file object immediately goes into the fail state, and the eof function returns TRUE. 

		//If the number is negative:
		else if (tempf < 0)
		{
			cout << "A negative value was found in the scores. Please use a different file." << endl;
			return;
		}

		//Otherwise, do something with the value read in, such as print it out. 
		else 
		{
			e.addScore(tempf);
		}
		// end of while loop  
	}

	// strange issue where the last value of the read-in gets read in twice
	// this function just removes that second version of the value by erasing the last one on the stack
	if (infile.eof())
	{
		e.removeScore(e.numScores() - 1);
	}
}

// function for creating a new edition of the employee class
void newEmployee(Employee& e)
{
	// for clearing out the values 
	e.resetEmployee();
	string n, c, i;

	// Get the user to enter the employee's name
	cout << "Please enter the employee's name: ";
	cin.ignore(1);
	getline(cin, n, '\n');

	// set Name
	e.setName(n);

	// Get the user to enter the employee's city
	cout << "Please enter the city that the employee will be working: ";
	getline(cin, c, '\n');

	// set City
	e.setCity(c);

	// Get the user to enter the employee's ID
	cout << "Please enter the employee's ID: ";
	getline(cin, i, '\n');

	// set ID
	e.setID(i);
}

// function for creating an instance where scores can be added, mostly error checking
void AddScore(Employee& e)
{
	// as long as there is a name, this will work
	if (e.getName() != "")
	{
		float s = 0;
		// very simple cout and cin for the values

		cout << "Please enter the satisfaction score between 1 and 5:" << endl;
		cin >> s;

		// another bit for error checking
		while (cin.fail() || s > 5 || s < 1)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // gotta use the streamsize MAX!!!
			cout << "Please enter a value between 1 and 5. " << endl;
			cin >> s;
		}

		// this connects the user to the class
		e.addScore(s);
	}
	
	else
	{
		// only reachable if user inputs for this before entering the addition
		cout << "How did we get here?" << endl;
	}
}

// obligatory wait function
void wait()
{
	if (cin.rdbuf()->in_avail() > 0)
	{
		cin.clear();
		cin.ignore(numeric_limits< streamsize>::max(), '\n');
	}
	cout << "Press Enter to continue . . . ";
	cin.get();
}