#include "linked.h"
#include "node.h"
#include "car.h"
#include "truck.h"
#include "bus.h"
#include <bits/stdc++.h>
using namespace std;

template <typename T>
linked<T>::linked(){
	head = NULL;
}

template <typename T>
linked<T>::~linked(){
	while(!empty()){
		node<T> *old = head;
		head = old->next;
		delete old;
	}
}


template <typename T>
void linked<T>::Book(int i){
	node<T> *current = head;
	int count = 1;
	while (current != NULL)
    {
       if (count == i)
          current->book = true;
       count++;
       current = current->next;
    }
}

template <typename T>
void linked<T>::unbook(int i){
	node<T> *current = head;
	int count = 1;
	while (current != NULL)
    {
       if ((count == i)&&(current->book==true)){
          current->book = false;}
       else if ((count == i)&&(current->book==false)){
          cout << "This was not booked." << endl;}
       count++;
       current = current->next;
    }
}

template <typename T>
bool linked<T>::getBook(int i){
	node<T> *current = head;
	int count = 1;
	while (current != NULL)
    {
       if (count == i)
          return current->book;
       count++;
       current = current->next;
    }
}

template <typename T>
bool linked<T>::empty() const{
	if (head==NULL)
		return true;
}

template <typename T>
void linked<T>::addtolist(const T& e){
	node<T> *temp = new node<T>;
	temp->value = e;
	temp->next = head;
	head = temp;
}

template <typename T>
T linked<T>::getElem(int i) const{
	node<T> *current = head;
	int count = 1;
	while (current != NULL)
    {
       if (count == i)
          return current->value;
       count++;
       current = current->next;
    }
}

template <typename T>
node<T>* linked<T>::getNode(int i) const{
	node<T> *current = head;
	int count = 1;
	while (current != NULL)
    {
       if (count == i)
          return current;
       count++;
       current = current->next;
    }
}

template <typename T>
void linked<T>::remNode(int i){
	i--;
	if (head == NULL)
		cout << "No element left" << endl;
		return;
	node<T> *temp = head;
    if (i == 0)
    {
        head = temp->next; 
        delete(temp);            
        return;
    }
    for (int j=0; temp!=NULL && j<i-1; j++)
         temp = temp->next;
    node<T> *next = temp->next->next;
    delete(temp->next);
    temp->next = next;
}








template <typename T>
void linked<T>::operator +(ifstream& myFile){      
	string a,b;
	int c,d,e;
	int count = 0;
	string line;
	while (getline(myFile,line)){
		count++;	
	}
	myFile.clear();
    myFile.seekg(0);
	for (int i=0;i<count;i++){
		myFile >> a >> b >> c >> d >> e;
		car car1;
		car1.setName(a);
		car1.Color(b);
		car1.Mileage(c);
		car1.TopSpeed(d);
		car1.NumGears(e);
		car& car2 = car1;
		addtolist(car2);
	}
}

template <typename T>
void linked<T>::add_bus(ifstream& myFile){
	string a,b;
	int c,d,e,f;
	int count = 0;
	string line;
	while (getline(myFile,line)){
		count++;	
	}
	myFile.clear();
    myFile.seekg(0);
	for (int i=0;i<count;i++){
		myFile >> a >> b >> c >> d >> e >>f;
		bus car1;
		car1.setName(a);
		car1.Color(b);
		car1.Mileage(c);
		car1.TopSpeed(d);
		car1.NumGears(e);
		car1.Seats(f);
		bus& car2 = car1;
		addtolist(car2);
	}
}

template <typename T>
void linked<T>::add_truck(ifstream& myFile){
	string a,b;
	int c,d,e,f,g;
	int count = 0;
	string line;
	while (getline(myFile,line)){
		count++;	
	}
	myFile.clear();
    myFile.seekg(0);
	for (int i=0;i<count;i++){
		myFile >> a >> b >> c >> d >> e >> f >> g;
		truck car1;
		car1.setName(a);
		car1.Color(b);
		car1.Mileage(c);
		car1.TopSpeed(d);
		car1.NumGears(e);
		car1.setLoad(f);
		car1.setVol(g);
		truck& car2 = car1;
		addtolist(car2);
	}
}

template <typename T>
bool linked<T>::operator ==(string vehicle_name){
	int i=1;
	while (getNode(i)!=NULL){
		if (getElem(i).getName()==vehicle_name){
		return true;
		}
		else{
		i++;
		}
	}
	return false;
}

template <typename T>
void linked<T>::remNode(string rem){
	int i = 1;
	while (getNode(i)!=NULL){
		if (getElem(i).getName()==rem){
			remNode(i);
			return;
			}
		i++;
	}
}

template <typename T>
void linked<T>::getDetails(string vehicle){
	int i = 1;
	while (getNode(i)!=NULL){
		if (getElem(i).getName()==vehicle){
			cout << "Name: " << getElem(i).getName() << "\nColor: " << getElem(i).Color() << "\nMileage: " << getElem(i).Mileage() << "\nTopSpeed: " << getElem(i).TopSpeed() << "\nNumGears: " << getElem(i).NumGears() << endl;
			return;
		}
		i++;
	}
	cout << "Car not found" << endl;
}

template <typename T>
void linked<T>::getBusDetails(string vehicle){
	int i = 1;
	while (getNode(i)!=NULL){
		if (getElem(i).getName()==vehicle){
			cout << "Name: " << getElem(i).getName() << "\nColor: " << getElem(i).Color() << "\nMileage: " << getElem(i).Mileage() << "\nTopSpeed: " << getElem(i).TopSpeed() << "\nNumGears: " << getElem(i).NumGears() << "\nSeats: " << getElem(i).Seats() << endl;
			return;
		}
		i++;
	}
}

template <typename T>
void linked<T>::getTruckDetails(string vehicle){
	int i = 1;
	while (getNode(i)!=NULL){
		if (getElem(i).getName()==vehicle){
			cout << "Name: " << getElem(i).getName() << "\nColor: " << getElem(i).Color() << "\nMileage: " << getElem(i).Mileage() << "\nTopSpeed: " << getElem(i).TopSpeed() << "\nNumGears: " << getElem(i).NumGears() << "\nLoad: " << getElem(i).getLoad() << "\nVolume: " << getElem(i).getVol() << endl;
			return;
		}
		i++;
	}
}

template <typename T>
int linked<T>::getIndex(string vehicle){
	int i = 1;
	while (getNode(i)!=NULL){
		if (getElem(i).getName()==vehicle)
			return i;
		i++;
	}
}

template <typename T>
void linked<T>::sort(node<T> *head)			//selection sort
{
	node<T> *start = head;
	node<T> *traverse;
	node<T> *max;
	
	while(start->next)
	{
		max = start;
		traverse = start->next;
		
		while(traverse)
		{
			/* Find maximum element from array */ 
			if( max->value.getVol() < traverse->value.getVol() )
			{
				max = traverse;
			}
			
			traverse = traverse->next;
		}
		T temp = start->value;
		start->value = max->value;
		max->value = temp;			// Put maximum element on starting location
		start = start->next;
	}
}

template <typename T>
void linked<T>::sort_bus(node<T> *head)			//selection sort
{
	node<T> *start = head;
	node<T> *traverse;
	node<T> *max;
	
	while(start->next)
	{
		max = start;
		traverse = start->next;
		
		while(traverse)
		{
			/* Find maximum element from array */ 
			if( max->value.Seats() < traverse->value.Seats() )
			{
				max = traverse;
			}
			
			traverse = traverse->next;
		}
		T temp = start->value;
		start->value = max->value;
		max->value = temp;			// Put maximum element on starting location
		start = start->next;
	}
}

template <typename T>
void linked<T>::getsorted(){
	sort(head);
}

template <typename T>
void linked<T>::getsortedbus(){
	sort_bus(head);
}

template <typename T>
int linked<T>::maxMelons(){
	int i = 1,max=0;
	while(getNode(i)!=NULL){
		max = max + (getElem(i).getVol())/30;
		i++;
	}
	return max;
}

template <typename T>
int linked<T>::maxPassengersBus(){
	int i=1,count=0;
	while(getNode(i)!=NULL){
		count = count + getElem(i).Seats();
		i++;
	}
	return count;
}

template <typename T>
int linked<T>::maxPassengersCar(){
	int i=1,count=0;
	while(getNode(i)!=NULL){
		count = count + 5;
		i++;
	}
	return count;
}
