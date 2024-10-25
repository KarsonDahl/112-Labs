#include "Vigenere.h"

// setters
void Vigenere::setKey(std::string k)
{
	// key can call the capitalization
	 key = capitalizeKey(k);
}

// getters
std::string Vigenere::getKey() const
{
	return key;
}

// default constructor
Vigenere::Vigenere()
{
	key = "";
}

// full arguemnt (1) constructor
Vigenere::Vigenere(std::string k)
{
	setKey(k);
}

// destructor
Vigenere::~Vigenere()
{

}

// capitalization function
std::string Vigenere::capitalizeKey(std::string k)
{
	std::string capital = "";

	for (char K : k) // K is the same as k, just looped for each character instead of as a string
	{
		capital += std::toupper(K); //loops through the new char version of k and capitalizes, adding to the return string
	}

	return capital;
}


std::string Vigenere::encrypt(std::string word)
{
	std::string output;
	for (int i = 0, j = 0; i < word.length(); ++i) {
		char c = word[i];
		if (c >= 'a' && c <= 'z')
			c += 'A' - 'a';
		else if (c < 'A' || c > 'Z')
			continue;
		output += (c + key[j] - 2 * 'A') % 26 + 'A'; //added 'A' to bring it in range of ASCII  alphabet[65 - 90 | A - Z]
			j = (j + 1) % key.length();
	}
	return output;
}
std::string Vigenere::decrypt(std::string word)
{
	std::string output;
	for (int i = 0, j = 0; i < word.length(); ++i) {
		char c = word[i];
		if (c >= 'a' && c <= 'z')
			c += 'A' - 'a';
		else if (c < 'A' || c > 'Z')
			continue;
		output += (c - key[j] + 26) % 26 + 'A'; //added 'A' to bring it in range of ASCII alphabet[65 - 90 | A - Z]
			j = (j + 1) % key.length();
	}
	return output;
}
