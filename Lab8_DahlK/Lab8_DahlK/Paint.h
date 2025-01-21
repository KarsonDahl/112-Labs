#pragma once
#include <string>
#include <iostream>
#include <iomanip>

class Paint
{
	// friend functions!!
	friend std::ostream& operator<<(std::ostream& output, const Paint& p);
public:
	// default construction
	Paint();

	// full 3 argument constructor
	Paint(std::string, float, float);

	// copy constrcutor
	// this is called every time I add an object due to the way I set up my functions
	Paint(const Paint& p);

	// destructor, virtual so it runs later
	virtual ~Paint();

	// setters
	void setColor(std::string);
	void setGlossLevel(float);
	void setNumCans(float);

	// getters
	std::string getColor() const;
	float getGlossLevel() const;
	float getNumCans() const;
	// virtual function set to 0, needs to be redefined to be called
	virtual void help() = 0;

	// operator overloading
	void operator=(const Paint& p);
	bool operator!=(const Paint& p);
private:
	// private variable pointers
	std::string* color;
	float* gloss_level, *num_cans;
};

// overloaded extraction operator 
std::ostream& operator<<(std::ostream& output, const Paint& p)
{
	output << std::endl << "Color:              " << std::setw(20) << std::right << p.getColor() << std::endl;
	output << "Number of Cans:     " << std::setw(20) << std::right << std::fixed << std::setprecision(1) << p.getNumCans() << std::endl;
	output << "Gloss Level:        " << std::setw(20) << std::right << std::setprecision(4) << p.getGlossLevel()  << "%" << std::endl;
	return output;
}

// default construction
Paint::Paint()
{
	std::cout << "in the Paint default constructor" << std::endl;
	color = new std::string;
	gloss_level = new float;
	num_cans = new float;
	setColor("NULL");
	setGlossLevel(0.0);
	setNumCans(0);
}

// 3 argument construction
Paint::Paint(std::string c, float g, float nc)
{
	std::cout << "in the Paint full constructor" << std::endl;
	color = new std::string;
	gloss_level = new float;
	num_cans = new float;
	setColor(c);
	setGlossLevel(g);
	setNumCans(nc);
}

// copy constructor
Paint::Paint(const Paint& p)
{
	color = new std::string;
	gloss_level = new float;
	num_cans = new float;
	*this->color = *p.color;
	*this->num_cans = *p.num_cans;
	*this->gloss_level = *p.gloss_level;
}

// destructor
Paint::~Paint() 
{
	std::cout << "in the Paint destructor" << std::endl;
	delete color;
	delete gloss_level;
	delete num_cans;
	color = nullptr;
	gloss_level = nullptr;
	num_cans = nullptr;
}

// setters
void Paint::setColor(std::string c) 
{
	if (!std::cin.fail()) *color = c; 
	else std::cout << "Error. Invalid value entered. " << std::endl; 
}

void Paint::setGlossLevel(float g) 
{
	if (!std::cin.fail()) *gloss_level = g;
	else std::cout << "Error. Invalid value entered. " << std::endl;
}

void Paint::setNumCans(float nc) 
{
	if (!std::cin.fail()) *num_cans = nc; 
	else std::cout << "Error. Invalid value entered. " << std::endl;
}

// getters
std::string Paint::getColor() const { return *color; }
float Paint::getGlossLevel() const { return *gloss_level; }
float Paint::getNumCans() const { return *num_cans; }

// overload equals operator
void Paint::operator=(const Paint& p)
{
	*this->color = *p.color;
	*this->num_cans = *p.num_cans;
	*this->gloss_level = *p.gloss_level;
}

// overload not equals operator
bool Paint::operator!=(const Paint& p)
{
	if((*this->color) != (*p.color) ||
		(*this->num_cans) != (*p.num_cans) ||
		(*this->gloss_level) != (*p.gloss_level))
		return true;
	else 
		return false;
}