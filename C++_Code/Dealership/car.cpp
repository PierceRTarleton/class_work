
/* Pierce Tarleton
	ptarle
	CPSC-1070-001 Fall 2018
	PA3
	
	This file defines all of the functions for the car class*/

#include "car.h"

using namespace std;

//Default constructor
Car::Car():doors(0)			
{
	
}

//This Parameterized construcor reads in the information from a file
Car::Car(ifstream &infile){
	infile>>id>>year>>make>>model>>color>>doors;
}

//Regualar contructor
Car::Car(string id, int year, string make, string model, 
			string color, int numberOfDoors):
			Vehicle(id, year,make, model, color), 
			doors(numberOfDoors)
{

}

//Deconstructor
Car::~Car(){

}

//returns the number of doors on the car
int Car::getDoors(){
	return doors;
}

//sets the number of doors on the car
void Car::setDoors(int numdoors){
	doors = numdoors;
}

//prints the informaton
void Car::printInfo(){
	cout<<"id:     "<<id<<endl;
	cout<<"year:   "<<year<<endl;
	cout<<"make:   "<<make<<endl;
	cout<<"model:  "<<model<<endl;
	cout<<"color:  "<<color<<endl;
	cout<<"Doors:    "<<doors<<endl;
	cout<<" "<<endl;
}

