/* Pierce Tarleton
	prtarle
	CpSc-1070-001
	Fall 2018
	PA3
	
	This file defines the Functions for the Vehicle class*/
#include "vehicle.h"

using namespace std;

//Default constructor
Vehicle::Vehicle():id(""), year(0), make(""), color("")
{

}

//Parameterized Constructor
Vehicle::Vehicle(ifstream &infile){
	infile>>id>>year>>make>>color;
}

//Regular constructor
Vehicle::Vehicle(string id, int year, string make, string model, string color):
					id(id), year(year), make(make), model(model), color(color)
{

}

//Destructor
Vehicle::~Vehicle(){

}

//Returns the Vehicle's id
string Vehicle::getID(){
	return id;
}

//sets the Vehicle's id
void Vehicle::setID(string id){
	this->id = id;
}

//Prints out the Vehicle's info
void Vehicle::printInfo(){
	cout<<"id:    "<<id<<endl;
	cout<<"year:  "<<year<<endl;
	cout<<"make:  "<<make<<endl;
	cout<<"model: "<<model<<endl;
	cout<<"color: "<<color<<endl;
}
