#pragma once
#include "Paint.h"

class HighGloss : public Paint
{
public:
	HighGloss();

	HighGloss(std::string, float, float);

	~HighGloss();

	void help() override;
};

// default construction
HighGloss::HighGloss() : Paint()
{
	std::cout << "in the HighGloss default constructor" << std::endl;
}

// 3 argument construction
HighGloss::HighGloss(std::string c, float g, float nc) : Paint(c, g, nc)
{
	std::cout << "in the HighGloss full constructor" << std::endl;
}

// destructor
HighGloss::~HighGloss() { std::cout << "in the HighGloss destructor" << std::endl; }

void HighGloss::help()
{
	// unique help message that overrides the virtual function in Paint.h
	std::cout << "High-gloss is the shiniest type of paint we offer, and also the most durable and washable.  It can also be used as an outdoor paint!  It is best for doors, trim, and cabinetry as it can show many imperfections if applied incorrectly." << std::endl;
}