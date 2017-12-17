#ifndef car_H_
#define car_H_
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;

class car{
	protected:
	string name;
	string color;
	int mileage;
	int topSpeed;
	int numGears;    // modify the constructor and destructor for car initializing data an also initialize book to false.
	public:
	car();
	~car();
	void Color(string const);
	void Mileage(int const);
	void TopSpeed(int const);
	void NumGears(int const);
	void setName(string const);
	const string getName();
	const string Color();       //function overloading to get the color of the car object.
	const int Mileage();		// same as above.
	const int TopSpeed();
	const int NumGears();
};

#endif
