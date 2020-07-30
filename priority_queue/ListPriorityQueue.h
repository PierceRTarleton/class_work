/*
 * Name:Pierce Tarleton
 * Date Submitted:1/30/2019
 * Lab Section:4
 * Assignment Name: Lab 2 Priority Queue
 */

#pragma once

#include <iostream>
#include <string>
#include "List.h"

using namespace std;

//This class represents a Priority Queue based on a Linked List.
//Do not modify anything in the class interface
template <class T>
class ListPriorityQueue{

 private:
  List<T> queue;

 public:
  ListPriorityQueue();
  ~ListPriorityQueue();
  int size();
  bool empty();
  void enqueue(T, double insertPriority = 0);
  T dequeue();

  //Print the name and this ListPriorityQueue's size and values to stdout
  //This function is already implemented (no need to change it)
  void print(string name){
    queue.print(name);
  }

}; //end of class interface (you may modify the code below)

//Implement all of the functions below

//Construct an empty ListPriorityQueue by initializig this ListPriorityQueue's instance variables
template <class T>
ListPriorityQueue<T>::ListPriorityQueue(){
    List<T> queue;
}

//Destroy all nodes in this ListPriorityQueue to prevent memory leaks
template <class T>
ListPriorityQueue<T>::~ListPriorityQueue(){
}

//Return the size of this ListPriorityQueue
template <class T>
int ListPriorityQueue<T>::size(){
    return queue.size();
}

//Return true if this ListPriorityQueue is empty
//Otherwise, return false
template <class T>
bool ListPriorityQueue<T>::empty(){
    return queue.empty();
}

//Create a new node with value, and insert that new node
//into this ListPriorityQueue in its correct position
template <class T>
void ListPriorityQueue<T>::enqueue(T value, double priorityOfInput){
    queue.priorityInsert(value, priorityOfInput);
}

//Dequeue an element from this ListPriorityQueue
// Note that here that means both removing the element from the queue
//AND returning the value
template <class T>
T ListPriorityQueue<T>::dequeue(){
    return queue.getFirst();
}
