/*
 * Name:Pierce Tarleton
 * Date Submitted:1/30/2019
 * Lab Section:4
 * Assignment Name:Lab 2 Priority Queue
 */

#pragma once

#include <iostream>
#include <string>
#include <deque>
using namespace std;

template<class T>
struct Entry
{
          T value;
          double priority;
};

//This class represents a Priority Queue based on an array (deque)
//Do not modify anything in the class interface
template <class T>
class ArrayPriorityQueue{

 private:
  deque<Entry<T>> queue;

 public:
  ArrayPriorityQueue();
  ~ArrayPriorityQueue();
  int size();
  bool empty();
  void enqueue(T, double insertPriority = 0);
  T dequeue();
  //Print the name and this ArrayPriorityQueue's size and values to stdout
  //This function is already implemented (no need to change it)
  void print(string name){
    cout << name << ": ";
    cout << "size = " << queue.size();
    cout << ", values = ";
    for (auto i : queue){
      cout << i.value << " ";
    }
    cout << endl;
  }

}; //end of class interface (you may modify the code below)

//Implement all of the functions below

//Construct an empty ArrayPriorityQueue by initializig this ArrayPriorityQueue's instance variables
template <class T>
ArrayPriorityQueue<T>::ArrayPriorityQueue(){
    deque<Entry<T>> queue;
}

//Destroy all nodes in this ArrayPriorityQueue to prevent memory leaks
template <class T>
ArrayPriorityQueue<T>::~ArrayPriorityQueue(){
}

//Return the size of this ArrayPriorityQueue
template <class T>
int ArrayPriorityQueue<T>::size(){
    return queue.size();
}

//Return true if this ArrayPriorityQueue is empty
//Otherwise, return false
template <class T>
bool ArrayPriorityQueue<T>::empty(){
    return queue.empty();
}

//Enqueue a value <value> with priority <insertPriority>.
//Larger values for priority at front
template <class T>
void ArrayPriorityQueue<T>::enqueue(T value, double insertPriority){
    Entry<T> temp;
    temp.value = value;
    int position = 0;
    int endplace = 1;
    temp.priority = insertPriority;
    if(empty()){
        queue.push_back(temp);
    }
    else{
        for(auto i : queue){
            if(i.priority < insertPriority){
                queue.emplace(queue.begin()+position, temp);
                endplace = 0;
                break;
            }
            position++;
        }
        if(endplace == 1){
            queue.push_back(temp);
        }
    }
}

//Dequeue an element.
//Here this means both remove it from the deque AND return the value
template <class T>
T ArrayPriorityQueue<T>::dequeue(){
    if(!empty()){
        Entry<T> temp = queue.front();
        queue.pop_front();
        return temp.value;
    }
    return false;
}
