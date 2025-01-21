#pragma once
#include "Paint.h"

class Eggshell : public Paint
{
public:
	Eggshell();

	Eggshell(std::string, float, float);

	~Eggshell();

	void help() override;
};

// default construction
Eggshell::Eggshell() : Paint()
{
	std::cout << "in the Eggshell default constructor" << std::endl;
}

// 3 argument construction
Eggshell::Eggshell(std::string c, float g, float nc) : Paint(c, g, nc)
{
	std::cout << "in the Eggshell full constructor" << std::endl;
}

// destructor
Eggshell::~Eggshell() { std::cout << "in the Eggshell destructor" << std::endl; }

void Eggshell::help()
{
	// unique help message that overrides the virtual function in Paint.h
	std::cout << "Eggshell paint is more durable that flat paint and has slightly more luster.This type of paint is great for places that experience low or medium traffic." << std::endl;
}