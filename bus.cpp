#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include "bus.h"

using namespace std;

bus::bus(){
	numSeats = 0;
	mileage = 0;
	numGears = 0;
	topSpeed = 0;
}

bus::~bus(){
}

void bus::Seats(int const a){
	numSeats = a;
}

const int bus::Seats(){
	return numSeats;
}

