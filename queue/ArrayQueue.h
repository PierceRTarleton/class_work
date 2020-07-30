/*
 * Name: Piece Tarelton
 * Date Submitted:1/30/2019
 * Lab Section: 4
 * Assignment Name:Lab_2_Queue
 */

#pragma once

#include <iostream>
#include <string>
#include <deque>
using namespace std;

//This class represents an Queue based on an Array (deque)
//Do not modify anything in the class interface
template <class T>
class ArrayQueue{

 private:
  deque<T> queue;

 public:
  ArrayQueue();
  ~ArrayQueue();
  int size();
  bool empty();
  void enqueue(T);
  T dequeue();
  //Print the name and this ArrayQueue's size and values to stdout
  //This function is already implemented (no need to change it)
  void print(string name){
    cout << name << ": ";
    cout << "size = " << queue.size();
    cout << ", values = ";
    for (auto i : queue){
      cout << i << " ";
    }
    cout << endl;
  }

}; //end of class interface (you may modify the code below)

//Implement all of the functions below

//Construct an empty ArrayQueue by initializig this ArrayQueue's instance variables
template <class T>
ArrayQueue<T>::ArrayQueue(){
    deque<T> queue;
}

//Destroy all nodes in this ArrayQueue to prevent memory leaks
template <class T>
ArrayQueue<T>::~ArrayQueue(){
}

//Return the size of this ArrayQueue
template <class T>
int ArrayQueue<T>::size(){
    return queue.size();
}

//Return true if this ArrayQueue is empty
//Otherwise, return false
template <class T>
bool ArrayQueue<T>::empty(){
    return queue.empty();
}

//Enqueue <value> into the queue
template <class T>
void ArrayQueue<T>::enqueue(T value){
    queue.push_back(value);
}

//Dequeue an element
//Here, this means both remove the item AND return its value
template <class T>
T ArrayQueue<T>::dequeue(){
    T temp = queue.front();
    queue.pop_front();
    return temp;
}
