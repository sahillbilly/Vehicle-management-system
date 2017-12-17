#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include "linked.h"
#include "linked.cpp"
#include "node.h"
#include "node.cpp"
#include "car.h"
#include "bus.h"
#include "truck.h"

using namespace std;

int main(){
	linked<car> list1;
	linked<bus> list2;
	linked<truck> list3;
	ifstream myFile;
	myFile.open("car.txt");
	list1+(myFile);
	ifstream myFile2;
	myFile2.open("bus.txt");
	list2.add_bus(myFile2);
	ifstream myFile3;
	myFile3.open("truck.txt");
	list3.add_truck(myFile3);
	char command;
	while(1){
	cout << "\n\n1.Press 1 to add a vehicle\n2.Press 2 to remove a vehicle\n3.Press 3 to get the details of a vehicle\n4.Press 4 to book a vehicle\n5.Press 5 to unbook a vehicle\n6.Press 6 to know the minimum trucks that can carry your watermelons\n7.Wanna travel! Press 7 to get vehicle details suitable for the number of passengers you have got\n8.Press 8 to exit\n9.Others" << endl;
	cin >> command;
	switch(command){
		case '1':{
		char command2;
		cout << "What type of vehicle do you want to add, enter the number corresponding to it-\n1 for car\t2 for bus\t3 for truck" << endl;
		cin >> command2;
		switch(command2){
			case '1':	{cout << "Type the car name to be entered: " << endl;
						string entered_car;
						cin >> entered_car;
						if (list1==(entered_car)){
							cout << "ERROR: THIS VEHICLE IS ALREADY PRESENT" << endl;
						}
						else{
						car new_car;
						cout << "Add the details like in this format- color mileage topSpeed numGears: ";
						string b;
						int c,d,e;
						cin >> b >> c >> d >> e;
						new_car.setName(entered_car);
						new_car.Color(b);
						new_car.Mileage(c);
						new_car.TopSpeed(d);
						new_car.NumGears(e);
						list1.addtolist(new_car);
						cout << entered_car << "added." << endl;
						}
						break;
			}
			case '2':	{cout << "Type the bus name to be entered: " << endl;
						string entered_bus;
						cin >> entered_bus;
						if (list2==(entered_bus)){
							cout << "ERROR: THIS VEHICLE IS ALREADY PRESENT";
						}
						else{
						bus new_bus;
						cout << "Add the details in this format- color mileage topSpeed numGears numSeats: ";
						string b;
						int c,d,e,f;
						cin >> b >> c >> d >> e >> f;
						new_bus.setName(entered_bus);
						new_bus.Color(b);
						new_bus.Mileage(c);
						new_bus.TopSpeed(d);
						new_bus.NumGears(e);
						new_bus.Seats(f);
						list2.addtolist(new_bus);
						cout << entered_bus << "added." << endl;
						}
						break;
			}
			case '3':	{cout << "Type the truck to be entered: " << endl;
						string entered_truck;
						cin >> entered_truck;
						if (list3==(entered_truck)){
							cout << "ERROR: THIS VEHICLE IS ALREADY PRESENT";
						}
						else{
						truck new_truck;
						cout << "Add the details in this format- color mileage topSpeed numGears weight_capacity vol_capacity: ";
						string b;
						int c,d,e,f,g;
						cin >> b >> c >> d >> e >> f >> g;
						new_truck.setName(entered_truck);
						new_truck.Color(b);
						new_truck.Mileage(c);
						new_truck.TopSpeed(d);
						new_truck.NumGears(e);
						new_truck.setLoad(f);
						new_truck.setVol(g);
						list3.addtolist(new_truck);
						cout << entered_truck << "added." << endl;
						}
						break;
			}
						default:{
						cout << "Please enter a correct alternative" << endl;
						break;
			}
		}
		break;
		}
		case '2':   {string veh_type,rem;
					cout << "Enter the vehicle type to be removed: car or bus or truck: " ;
					cin >> veh_type;
					
					if (veh_type=="car"){
						cout << "Enter the name of vehicle: " ;
						cin >> rem;
						if (list1==(rem)){
							list1.remNode(rem);
							cout << rem << "removed." << endl;
						}
						else
							cout << "No such vehicle" << endl;
						}
					else if (veh_type == "bus"){
						cout << "Enter the name of vehicle: " ;
						cin >> rem;
						if (list2==(rem)){
							list2.remNode(rem);
							cout << rem << "removed." << endl;
						}
						else
							cout << "No such vehicle" << endl;
						}
					else if (veh_type == "truck"){
						cout << "Enter the name of vehicle: " ;
						cin >> rem;
						if (list3==(rem)){
							list3.remNode(rem);
							cout << rem << "removed." << endl;
						}
						else
							cout << "No such vehicle" << endl;	
						}
					else
						cout << "Please enter a correct alternative." << endl;
					break;
		}
		case '3': {    
					string details,det_type;
					cout << "Enter the type of vehicle to know details: car or bus or truck: " << endl;
					cin >> det_type;
					if (det_type == "car"){
						cout << "Enter the vehicle: " << endl;
						cin >> details;	
						if (list1==(details))
							list1.getDetails(details);
						else
							cout << "No such vehicle" << endl;
							}
					else if (det_type == "bus"){
						cout << "Enter the vehicle: " << endl;
						cin >> details;
						if (list2==(details))
							list2.getBusDetails(details);
						else
							cout << "No such vehicle" << endl;
						}
					else if (det_type == "truck"){
						cout << "Enter the vehicle: " << endl;
						cin >> details;
						if (list3==(details))
							list3.getTruckDetails(details);
						else
							cout << "No such vehicle" << endl;	
						}
					else
						cout << "Please enter a correct alternative." << endl;	
					break;
		}
		case '4': {
					string abc,cba;
					cout << "Enter the vehicle type to be booked: car or bus or truck: ";
					cin >> abc;
					if (abc=="car"){
						cout << "Enter the vehicle name: ";
						cin >> cba;
						if (list1==(cba)){
							list1.Book(list1.getIndex(cba));
							list1.getDetails(cba);
							cout << cba << "booked" << endl;
						}
						else
							cout << "No such vehicle" << endl;
						}
					else if (abc == "bus"){
						cout << "Enter the vehicle name: ";
						cin >> cba;
						if (list2==(cba)){
							list2.Book(list2.getIndex(cba));
							list2.getDetails(cba);
							cout << cba << "booked." << endl;
						}
						else
							cout << "No such vehicle" << endl;
						}
					else if (abc == "truck"){
						cout << "Enter the vehicle name: ";
						cin >> cba;
						if (list3==(cba)){ 
							list3.Book(list3.getIndex(cba));
							list3.getDetails(cba);
							cout << cba << "booked." << endl;
						}
						else
							cout << "No such vehicle" << endl;
						}
					else
						cout << "Please enter a correct alternative" << endl;
					break;
		}
		case '5': {
					string abcd,dcba;
					cout << "Enter the vehicle type to be unbooked: car or bus or truck: ";
					cin >> abcd;
					if (abcd=="car"){
						cout << "Enter the vehicle name: ";
						cin >> dcba;
						if (list1==(dcba))
							{list1.unbook(list1.getIndex(dcba));
							cout << dcba << "unbooked." << endl;
							}
						else
							cout << "No such vehicle" << endl;
						}
					else if (abcd == "bus"){
						cout << "Enter the vehicle name: ";
						cin >> dcba;
						if (list2==(dcba))
							{list2.unbook(list2.getIndex(dcba));
							cout << dcba << "unbooked." << endl;
						}
						else
							cout << "No such vehicle" << endl;
						}
					else if (abcd == "truck"){
						cout << "Enter the vehicle name: ";
						cin >> dcba;
						if (list3==(dcba))
							{list3.unbook(list3.getIndex(dcba));
							cout << dcba << "unbooked." << endl;
							}
						else
							cout << "No such vehicle" << endl;
						}
					else
						cout << "Please enter a correct alternative." << endl;
					break;
		}
		case '6': {
					int count=1,num_trucks = 0;
					int num_watermelons;
					cout << "Enter the number of watermelons: ";
					cin >> num_watermelons;	
					if(list3.maxMelons()<num_watermelons){
						cout << "Invalid input: a max of " << list3.maxMelons() << " watermelons can be transported" << endl;
					}
					else{
					list3.getsorted();
					while(num_watermelons>0){
						cout << list3.getElem(count).getName() << endl;
						num_watermelons = num_watermelons-(list3.getElem(count).getVol())/30;
						count++;
						num_trucks++;
					}
					cout << "A total of " << num_trucks << " trucks are required" << endl;
					}
					break;
		}
		case '7': {
					int totalCars=1,totalBuses=1;
					while(list1.getNode(totalCars)!=NULL){
						totalCars++;
					}
					while(list1.getNode(totalBuses)!=NULL){
						totalBuses++;
					}
					totalCars--;
					totalBuses--;
					int passengers,booked_cars=1,booked_buses=1;		// remember they are initialised with 1.
					cout << "Enter the number of passengers: " << endl;
					cin >> passengers;
					if (passengers>(list1.maxPassengersCar()+list2.maxPassengersBus()))
						cout << "Invalid input: a max of " << list1.maxPassengersCar()+list2.maxPassengersBus() << " people can be transported";
					else{
					list2.getsortedbus();
					while(passengers>0){
					if (((list2.getElem(booked_buses).Seats()<5)&&(booked_cars-1<totalCars))||((booked_buses-1)>=totalBuses)){
						cout << list1.getElem(booked_cars).getName() << endl;
						booked_cars++;			
						passengers = passengers-5;
					}
					else if((booked_buses-1)<totalBuses){
						cout << list2.getElem(booked_buses).getName() << endl;
						passengers = passengers - list2.getElem(booked_buses).Seats();
						booked_buses++;
					}
					}
					}
					break;
		}
		case '8': {
					exit(1);
		}
		case '9': {
					cout << "Nothing else to do";
					break;
		}
		default:{
		cout << "Please enter a correct alternative" << endl;
		break;
		}
	}
	}
}
