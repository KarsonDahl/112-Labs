#pragma once

#include <string>

class Vigenere
{
public:

	// default constructor
	Vigenere();

	// full arguemnt (1) constructor
	Vigenere(std::string);

	// destructor
	~Vigenere();

	// setters
	void setKey(std::string);

	// getters
	std::string getKey() const;


	// vigenere encrypt and decryption functions provided by Mrs. Poole
	std::string encrypt(std::string);
	std::string decrypt(std::string);


private:
	std::string key;

	// toupper the key
	std::string capitalizeKey(std::string);
};