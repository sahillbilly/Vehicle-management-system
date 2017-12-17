#ifndef BUS_H_
#define BUS_H_
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include "car.h"


class bus: public car{
	private:
	int numSeats;
	public:
	bus();
	~bus();
	void Seats(int const);
	const int Seats();
};

#endif
