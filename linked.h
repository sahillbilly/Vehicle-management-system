#ifndef LINKED_H_
#define LINKED_H_
#include "node.h"
#include "car.h"
#include "bus.h"
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class node;

template <typename T>
class linked{
	public:
	linked();
	~linked();
	bool empty() const;
	void addtolist(const T& e);
	T getElem(int i) const;  
	node<T>* getNode(int i) const; 
	void remNode(int i);
	void Book(int i);
	void unbook(int i);
	bool getBook(int i);
	void operator +(ifstream&);    // operator overloading to add cars from file
	void add_bus(ifstream&);
	void add_truck(ifstream&);
	bool operator ==(string);   // operator overloading to check if the string is present in linked list as a vehicle name or not.
	void remNode(string);
	void getDetails(string);
	void getBusDetails(string);
	void getTruckDetails(string);
	int getIndex(string);
	void sort(node<T>*);
	void sort_bus(node<T>*);
	void getsorted();
	void getsortedbus();
	int maxMelons();
	int maxPassengersBus();
	int maxPassengersCar();
	private:
	node<T> *head;
};

#endif
