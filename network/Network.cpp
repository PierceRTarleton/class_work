/*
 * Name:Pierce Tarleton
 * Date Submitted:2/27/2019
 * Lab Section:4
 * Assignment Name:Lab 6 Network
 */

#include "Network.h"

using namespace std;

// Constructor
Network::Network() {
    ArrayPriorityQueue<package> packages;
    totalProcessedPacks = 0;
    map<string, int> processedPacks;
}

/*  prints the number of processed packages, number 
    of packages processed for each customer, the number 
    of packages left tobe processed, and the values of 
    the packages left to be processed*/
void Network::print() {
    cout << "Total Number of Processed Packages:";
    cout << totalProcessedPackets() << endl;
    cout << "Number of Processed ";
    cout << "Packages for each Customer: " << endl;
    for (auto i : processedPacks) {
      cout << i.first << " : " << i.second << endl;
    }
    cout << "Number of Packages Left to ";
    cout << "Process: " << remainingPackets() << endl;
    cout << "Packages left to Process: " << endl;
    packages.print();
    cout << endl;
}

//  returns the size of the priority queue packages
int Network::remainingPackets() {
    return packages.size();
}

//  returns the total number of packages processed
int Network::totalProcessedPackets() {
    return totalProcessedPacks;
}

//  returns the number of packages processed for the specified customer
int Network::numberPacketsProcessed(string customer) {
    return processedPacks.at(customer);
}

/*  creates a new package using the values sent in as arguments. 
    Then if action is equal to 1 then it adds the package to the
    priority queue packages with the correct priority based on 
    the customer string.*/
void Network::process(int action, int id, string customer) {
    package NewP = {id, customer};
    if (action == 1) {
        if (customer == "Comcast") {
            packages.enqueue(NewP, 7.0);
        } else
        if (customer == "Verizon") {
            packages.enqueue(NewP, 6.0);
        } else
        if (customer == "Apple" || customer == "Google"
        || customer == "Amazon") {
            packages.enqueue(NewP, 5.0);
        } else
        if (customer == "Facebook" || customer == "Twitter"
        || customer == "SnapChat") {
            packages.enqueue(NewP, 4.0);
        } else
        if (customer == "Netflix") {
            packages.enqueue(NewP, 3.0);
        } else
        if (customer == "Hulu") {
            packages.enqueue(NewP, 2.0);
        } else
        if (customer == "email") {
            packages.enqueue(NewP, 1.0);
        }
        
    /*  If action equals zero and customer does not equal quit 
        then it gets the first package from packages and adds 
        one to the totalProcessedPacks and to the number stored 
        in the map processedPacks for that customer of how many 
        packs have been processed for that customer*/
    } else if (action == 0 && customer != "quit") {
        package Temp = packages.dequeue();
        processedPacks[Temp.customer] += 1;
        totalProcessedPacks += 1;
    }
}
