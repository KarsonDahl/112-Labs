#pragma once
#include "Paint.h"

class SemiGloss : public Paint
{
public:
	SemiGloss();

	SemiGloss(std::string, float, float);

	~SemiGloss();

	void help() override;
};

// default construction
SemiGloss::SemiGloss() : Paint()
{
	std::cout << "in the SemiGloss default constructor" << std::endl;
}

// 3 argument construction
SemiGloss::SemiGloss(std::string c, float g, float nc) : Paint(c, g, nc)
{
	std::cout << "in the SemiGloss full constructor" << std::endl;
}

// destructor
SemiGloss::~SemiGloss() { std::cout << "in the SemiGloss destructor" << std::endl; }

void SemiGloss::help()
{
	// unique help message that overrides the virtual function in Paint.h
	std::cout << "Semi-gloss is a very shiny and reflective paint.  It is durable and resistant to mildew, but will show more imperfections than flat, eggshell, or satin paint. This type of paint is great for rooms that have high moisture or high levels of wear and tear." << std::endl;
}