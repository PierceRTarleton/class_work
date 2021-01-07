/* Pierce Tarleton
	prtarle
	CpSc-1070-001
	Fall 2018
	PA3
	
	This file defines the functions for the truck class*/

#include "truck.h"
using namespace std;

//Defalt cunstructor
Truck::Truck():axles(0), weight(0)
{

}

//Parameterized construtor
Truck::Truck(ifstream &infile){
	infile>>id>>year>>make>>model>>color>>axles>>weight;
}

Truck::Truck(string id, int year, string make, string model, string color,
					int axles, double grossWt):
					Vehicle(id, year, make, model, color), 
					axles(axles), 
					weight(grossWt)					
{
	
}

//Regular constuctor
Truck::~Truck(){
	
}

//Retruns the number of axles
int Truck::getAxles(){
	return axles;
}

//returns the weight of the truck
double Truck::getWeight(){
	return weight;
}

//Set the number of axles
void Truck::setAxles(int ax){
	axles = ax;
}

//sets the weight of the truck
void Truck::setWeight(double wt){
	weight = wt;
}

//Prints the truck's info
void Truck::printInfo(){
	cout<<"id:     "<<id<<endl;
	cout<<"year:   "<<year<<endl;
	cout<<"make:   "<<make<<endl;
	cout<<"model:  "<<model<<endl;
	cout<<"color:  "<<color<<endl;
	cout<<"weight: "<<weight<<endl;
	cout<<" "<<endl;
}
