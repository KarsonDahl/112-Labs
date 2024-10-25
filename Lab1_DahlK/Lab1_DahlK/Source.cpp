/*

Loan Amortization (recursion)
Source.cpp

This program will calculate a loan payment and produces an amortization schedule

prompt user for
- principal (amount borrowed)
- annual interest rate ((taken in as a percent will need to be /10 for decimal) will need to be /12)
- 5, 10, or 15 year fixed loan (this will give us n, our # of iterations [60, 120, 180])

calculate the payment as per the formula given
- balance + total interest 

print a menu displaying the relevant information for the user

looping through the same principle of a loan and subtracting per payment

an if loop should suffice
- for iterations less than n, take the balance of n-1 times the monthly interest rate

Created by: Karson Dahl
Create date: 8/22/2024

*/

#include <iostream>
#include <iomanip>
#include <cmath>
// cmath is nessacary for pow()

using namespace std; // not in header files!


// funciton declariations!!!

double UserPcpl(double);
int UserYears(int);
void wait();
double paymentCalc(double, int, double);
void Amortize(double, double, int, int, double);
double UserIrate(double);

int main()
{
	// system("pause");
	// less efficient than the wait program given by sipantzi (slower, less secure, doesn't run mac) TEST QUESTION
	static double payment = 0;
	static double irate = 0;
	static int years = 0;
	static double pcpl = 0;

	// The purpose of having the values as doubles and ints here is so that they can interact with the later functions.
	double principal = 0;
	double interest = 0;
	int period = 0;
	int i = 0;
	double perc = 0;

	// Keep main lean

	principal = UserPcpl(pcpl);
	// principal for loan

	period = UserYears(years);
	// loan in as years but stored as total number of periods for calculation

	interest = UserIrate(irate);

	perc = (interest / 100) / 12;
	//payment = ((principal) * ((perc * pow((perc + 1), period)) / (pow((perc + 1), period) - 1)));

	payment = paymentCalc(principal, period, perc);

	//displaying the results for the user before they see the whole thing
	cout << fixed << setprecision(2) << left << setw(15) << "Balance: $" << left << setw(15) << principal << endl;
	cout << left << setw(15) << "Interest rate: " << interest << "%" << left << setw(15) << endl;

	wait();
	// Giving the user the oppurtunity to actually see the balance and interest rate before the whole log

	// formatting for the final results to look good
	cout << setw(10) << "Payment #" << setw(15) << "Amount" << setw(15) << "Principal" << setw(15) << "Interest" << endl;
	
	// recursive function taht calls itself
	Amortize(payment, principal, i, period, perc);

	// wait function that was provided for us
	wait();

	return 0;
	// ends with no errors
}


int UserYears(int years)
{
	int temp = 0;

	// get user input
	cout << "How many years will your term be? Please enter either a 5, 10, or 15. " << endl;
	cin >> years;

	// routine error checking using a while loop
	while (cin.fail() || (years != 5 && years != 10 && years != 15))
	{
		cout << "Sorry, there seems to be an error. Please try again, entering either a 5, 10, or 15. " << endl;
		cin.clear();
		cin.ignore(numeric_limits< streamsize>::max(), '\n');

		// reentering the values
		cin >> years;
	}

	if (years == 5)
	{
		// case which uses the number of years times by 12 months, resulting in 60
		temp = 60;
	}

	else if (years == 10)
	{
		// case which uses the number of years times by 12 months, totaling 120
		temp = 120;
	}

	else if (years == 15)
	{
		// case which uses the number of years times by 12 months, giving you 180
		temp = 180;
	}

	else
	{
		// in the event of an unsucessful run, it will run again
		UserYears(years);
	}

	// let user know their choice is accurate
	cout << "Your loan term is " << years << " years. " << endl << endl;

	//return to main
	return temp;
}

double UserPcpl(double pcpl)
{
	// get user input
	cout << "How much money will your loan be? " << endl;
	cin >> pcpl;

	// routine error checking using a while loop
	while (cin.fail() || pcpl < 0)
	{
		cout << "Please enter a valid amount: a number greater than 0." << endl;
		cin.clear();
		cin.ignore(numeric_limits< streamsize>::max(), '\n');
		cin >> pcpl;
	}

	//let user see what their input was taken in as
	cout << "Ok! Your loan principal is $" << pcpl << endl << endl;

	// returning the resulting value to main
	return pcpl;
}

double UserIrate(double irate)
{
	// get user input
	cout << "What percentage will you pay in interest annually? " << endl;
	cin >> irate;

	// routine error checking using a while loop
	while (cin.fail() || irate < 0)
	{
		cout << "Please enter a valid amount: a percentage greater than 0." << endl;
		cin.clear();
		cin.ignore(numeric_limits< streamsize>::max(), '\n');
		cin >> irate;
	}

	//let user see what their input was taken in as
	cout << "Ok! Your interest rate is " << irate << "% annually. " << endl << endl;

	// returning the resulting value to main
	return irate;
}

double paymentCalc(double principal, int period, double perc)
{
	double result = 0;
	// Calculation for the monthly payment
	result = ((principal) * ((perc * pow((perc + 1), period)) / (pow((perc + 1), period) - 1)));

	//returning the resulting value to main
	return result;
}


void Amortize(double payment, double principal, int i, int period, double perc)
{
	// setting up to get the interest taken care of
	double interestPer = 0;

	// calculation for how much interest will be taking away each payment
	interestPer = principal * perc;

	// how the balance will be reduced every time
	principal -= payment - interestPer;

	if (i <= period)
	{
		//real looping!!! when the number of iterations is less than the number of periods

		if (principal < 0)
		{
			// when the principal is less than 0, its over. principal = 0
			principal = 0;
		}
		else
		{
			// this cout is what prints the entire menu of payments for the user
			cout << setw(10) << i << setw(15) << payment << setw(15) << principal << setw(15) << interestPer << endl;
			
			// looping requires a stopping, and this ++ increase to the iteration tracker is what keeps it in check.
			i++;

			// gotta recall the function
			Amortize(payment, principal, i, period, perc);
		}
	}
	else
		// once i < period, the function is complete.
		return;
}


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