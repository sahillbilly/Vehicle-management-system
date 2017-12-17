#ifndef TRUCK_H_
#define TRUCK_H_
#include "car.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>

class truck:public car{
	private:
	int vol;
	int load;
	public:
	truck();
	~truck();
	void setVol(int const);
	void setLoad(int const);
	const int getVol();
	const int getLoad();
};

#endif
