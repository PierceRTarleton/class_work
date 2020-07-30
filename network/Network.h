/*
 * Name:Pierce Tarleton
 * Date Submitted:2/27/2019
 * Lab Section:4
 * Assignment Name:Lab 6 Network
 */

#include <map>
#include "ArrayPriorityQueue.h"

using namespace std;

//structure to hold the values of the packages
typedef struct{
    int id;
    string customer;
}package;

class Network{
  private:
    ArrayPriorityQueue<package> packages;
    int totalProcessedPacks;
    map<string, int> processedPacks;
  public:
    Network();
    void print();
    int remainingPackets();
    int totalProcessedPackets();
    int numberPacketsProcessed(string customer);
    void process(int action, int id, string customer);
};


