#include "Message.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

// default constructor
Message::Message()
{
	vig.setKey("");
}

// full arguemnt (1) constructor
Message::Message(std::string key)
{
	vig.setKey(key);
}

// destructor
Message::~Message()
{

}

// showing words function
void Message::showWords()
{
	for (int i = 0; i < token.size(); i++) 
	{
		std::cout << token.at(i) << " ";
	
	}
	std::cout << std::endl;
}


// out to a file
void Message::makeFile(std::string n)
{

	std::ofstream outfile(n);
	 
	// looped outing of word
	for (int i = 0; i < token.size(); i++)
	{
		outfile << token.at(i) << " ";
	}
}

void Message::tokenEncrypt(char* w)
{
	std::string word = w;
	std::string theWord = vig.encrypt(word);
	token.push_back(theWord);
}

void Message::tokenDecrypt(char* w)
{
	std::string word = w;
	std::string theWord = vig.decrypt(word);
	token.push_back(theWord);
}