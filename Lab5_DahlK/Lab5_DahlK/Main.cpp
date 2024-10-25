// maine
/*
The goal of this proggram is to encypt and decypt files. 
these are either files that are already on hand or from the user.
the program will utilize 5 different files: 
Main.cpp, Message.cpp and .h, Vigenere.cpp and .h.
the main storage is a vigenere object 'vig' in message.h and a vector of string values 'token'.
the vigenere object is a string, which represents the key or password that is from the user.
in vigenere.cpp, there is an encrypt function and a decrypt function.
the main logic is within main, call the message class and use the vig (that is verified with a passkey)
then change the message (encrypt/decrypt) then pass back the new string to message 


*/

#include "Message.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>


using namespace std;

int menu();
void tokenize(Message, int);

int main()
{
	int menuC;
	// variable initialization
	


	// prompt user for what they watn the file's name to be 
	

	

	do
	{
		menuC = menu();

		cin.ignore(10000000000, '\n');
		char k[20];
		cout << "What is the keyword for the cipher: ";
		cin.getline(k, 20, '\n');
		Message m(k);

		switch (menuC)
		{
		case 1:
			tokenize(m, menuC);
			system("pause");
			system("cls");
			break;
		case 2:
			tokenize(m, menuC);
			system("pause");
			system("cls");
			break;
		case 3:
			cout << "Exiting program. \n";
			break;
		default:
			cout << "Error. Exit program.";
			return 0;
		}
	} while (menuC != 3);



	system("pause");
	return 0;
}

int menu()
{
	int num;

	// using "\n "  instead of endl looks way nicer 
	cout << setw(25) << right << "Vigenere Cypher\n\n"
		<< "	   Main Menu\n\n"
		<< "	1 - Encrypt\n"
		<< "	2 - Decrypt\n"
		<< "	3 - Quit\n";

	cout << "Please enter selection here: ";
	cin >> num;

	while (cin.fail() || num < 0 && num > 3)
	{
		cin.clear();
		cin.ignore(numeric_limits< streamsize>::max(), '\n'); // gotta have it
		cout << "Error. Please enter a number between 1 and 3. " << endl;
		cin >> num;
	}
	
	return num;
}

void tokenize(Message m, int c)
{
	char paragraph[1001]; // 1001 for 1000 and '\0'
	char delim[] = ". !?;:";
	char* tokenX = NULL;
	char* nextToken = NULL;
	string file;
	// prompt user for the file that they are going to be reading in
	cout << "What is the name of your file including the extension: ";
	getline(cin, file, '\n');
	
	ifstream inFile;

	inFile.open(file);
	inFile.getline(paragraph, 1001, '\n');
	
	if (!inFile.fail())
	{
		tokenX = strtok_s(paragraph, delim, &nextToken);

		while (tokenX != NULL)
		{
			if (c == 1)
				m.tokenEncrypt(tokenX);
			else
				m.tokenDecrypt(tokenX);
			tokenX = strtok_s(NULL, delim, &nextToken);
		}
	}

	// makeFile
	string n;
	cout << "What would you like the name of the new file to be? ";
	//cin.ignore();
	getline(cin, n);
	m.makeFile(n);

	m.showWords();
}