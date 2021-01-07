/* Pierce Tarleton
	prtarle
	CpSc-1070-001
	Fall 2018
	PA3
	
	This is the header file for the Vehicle class*/

#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Vehicle {
  protected:
  /*Each of these data items represent something any type of vehicle will have
   *so it makes sense these would be in the base class.*/
   string id;
   int year;
   string make;
   string model;
   string color;

  public:
   Vehicle();
   Vehicle(ifstream &infile);
   Vehicle(string id, int year, string make, string model, string color);
   virtual ~Vehicle();
   string getID();
   void setID(string id);
   virtual void printInfo();

};

#endif
