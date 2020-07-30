/*
 * Name:Pierce Tarleton
 * Date Submitted:1/15/2019
 * Lab Section: 4
 * Assignment Name: lab 4 Searching and Sorting
 */

#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <random>

using namespace std;

template <class T>
std::vector<T> mergeSort(std::vector<T> lst){
    
    //Declaring variables
    int half = lst.size()/2;
    vector<T> merge1;
    vector<T> merge2;
    
    //if the vector is has a size greater than 1 it splits the vector into two then sends the two vectors into mergesort(), and stores the results.
    if(lst.size() > 1){
        vector <T> split1;
        vector <T> split2;
        split1.assign(lst.begin(), lst.begin()+half);
        split2.assign(lst.begin()+half, lst.end());
        vector<T> copyMer1 = mergeSort(split1);
        vector<T> copyMer2 = mergeSort(split2);
        merge1.assign(copyMer1.begin(), copyMer1.end());
        merge2.assign(copyMer2.begin(), copyMer2.end());
    }
    
    // if the vector has a size of 1 it returns the vector
    if(lst.size() == 1){
        return lst;
    }
    
    //merges the vector together. Deleting the element from merge1 or merge2 after it has been merged in to lst.
    for(int i = 0; i<lst.size(); i++){
        if(merge1.empty()){
            lst[i] = merge2[0];
            merge2.erase(merge2.begin());
        }
        else if(merge2.empty()){
            lst[i] = merge1[0];
            merge1.erase(merge1.begin());
        }
        else if(merge1[0] > merge2[0]){
            lst[i] = merge2[0];
            merge2.erase(merge2.begin());
        }
        else if(merge1[0] < merge2[0]){
            lst[i] = merge1[0];
            merge1.erase(merge1.begin());
        }
        else if(merge1[0] == merge2[0]){
            lst[i] = merge1[0];
            merge1.erase(merge1.begin());
        }
    }
    return lst;
}


//used to generate a random int for the position of the pivot in quickSort()
int randomInt(int min, int max){
    mt19937 generator (random());
    uniform_int_distribution<int> dist(min, max);
    return dist(generator);
}

//checks if the random number has already been used
bool contains(int target, vector<int> used){
    for (auto i : used){
      if(i == target){
          return true;
      }
    }
    return false;
}


template <class T>
std::vector<T> quickSort(std::vector<T> lst){
    
    //Declaring variables
    random_device random;
    int pivot, greatpos, smallpos;
    T greaterValue;
    T smallerValue;
    vector<int> positionsUsed;
    
    //Sortign Vector
    while(positionsUsed.size() != lst.size()){
        //generate Pivot point and check if it has already been used
        pivot = randomInt(0, lst.size()-1);
        if(!contains(pivot, positionsUsed)){
            
            //iterates through vector finding outofplace values
            for(int i = 0; i <=pivot+1; i++){
                //ensure that i dose not go pased the end of the vector
                if(i == lst.size()-1){
                    break;
                }
                for(int o = lst.size()-1; o>=pivot; o--){
                    
                    //stores the out of place value and their positions then exits the loop
                    if(lst[i] > lst[pivot] && lst[o] < lst[pivot]){
                        if(!(o<=pivot) && !(i>=pivot)){
                            greaterValue = lst[i];
                            smallerValue = lst[o];
                            greatpos = i;
                            smallpos = o;
                            break;

                        }
                    }
                    
                    //if there is no value out of place on the right saves the pivot value in smallerValue and the value at i in greaterValue, as well as saving their positions. Then changing the position of the pivot to i, and breaking the loop.
                    if(lst[i] > lst[pivot] && lst[o] > lst[pivot]){
                        if(!(i>=pivot)){
                            smallerValue = lst[pivot];
                            greaterValue = lst[i];
                            greatpos = i;
                            smallpos = pivot;
                            pivot = i;
                            break;
                        }
                    }
                    
                    //if i is greater than pivot and there is no value out of place on the left stores the pivot value in greaterValue and the value at o in smallerValue, as well as storing their positions. Then change pivot's positions to o, sets i to zero, and breaks the loop.
                    if(i>=pivot){
                        if(lst[i] > lst[pivot] && lst[o] < lst[pivot]){
                            greaterValue = lst[pivot];
                            smallerValue = lst[o];
                            smallpos = o;
                            greatpos = pivot;
                            pivot = o;
                            i=0;
                            break;
                        }
                    }
                    
                    //if i is greater than pivot and there is no value out of place on the left stores the pivot value in greaterValue and the value at o in smallerValue, as well as storing their positions. Then change pivot's positions to o and breaks the loop.
                    if(lst[i] <= lst[pivot] && lst[o] < lst[pivot]){
                            greaterValue = lst[pivot];
                            smallerValue = lst[o];
                            smallpos = o;
                            greatpos = pivot;
                            pivot = o;
                            break;
                    }
                    //prevents the replacement of an element with the null value of the data type
                    greaterValue = lst[smallpos];
                    smallerValue = lst[greatpos];
                }
                
                //switches the value stored in smallerValue with the value in greaterValue
                lst[smallpos] = greaterValue;
                lst[greatpos] = smallerValue;
            }
            //stores the position of the pivot for comparison
            positionsUsed.push_back(pivot);
        }
    }
    return lst;
}
