/*Pierce Tarleton
  prtarle
  CpSc 1070-001
  Fall 2018
  PA3
  Header file for car*/
#ifndef CAR_H
#define CAR_H

#include "vehicle.h"

class Car : public Vehicle {
  public:
   Car();
   Car(ifstream &infile);
   Car(string id, int year, string make, string model,
       string color, int numberOfDoors);
   ~Car();
   int getDoors();
   void setDoors(int numdoors);
   void printInfo();

 private:
   int doors;
};

#endif
