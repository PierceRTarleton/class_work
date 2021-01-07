/* Pierce Tarleton
	prtarle
	CpSc-1070-001
	Fall 2018
	PA3
	
	The Header file for Dealership*/

#ifndef DEALERSHIP_H
#define DEALERSHIP_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "vehicle.h"

using namespace std;

class Dealership {
  public:
    Dealership();
    Dealership(string id);
    virtual ~Dealership();

    string getID();
    void setID(string id);

    virtual void printInventory();
    int inventoryCount();
    void addVehicle(Vehicle *v);

 private:
   string id;
   vector<Vehicle *> inventory;
   vector<Vehicle *>::iterator iter;
};

#endif
