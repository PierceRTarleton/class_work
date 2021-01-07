/* Pierce Tarleton
	prtarle
	CpSc-1070-001
	Fall 2018
	PA3
	
	This file defines the function of the class dealership*/
#include "dealership.h"

//Default constructor
Dealership::Dealership():
	id(""), 
	iter(inventory.begin())
{

}

//Regular constructor
Dealership::Dealership(string id):
	id(id)
{

}

//Destructor
Dealership::~Dealership(){
}

//Returns Id
string Dealership::getID(){
	return id;
}

//Sets Id
void Dealership::setID(string id){
	this->id = id;
}

//Prints the Info of the Vehicles in the dealership
void Dealership::printInventory(){
	for(iter = inventory.begin(); iter !=inventory.end(); ++iter){
		(*iter)->printInfo();
	}
}

//Returns the number of Vehicles in the Dealership
int Dealership::inventoryCount(){
	return inventory.size();
}

//Adds a Vehicle to the inventory and increments inventoryCount
void Dealership::addVehicle(Vehicle *v){
	inventory.push_back(v);
}

