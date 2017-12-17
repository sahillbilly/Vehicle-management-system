#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include "car.h"
using namespace std;

car::car(){
	mileage = 0;
	numGears = 0;
	topSpeed = 0;
}

car::~car(){
}

void car::setName(string const a){
	name = a;
}

void car::Color(string const a){
	color = a;
}

void car::Mileage(int const a){
	mileage = a;
}

void car::TopSpeed(int const a){
	topSpeed = a;
}

void car::NumGears(int const a){
	numGears = a;
}

const string car::getName(){
	return name;
}

const string car::Color(){
	return color;
}

const int car::TopSpeed(){
	return topSpeed;
}

const int car::Mileage(){
	return mileage;
}

const int car::NumGears(){
	return numGears;
}
