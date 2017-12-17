#ifndef NODE_H_
#define NODE_H_
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include "linked.h"
//#include "car.h"
using namespace std;

template <typename T>
class linked;

template <typename T>
class node{
	private:
	T value;
	node<T> *next;
	bool book;
	public:
	node();
	~node();
//template <typename T>
	friend class linked<T>;
};

#endif
