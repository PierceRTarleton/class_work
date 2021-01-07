/* Pierce Tarleton
	prtarle
	CpSc-1070-001
	Fall 2018
	PA3
	
	The Header file for the Truck class*/

#ifndef TRUCK_H
#define TRUCK_H

#include "vehicle.h"

using namespace std;

class Truck : public Vehicle {
  public:
   Truck();
   Truck(ifstream &infile);
   Truck(string id, int year, string make, string model, string color,
          int axles, double grossWt);
   ~Truck();
   int getAxles();
   double getWeight();
   void setAxles(int ax);
   void setWeight(double wt);
   void printInfo();

  private:
   int axles;
   double weight;

};

#endif   
