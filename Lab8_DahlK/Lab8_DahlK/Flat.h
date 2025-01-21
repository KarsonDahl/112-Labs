#pragma once
#include "Paint.h"

class Flat : public Paint
{
public:
	Flat();

	Flat(std::string, float, float);

	~Flat();

	void help() override;
};

// default construction
Flat::Flat() : Paint()
{
	std::cout << "in the Flat default constructor" << std::endl;
}

// 3 argument construction
Flat::Flat(std::string c, float g, float nc) : Paint (c, g, nc)
{
	std::cout << "in the Flat full constructor" << std::endl;
}

// destructor
Flat::~Flat() { std::cout << "in the Flat destructor" << std::endl; }

void Flat::help()
{
	// unique help message that overrides the virtual function in Paint.h
	std::cout << "Flat paint is less durable with less shine but will provide the most coverage. This type of paint is best for low traffic areas." << std::endl;
}