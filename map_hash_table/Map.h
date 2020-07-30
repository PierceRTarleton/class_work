/*
 * Name:Pierce Tarelton
 * Date Submitted:
 * Lab Section: 4
 * Assignment Name: lab 2 Map
 */

#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//This class represents a Map.
//Do not modify anything in the class interface
template <class T>
class Map{

 private:
  vector<T> table;
  int mySize;  //size (or length) of this Map

 public:
  Map(int);
  ~Map();
  int size();
  bool empty();
  void insert(T);
  bool contains(T);
  int find(T);

  //Print the name and this Map's size and values to stdout
  //This function is already implemented (no need to change it)
  void print(string name){
    cout << name << ": ";
    cout << "size = " << size();
    cout << ", values = ";

    for (int i=0; i < table.size(); i++){
      cout << i << ": " << table.at(i) << endl;
    }
    cout << endl;
  }

}; //end of class interface (you may modify the code below)

//Implement all of the functions below

//Construct an empty Map by initializig this Map's instance variables.
//The parameter is the size of the Map's table.
template <class T>
Map<T>::Map(int n){
    mySize = 0;
    table = vector<T>(n);
    //table.reserve(n);
}

//Destroy all nodes in this Map to prevent memory leaks
template <class T>
Map<T>::~Map(){
    table.clear();
}

//Return the size of this Map
template <class T>
int Map<T>::size(){
    return mySize;
}

//Return true if this Map is empty
//Otherwise, return false
template <class T>
bool Map<T>::empty(){
    int cempty = 0;
    for (int i=0; i < mySize; i++){
        if(table[i] == 0){
            cempty++;
        }
    }
    if(cempty == mySize){
        return true;
    }
    else{
        return false;
    }
    //return table.empty();
}

// insert a value into the map.
// the index should be value % size of table
template <class T>
void Map<T>::insert(T value){
    int size = table.size();
    int cvalue = static_cast<int>(table[value%size]);
    //cvalue = static_cast<int>(table[value%table.size()]);
    cout<<value%size<<endl;
    if(isalpha(value)){
        if(mySize == 0){
            for(int i = 0; i <= size; i++){
                table[i] = ' ';
            }
            mySize++;
            table[value%size] = value;
        }
        if(cvalue == 32){
            mySize++;
            table[value%size] = value;
        }
        else{
            table[value%size] = value;
        }
        /*else{
            if(table[value%size] == ' '){
                mySize++;
            }
            table[value%size] = value;
        }*/
    }
    //int position = value%mySize;
    /*if(table[value%mySize] == 0){
        mySize++;
    }*/
    else{
        if(cvalue == 0){
            mySize++;
            table[value%size] = value;
        }
        else{
            table[value%size] = value;
        }
    }
}



//Return true if this Map contains a node whose value is equal to the key
//Otherwise, return false
//NOTE - This operation should be O(1)
template <class T>
bool Map<T>::contains(T key){
    if(table[key%table.size()] == key){
        return true;
    }
    else{
        return false;
    }
}

//Return the index of the element <key> if it is in the Map
//If not in Map, return -1
template <class T>
int Map<T>::find(T key){
    if(contains(key)){
        return key%table.size();
    }
    else{
        return -1;
    }
}
