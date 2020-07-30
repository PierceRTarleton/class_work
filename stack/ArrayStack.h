/*
 * Name:Pierce Tarleton
 * Date Submitted:1/30/2019
 * Lab Section: 4
 * Assignment Name: lab 2 stack
 */

#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//This class represents a Stack implemented via Array (vector)
//Do not modify anything in the class interface
template <class T>
class ArrayStack{

 private:
  vector<T> stack;   //pointer to the last node in this ArrayStack

 public:
  ArrayStack();
  ~ArrayStack();
  int size();
  bool empty();
  void push(T);
  T pop();
  void print(string name);

}; //end of class interface (you may modify the code below)

//Implement all of the functions below


//Construct an empty ArrayStack by initializig this ArrayStack's instance variables
template <class T>
ArrayStack<T>::ArrayStack(){
    vector<T> stack;
}

//Destroy all nodes in this ArrayStack to prevent memory leaks
template <class T>
ArrayStack<T>::~ArrayStack(){
    stack.clear();
}

template<class T>
void ArrayStack<T>::print(string name){
    cout << name << ": ";
    cout << "size = " << stack.size();
    cout << ", values = ";
    for(int i = 0; i<stack.size(); i++){
        cout<<stack[i]<<" ";
    }
    cout<<endl;
}

//Return the size of this ArrayStack
template <class T>
int ArrayStack<T>::size(){
    return stack.size();
}

//Return true if this ArrayStack is empty
//Otherwise, return false
template <class T>
bool ArrayStack<T>::empty(){
    return stack.empty();
}

//Push <value> onto the Stack
template <class T>
void ArrayStack<T>::push(T value){
    stack.push_back(value);
}

//Pop an element off the Stack
//Here, this means both removing the element and returning the value.
template <class T>
T ArrayStack<T>::pop(){
    T temp;
    if(!empty()){
        temp = stack.back();
        stack.pop_back();
        return temp;
    }
    return false;
}
