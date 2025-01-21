#pragma once
#include "Paint.h"

class Satin : public Paint
{
public:
	Satin();

	Satin(std::string, float, float);

	~Satin();

	void help() override;
};

// default construction
Satin::Satin() : Paint()
{
	std::cout << "in the Satin default constructor" << std::endl;
}

// 3 argument construction
Satin::Satin(std::string c, float g, float nc) : Paint(c, g, nc)
{
	std::cout << "in the Satin full constructor" << std::endl;
}

// destructor
Satin::~Satin() { std::cout << "in the Satin destructor" << std::endl; }

void Satin::help()
{
	// unique help message that overrides the virtual function in Paint.h
	std::cout << "Satin paint is the most common interior paint.  It is easier to clean than flat or eggshell, but it can be very tricky to touch-up if errors are made during application.  This type of paint is great for high-traffic areas." << std::endl;
}