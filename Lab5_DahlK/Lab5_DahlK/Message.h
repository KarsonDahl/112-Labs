#pragma once

#include "Vigenere.h"
#include <vector>

class Message
{
public:

	// default constructor
	Message();

	// full arguemnt (1) constructor
	Message(std::string);

	// destructor
	~Message();

	void showWords();

	void makeFile(std::string);

	void tokenEncrypt(char*);

	void tokenDecrypt(char*);



private:
	// tokenized vector of strings, words that are 
	std::vector<std::string> token;

	// Vigenere object
	Vigenere vig;
};