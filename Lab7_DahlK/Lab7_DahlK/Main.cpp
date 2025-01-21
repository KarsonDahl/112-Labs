#include "Department.h"
#include <iostream>
#include <iomanip>
#include <cctype>
#include <stdexcept>

using namespace std;

// there is no base rate given, executive decision that painters make 45k a year

void tokenizeDate(char*, int&, int&, int&);
Person addPerson();
Employee addEmployee();
Manager addManager();
Department addDepartment();
void printmenu();

// error checking
template<class T>
 T errorCheckNum(T, T, T);
 string errorCheckString(string);

int main()
{
	char choice = ' ';
	Department d;
	d = addDepartment();
	//d.addVEmployee(Employee());

	while (choice != 'P')
	{
		
		printmenu();

		cout << "Enter your selection: " << endl;
		cin >> choice;
		choice = toupper(choice);
		switch (choice)
		{
		case 'M':
			// add a manager or check if one already exists
			system("CLS");
			cin.ignore(100000000000000, '\n');
			if (d.getmanager() == Manager()) // if the manager is equal to the default case
			{
				d.setmanager(addManager());
			}
				else
					cout << "A manager already exists: " << endl << d.getmanager() << endl;
				break;
			case 'E':
				system("CLS");
				cin.ignore(100000000000000, '\n');
				if (d.numEmployees() < d.getcapacity())
					d.addVEmployee(addEmployee());
				else
					cout << "Maximum number of employees already created." << endl;
				// add employee vector pushback
				break;
			case 'R':
				system("CLS");
				if (d.numEmployees() != 0)
					d.removeVEmployee();
				else
					cout << "No employees exist." << endl;
				// remove employee
				break;
			case 'L':
				system("CLS");// list department info
				cout << d;
				break;
			case 'P':
				system("CLS");//print final profit report
				d.printfinal(d);
				break;
			default:
				cout << "Invalid value entered. Please try again: " << endl;
				cin.ignore(1000000000000000000, '\n');
				break;
			}

		//cin.clear();
		//cin.ignore(numeric_limits< streamsize>::max(), '\n');
	}

	system("pause");
	return 0;
}


Person addPerson()
{
	// variable declaration
	Person p;
	string fn, ln;
	char d1[12], d2[12];
	int m, d, y, id;
	Date bd, hd;
	bool valid = false;

	//cin.clear();
	//cin.ignore(numeric_limits< streamsize>::max(), '\n');
	// first name
	cout << "First name:" << endl;
	getline(cin, fn);
	errorCheckString(fn);
	p.setfirstName(fn);

	// last name
	cout << "Last name:" << endl;
	getline(cin, ln);
	errorCheckString(ln);
	p.setlastName(ln);

	while (!valid)
	{
		try
		{
			// wrapping the date stuff in a try block
			// this will allow for the error catching and throwing of exceptions
			cout << "What is this person's birthday?: (mm/dd/yyyy) " << endl;
			cin >> d1;
			tokenizeDate(d1, m, d, y); // tokenizing the date with the
			bd.setDate(m, d, y);
			p.setbirthday(bd);
			valid = true;
		}
		catch (exception& e)
		{
			// catching the exception from the try block
			cout << "Birth date error. " << endl;
			cout << e.what() << endl;
		}
	}
	valid = false;

	while (!valid)
	{
		try
		{
			// wrapping the date stuff in a try block
			// this will allow for the error catching and throwing of exceptions
			cout << "When was this person hired?: (mm/dd/yyyy) " << endl;
			cin >> d2;
			tokenizeDate(d2, m, d, y);
			hd.setDate(m, d, y);
			p.sethiringDate(hd);
			valid = true;
		}
		catch (exception& e)
		{
			cout << "Hiring date error. " << endl;
			cout << e.what() << endl;
		}
	}

	cout << "ID: " << endl;
	cin >> id;
	errorCheckNum<int>(id, 0, 1000);
	p.setid(id);

	return p;
}

Manager addManager()
{
	// variable initializion
	char d1[12];
	Date pd;
	int m, d, y;
	float s;
	string t;
	bool valid = false;
	Manager man;
	Person* p = &man;

	cout << "Creating a New Manager" << endl;
	// this will create a person and the aspects of person willl apply to the manager
	*p = addPerson();

	while (!valid)
	{
		try
		{
			// wrapping the date stuff in a try block
			// this will allow for the error catching and throwing of exceptions
			cout << "Promotion Date: " << endl;
			cin >> d1;
			tokenizeDate(d1, m, d, y);
			pd.setDate(m, d, y);
			man.setpromotion(pd);
			valid = true;
		}
		catch (exception& e)
		{
			cout << "Date error. " << endl;
			cout << e.what() << endl;
		}
	}

	// salary information
	cout << "Salary: " << endl;
	cin >> s;
	// error checking
	errorCheckNum<float>(s, 0.0, 10000000000.0);
	man.setsalary(s);

	cin.clear();
	cin.ignore(numeric_limits< streamsize>::max(), '\n');

	// title informations
	cout << "Title:" << endl;
	getline(cin, t);
	errorCheckString(t);
	man.settitle(t);

	// return the manager to the department
	return man;
}

Department addDepartment()
{
	// variable initialization
	Department d;
	string n;
	float pu;
	int maxe;

	// department name informatoin
	cout << "Please enter the department name: " << endl;
	getline(cin, n);
	errorCheckString(n);
	d.setname(n);
	cout << endl;

	// product information
	cout << "Please enter the dollar amount of products this department has used: " << endl << "$";
	cin >> pu;
	// error checking for the product information
	pu = errorCheckNum<float>(pu, 0.0, 10000000000.0);
	d.setproductCost(pu);
	cout << endl;

	// max number of employees
	cout << "Please enter the total capacity (max number of employees) for this department. Must be under 50: " << endl;
	cin >> maxe;
	maxe = errorCheckNum<int>(maxe, 1, 50);
	d.setcapacity(maxe);
	// this sets the maximum size for the vector, and is used at hte end for the final print out as well
	cout << endl;

	return d;
}

Employee addEmployee()
{
	// variable initialization
	int mt;
	float er, j = 0.0;
	Employee e;
	Person* p = &e;

	cout << "Creating a New Employee" << endl;
	// this will create a person and the aspects of person willl apply to the employee
	*p = addPerson();

	cout << "Miles Traveled: " << endl;
	cin >> mt;
	errorCheckNum<int>(mt, 0, 1000000000);
	e.setmilesTraveled(mt);

	// add the employee's rating
	cout << "Employee Rating: " << endl;
	cin >> er;
	errorCheckNum<float>(er, 0.0, 10.0);
	e.setemployeeRating(er);

	// looping for the job additions
	// 
	while (j != -1)
	{
		// prompt user for the job amount
		cout << "Add a Job, how much revenue was generated: " << endl;
		cout << "Enter a -1 to exit " << endl << "$";
		cin >> j;
		j = errorCheckNum<float>(j, -1.0, 1000000000.0);

		// only works if hte job is positive (or 0)
		if (j > -1)
		{
			e.addJob(j);
		}
	}

	return e;
}

// tokenize funciton from Dr. Poole
void tokenizeDate(char* c, int& mon, int& day, int& year) {
	char seps[] = "/";
	char* token = NULL;
	char* next_token = NULL;
	token = NULL;
	next_token = NULL;

	// Establish string and get the tokens:  
	token = strtok_s(c, seps, &next_token);
	// edits for exception handling
	if (token == nullptr)
		throw exception("Month was not long enough.");
	mon = atoi(token);
	token = strtok_s(NULL, seps, &next_token);
	if (token == nullptr)
		throw exception("Day was not long enough.");
	day = atoi(token);
	token = strtok_s(NULL, seps, &next_token);
	if (token == nullptr)
		throw exception("Year was not long enough.");
	year = atoi(token);
	 // straight up throwing these exceptions
}

template<class T> // utilizing templates for error checking is AWESOME!!
T errorCheckNum(T value, T lowcap, T upcap)
{
	// a lowcap and an upcap allow this function to be specilazed for each value
	while (cin.fail() || value < lowcap || value > upcap)
	{
		cin.clear();
		cin.ignore(numeric_limits< streamsize>::max(), '\n'); // gotta have it
		cout << "Error. Please enter a valid value betwen " << lowcap << " and " << fixed << setprecision(2) << upcap << "." << endl;
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

void printmenu()
{
	// standard print out menu
	cout << "    Main Menu" << endl;
	cout << " M -- Add Manager" << endl;
	cout << " E -- Add Employee" << endl;
	cout << " R -- Remove Employee" << endl;
	cout << " L -- List Dept. Info" << endl;
	cout << " P -- Print Final Profit" << endl << endl;
}
