#include "CompletedJob.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>

/*
make a new job
loop through
each time make a pointer to a new job
user input for option either from a file or from console
each time add to the final total
store job into the array of jobs at i
*/

using namespace std;

// function for the job from the console
CompletedJob* userJob();

// function for the job from a file

CompletedJob* fileJob();

// function for the printing out to a file
void fileInvoice(ofstream&, CompletedJob**, float, int, std::string);
void coutInvoice(CompletedJob**, float, int, std::string);


int main()
{
	// variable declaration
	int numJobs = 0;
	float finaltotal = 0.0;
	string month = "NULL";

	// month information
	cout << "Which month would you like to generate an invoice for? "; //<< endl;
	getline(cin, month);
	//cin.ignore(1000000000000, '\n');

	// number of jobs
	cout << "How many jobs would you like to enter?" << endl;
	cin >> numJobs;
	while (cin.fail() || numJobs < 0 && numJobs > 1000)
	{
		cin.clear();
		cin.ignore(numeric_limits< streamsize>::max(), '\n'); // gotta have it
		cout << "Error. Please enter a number between 1 and 1000 for the total number of jobs. " << endl;
		cin >> numJobs;
	}

	// an array of jobs that is using pointers
	CompletedJob** jobs = new CompletedJob*[numJobs];


	for (int i = 0; i < numJobs; i++)
	{
		// looping through the job creating a new one per iteration
		// invoice random number genereation
		CompletedJob* newJob = new CompletedJob();
		newJob->setinvoiceNum(rand() % 1000 + 1);
		int option = 0;

		// option selection
		cout << "Choose an option:         " << endl;
		cout << "1 -- Enter Job manually:  " << endl;
		cout << "2 -- Enter Job from file: " << endl;
		cin >> option;

	
		//selection for options
		if (option == 1)
		{

			cout << "Invoice Number: " << newJob->getinvoiceNum() << endl;

			// prompt user in console
			newJob = userJob();
		}
		else if (option == 2)
		{
			cout << "Invoice Number: " << newJob->getinvoiceNum() << endl;
			// read in from file
			newJob = fileJob();
		}

		// keeping track of the final total by adding each new job's total
		finaltotal += newJob->calcTotal();

		jobs[i] = newJob;
	}

	//system("CLS");
	cin.ignore(1000000000, '\n');

	// opening the file
	string fname;
	cout << "what would you like your file name to be? ";
	getline(cin, fname);
	ofstream outfile;
	outfile.open(fname);

	// print out function (to a file)
	fileInvoice(outfile, jobs, finaltotal, numJobs, month);

	coutInvoice(jobs, finaltotal, numJobs, month);


	// final cout for reaffirmation
	cout << "file created successfully." << endl;
}

CompletedJob* userJob()
{
	// variable declariation
	// temp variables
	CompletedJob* newJob = new CompletedJob();
	int intT = 0;
	string stringT = "";
	float floatT = 0.0;

	// more variables
	int rp, nc; 
	std::string cn; 
	float lc, pc, tc,m;

	// prompt for user input
	cout << "What is the name of the client?" << endl;
	cin.ignore(1000000000, '\n');
	getline(cin, cn);
	newJob->setclientName(cn);
	// set value using getline, since no error checking for getline 

	cout << "How many rooms painted?" << endl;
	cin >> intT;
	while (cin.fail() || intT < 0)
	{
		cin.clear();
		cin.ignore(numeric_limits< streamsize>::max(), '\n'); // gotta have it
		cout << "Error. Please enter a number greater than 0. " << endl;
		cin >> intT;
	}
	// set value to temp value
	rp = intT;
	newJob->setroomsPainted(rp);

	// prompt for user input
	cout << "How much in labor costs?" << endl;
	cin >> floatT;
	while (cin.fail() || floatT < 0)
	{
		cin.clear();
		cin.ignore(numeric_limits< streamsize>::max(), '\n'); // gotta have it
		cout << "Error. Please enter a number greater than 0. " << endl;
		cin >> floatT;
	}
	// set value to temp value
	lc = floatT;
	newJob->setlaborC(lc);

	// prompt for user input
	cout << "How many cans of paint?" << endl;
	cin >> intT;
	while (cin.fail() || intT < 0)
	{
		cin.clear();
		cin.ignore(numeric_limits< streamsize>::max(), '\n'); // gotta have it
		cout << "Error. Please enter a number greater than 0. " << endl;
		cin >> intT;
	}
	// set value to temp value
	nc = intT;
	newJob->setnumCans(nc);

	// prompt for user input
	cout << "How much in product costs?" << endl;
	cin >> floatT;
	while (cin.fail() || floatT < 0)
	{
		cin.clear();
		cin.ignore(numeric_limits< streamsize>::max(), '\n'); // gotta have it
		cout << "Error. Please enter a number greater than 0. " << endl;
		cin >> floatT;
	}
	// set value to temp value
	pc = floatT;
	newJob->setproductC(pc);

	// prompt for user input
	cout << "How much was mileage?" << endl;
	cin >> floatT;
	while (cin.fail() || floatT < 0)
	{
		cin.clear();
		cin.ignore(numeric_limits< streamsize>::max(), '\n'); // gotta have it
		cout << "Error. Please enter a number greater than 0. " << endl;
		cin >> floatT;
	}
	// set value to temp value
	m = floatT;
	newJob->setmileage(m);

	// prompt for user input
	cout << "How much in travel costs?" << endl;
	cin >> floatT;
	while (cin.fail() || floatT < 0)
	{
		cin.clear();
		cin.ignore(numeric_limits< streamsize>::max(), '\n'); // gotta have it
		cout << "Error. Please enter a number greater than 0. " << endl;
		cin >> floatT;
	}
	// set value to temp value
	tc = floatT;
	newJob->settravelC(tc);

	return newJob;
}

CompletedJob* fileJob()
{
	// new job declaration
	CompletedJob* newJob = new CompletedJob();
	// variable declaration
	int rp, nc;
	string cn, fname;
	float lc, pc, tc, m;

	// prompt user for the name of the file to pull data from
	cout << "what file would you like to use? " << endl;
	cin.ignore(100000000, '\n');
	getline(cin, fname);

	// open the file
	ifstream inFile;
	inFile.open(fname);

	if (!inFile.fail())
	{
		// getilne and set
		getline(inFile, cn);
		newJob->setclientName(cn);

		// getilne and set
		inFile >> rp;
		newJob->setroomsPainted(rp);

		// getilne and set
		inFile >> lc;
		newJob->setlaborC(lc);

		// getilne and set
		inFile >> nc;
		newJob->setnumCans(nc);

		// getilne and set
		inFile >> pc;
		newJob->setproductC(pc);

		// getilne and set
		inFile >> m;
		newJob->setmileage(m);

		// getilne and set
		inFile >> tc;
		newJob->settravelC(tc);
	}

	// close file
	inFile.close();

	// return job
	return newJob;
}

void fileInvoice(ofstream& out,  CompletedJob** jobs, float finaltotal, int numJobs, std::string month)
{

	// Invoice specific information
	out << std::setprecision(2) << std::fixed;
	out << "------------------------------------------------------" << endl;
	out << std::setw(36) << "WePaintHouses LLC" << endl;
	out << std::setw(30) << std::right << "Revenue for " << month << endl;
	out << "------------------------------------------------------" << endl << endl;
	// General painting company information
	out << "WePaintHouses LLC" << endl;
	out << "1971 University Blvd" << endl;
	out << "Lynchburg, VA 24502" << endl;
	out << "(434) 4554-545" << endl;
	out << "wepainthousesllc.com" << endl << endl;
	out << "-----------------------------------------------------" << endl;

	// loop through printing each job
	for (int i = 0; i < numJobs; i++)
	{
		jobs[i]->printOut(out);
		out << endl;
	}

	// final cout with the final total
	out << "-----------------------------------------------------" << endl;
	out << std::setw(15) << "Final Revenue for " << std::setw(20) << std::left << month << std::setw(15) << std::right << finaltotal << endl;
	out << "-----------------------------------------------------" << endl << endl;

}

void coutInvoice(CompletedJob** jobs, float finaltotal, int numJobs, std::string month)
{

	// Invoice specific information
	cout << std::setprecision(2) << std::fixed;
	cout << "------------------------------------------------------" << endl;
	cout << std::setw(36) << "WePaintHouses LLC" << endl;
	cout << std::setw(30) << std::right << "Revenue for " << month << endl;
	cout << "------------------------------------------------------" << endl << endl;
	// General painting company information
	cout << "WePaintHouses LLC" << endl;
	cout << "1971 University Blvd" << endl;
	cout << "Lynchburg, VA 24502" << endl;
	cout << "(434) 4554-545" << endl;
	cout << "wepainthousesllc.com" << endl << endl;
	cout << "-----------------------------------------------------" << endl;

	// loop through printing each job
	for (int i = 0; i < numJobs; i++)
	{
			cout << std::setw(33) << std::left << "Client Name: " << std::setw(20) << std::right << jobs[i]->getclientName() << std::endl;
			cout << std::setw(33) << std::left << "   Rooms Painted: " << std::setw(20) << std::right << jobs[i]->getroomsPainted() << std::endl;
			cout << std::setw(33) << std::left << "   Labor Charges: " << std::setw(20) << std::right << jobs[i]->getlaborC() << std::endl;
			cout << std::setw(33) << std::left << "   Paint Cans: " << std::setw(20) << std::right << jobs[i]->getnumCans() << std::endl;
			cout << std::setw(33) << std::left << "   Product Charges: " << std::setw(20) << std::right << jobs[i]->getproductC() << std::endl;
			cout << std::setw(33) << std::left << "   Mileage: " << std::setw(20) << std::right << jobs[i]->getmileage() << std::endl;
			cout << std::setw(33) << std::left << "   Travel Charges: " << std::setw(20) << std::right << jobs[i]->gettravelC() << std::endl;
			cout << std::setw(33) << std::left << "   Total Cost: " << std::setw(20) << std::right << jobs[i]->calcTotal() << std::endl;

		cout << endl;
	}

	// final ccout with the final total
	cout << "-----------------------------------------------------" << endl;
	cout << std::setw(15) << "Final Revenue for " << std::setw(20) << std::left << month << std::setw(15) << std::right << finaltotal << endl;
	cout << "-----------------------------------------------------" << endl << endl;

}