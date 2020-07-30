/*
 * Name:Pierce Tarleton
 * Date Submitted:1/30/2019
 * Lab Section: 4
 * Assignment Name: lab 2 stack
 */

#pragma once

#include <iostream>
#include <string>
#include "List.h"
using namespace std;

//This class represents a Stack implemented via Linked List
//Do not modify anything in the class interface
template <class T>
class ListStack{

 private:
  List<T> stack;

 public:
  ListStack();
  ~ListStack();
  int size();
  bool empty();
  void push(T);
  T pop();
  void print(string name);

}; //end of class interface (you may modify the code below)

//Implement all of the functions below


//Construct an empty ListStack by initializig this ListStack's instance variables
template <class T>
ListStack<T>::ListStack(){
    List<T> stack;
}

//Destroy all nodes in this ListStack to prevent memory leaks
template <class T>
ListStack<T>::~ListStack(){
}

template<class T>
void ListStack<T>::print(string name){
    stack.print(name);
}

//Return the size of this ListStack
template <class T>
int ListStack<T>::size(){
    return stack.size();
}

//Return true if this ListStack is empty
//Otherwise, return false
template <class T>
bool ListStack<T>::empty(){
    return stack.empty();
}

//Create a node with value <value> and push it onto the stack
template <class T>
void ListStack<T>::push(T value){
    stack.insertAt(value, 0);
}

//Pop a node from the Stack.
//Note that here that includes both removing the node from the stack
//AND returning its value.
template <class T>
T ListStack<T>::pop(){
    return stack.getFirst();
}
