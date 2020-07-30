/*
 * Name:Pierce Tarleton
 * Date Submitted:1/30/2019
 * Lab Section:4
 * Assignment Name:Lab 2 set
 */

#pragma once

#include <iostream>
#include <string>
#include "List.h"
using namespace std;

//This class represents a Set implemented via Linked List
//Do not modify anything in the class interface
template <class T>
class ListSet{

 private:
  List<T> set;

 public:
  ListSet();
  ~ListSet();
  int size();
  bool empty();
  void add(T);
  void remove(T);
  bool contains(T);

  //Print the name and this ListSet's size and values to stdout
  //This function is already implemented (no need to change it)
  void print(string name){
    set.print(name);
  }

}; //end of class interface (you may modify the code below)

//Implement all of the functions below

//Construct an empty ListSet by initializig this ListSet's instance variables
template <class T>
ListSet<T>::ListSet(){
    List<T> set;
}

//Destroy all nodes in this ListSet to prevent memory leaks
template <class T>
ListSet<T>::~ListSet(){
}

//Return the size of this ListSet
template <class T>
int ListSet<T>::size(){
    return set.size();
}

//Return true if this ListSet is empty
//Otherwise, return false
template <class T>
bool ListSet<T>::empty(){
    return set.empty();
}

//Create a new node with value, and insert that new node
//into this Set correctly.
template <class T>
void ListSet<T>::add(T value){
    if(!contains(value)){
        set.insert(value);
    }
}

//Remove node with value <target> from the Set
template <class T>
void ListSet<T>::remove(T target){
  set.remove(target);
}

//If there is an element in Set which has the value <target>, return true;
//Otherwise, return false
template <class T>
bool ListSet<T>::contains(T target){
    return set.contains(target);
}
