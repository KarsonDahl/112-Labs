#pragma once

// NO USING NAMESPACE STD

// use the scope resolution operator '::' and 'std'

class Room
{
public:

	// default constructor
	Room();

	// full constructor
	
	Room(float, float, float, int);

	// set functions
	void setHeight(float);
	void setLength(float);
	void setWidth(float);
	void setCoat(int);

	// get functions
	float getHeight() const;
	float getLength() const;
	float getWidth() const;
	int getCoat() const;

	// other functions
	float calcVolume() const;
	float calcPaintedArea() const;
	void showData() const;

private:
	// private variables!!!
	// only reachable through the get functions 
	float height;
	float length;
	float width;
	int coats;
};