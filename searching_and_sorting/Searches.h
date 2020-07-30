/*
 * Name:Pierce Tarleton
 * Date Submitted:1/15/2019
 * Lab Section: 4
 * Assignment Name: lab 4 Searching and Sorting
 */

#pragma once

#include <vector>
#include <string>
#include "Sorts.h"

using namespace std;

//Iterates through the vector comparing each element to the target if the target is not found it returns -1. If the target is found it returns it's position.
template <class T>
int linearSearch(std::vector<T> data, T target){
    for(int i = 0; i<data.size(); i++){
        if(data[i] == target){
            return i;
        }
    }
    return -1;
}



template <class T>
int binarySearch(std::vector<T> data, T target){
    
    //Declaring variables and sorting the vector
    vector<T> sortData = mergeSort(data);
    int Position = (data.size()-1)/2;
    int Half = (data.size()-1)/2;
    int lastValue = data.size()-1;
    bool stop;
    
    //Search vector
    while(stop){
        Half = Half/2;
        
        //if target is found returns target
        if(sortData[Position] == target){
            return Position;
        }
        
        //if either the beging or the end of the vector is reached target is not in vector so stop search
        if(Position == 0 || Position == lastValue){
            stop = false;
        }
        
        //if the value at the position is less than the target adds half of the number of elements between the current Position and the previous one checked. If half is at zero add 1 the position to get to the last element to check.
        else if(sortData[Position] < target){
            if(Half == 0){
                Position = Position + 1;
            }
            Position = Position + Half;
        }
        
        //if the value at the position is greater than the target set position equal to half of the distance from the end or begining of the vector.
        else{ 
            if(sortData[Position] > target){
                if(Position == 1){
                    Position = 0;
                }
                Position = Half;
            }
        }
    }
    
    //if target is not found return -1.
    return -1;
}
