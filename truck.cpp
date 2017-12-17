#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include "car.h"
#include "truck.h"

using namespace std;

truck::truck(){
	mileage = 0;
	numGears = 0;
	topSpeed = 0;
	vol = 0;
	load = 0;
}

truck::~truck(){
}
void truck::setVol(int const a){
	vol = a; 
}

void truck::setLoad(int const a){
	load = a; 
}

const int truck::getLoad(){
	return load;
}

const int truck::getVol(){
	return vol;
}

