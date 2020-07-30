/*
 * Name:Pierce Tarleton
 * Date Submitted:1/30/2019
 * Lab Section:4
 * Assignment Name:Lab 2 set
 */

#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//This class represents a Set implemented via Array (vector)
//Do not modify anything in the class interface
template <class T>
class ArraySet{

 private:
  vector<T> set;

 public:
  ArraySet();
  ~ArraySet();
  int size();
  bool empty();
  void add(T);
  void remove(T);
  bool contains(T);
  //Print the name and this ArraySet's size and values to stdout
  //This function is already implemented (no need to change it)
  void print(string name){
    cout << name << ": ";
    cout << "size = " << set.size();
    cout << ", values = ";
    for (auto i : set){
      cout << i << " ";
    }
    cout << endl;
  }

}; //end of class interface (you may modify the code below)

//Implement all of the functions below

//Construct an empty ArraySet by initializig this ArraySet's instance variables
template <class T>
ArraySet<T>::ArraySet(){
    vector<T> set;
}

//Destroy all nodes in this ArraySet to prevent memory leaks
template <class T>
ArraySet<T>::~ArraySet(){
    set.clear();
}

//Return the size of this ArraySet
template <class T>
int ArraySet<T>::size(){
    return set.size();
}

//Return true if this ArraySet is empty
//Otherwise, return false
template <class T>
bool ArraySet<T>::empty(){
    return set.empty();
}

//Add <value> to the set.
template <class T>
void ArraySet<T>::add(T value){
    if(!contains(value)){
        set.push_back(value);
    }
}

//Remove <target> value from the set.
template <class T>
void ArraySet<T>::remove(T target){
    int count = 0;
    if (!empty()){
        while(set[count] != target){
        count++;
        }
        if(set[count] == target){
            set.erase(set.begin() + count);
        }
    }
}

//If the set contains <target> value, return true;
//Otherwise, return false
template <class T>
bool ArraySet<T>::contains(T target){
    for (auto i : set){
      if(i == target){
          return true;
      }
    }
    return false;
}
