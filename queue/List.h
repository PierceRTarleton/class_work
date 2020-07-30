/*
 * Name:Pierce Tarleton
 * Date Submitted: 1/24/2019
 * Lab Section: 4
 * Assignment Name:Lab 2 Linked list
 */

#pragma once

#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

//This class represents a linked list of node objects
//Do not modify anything in the class interface
template <class T>
class List{

 private:
  Node<T> * start; //pointer to the first node in this list
  Node<T> * end;   //pointer to the last node in this list
  int mySize;  //size (or length) of this list

 public:
  List();
  ~List();
  int size();
  bool empty();
  void insert(T);
  void insertAfter(T, T);
  void insertAt(T, int);
  void priorityInsert(T, double);
  void remove(T);
  void removeAll(T);
  T getFirst();
  bool contains(T);

  //Print the name and this list's size and values to stdout
  //This function is already implemented (no need to change it)
  void print(string name){
    cout << name << ": ";
    cout << "size = " << size();
    cout << ", values = ";
    Node<T> * iterator = start;
    while(iterator != NULL){
      cout << iterator->value << ' ';
      iterator = iterator->next;
    }
    cout << endl;
  }

  void returnFirstNode(Node<T> * iterator){
    iterator = start;
  }

}; //end of class interface (you may modify the code below)

//Implement all of the functions below
//Construct an empty list by initializig this list's instance variables
template <class T>
List<T>::List(){
    mySize = 0;
    start = NULL;
    end = NULL;
}

//Destroy all nodes in this list to prevent memory leaks
template <class T>
List<T>::~List(){
    Node<T> * temp = start;
    Node<T> * iterator = start;
    while(iterator !=NULL){
        iterator = iterator->next;
        delete temp;
        temp = iterator;
    }
}

//Return the size of this list
template <class T>
int List<T>::size(){
    mySize = 0;
    Node<T> * iterator = start;
    while(iterator != NULL){
        iterator = iterator->next;
        mySize++;
    }
    return mySize;
}

//Return true if this list is empty
//Otherwise, return false
template <class T>
bool List<T>::empty(){
    if(start == NULL && end == NULL){
        return true;
    }
    else{
        return false;
    }
}

//Create a new node with value, and insert that new node
//into this list
template <class T>
void List<T>::insert(T value){
    Node<T> * temp = new Node<T> (value);
    temp->next = NULL;
    if(empty()){
        start = temp;
        end = temp;
    }
    else{
        Node<T> * iterator = start;
        while(iterator != NULL){
            if(iterator->next == NULL){
                iterator->next = temp;
                iterator->next->next = NULL;
            }
            end = temp;
            iterator = iterator->next;
        }
    }
}

//Create a new node with value <value>, and insert after the first instance of
//a node with value <target>
template <class T>
void List<T>::insertAfter(T value, T target){
    Node<T> * newNode = new Node<T>(value);
    Node<T> * iterator = start;
    Node<T> * temp = start->next;
    while (iterator != NULL){
        if(iterator->value == target){
            temp = iterator->next;
            newNode->next = temp;
            iterator->next = newNode;
        }
        iterator= iterator->next;
    }
}

//Create a new node with value <value>, and insert that new node at position j
template <class T>
void List<T>::insertAt(T value, int j){
    Node<T> * newNode = new Node<T>(value);
    Node<T> * iterator = start;
    Node<T> * temp = start;
    int position = 0;
    if(j == 0){
        start = newNode;
        start->next = temp;
    }
    while(iterator != NULL){
        if(position == (j-1)){
            cout<<j-1<<endl;
            temp = iterator->next;
            newNode->next = temp;
            iterator->next = newNode;
        }
        iterator = iterator->next;
        position++;
    }
}

//Insert into Linked List such that the list is ordered by priority
//(higher priority at beginning of list).  Should insert after all
//nodes with same priority.
template <class T>
void List<T>::priorityInsert(T value, double insertPriority){
    Node<T> * newNode = new Node<T>(value, insertPriority);
    Node<T> * iterator = start;
    Node<T> * temp = start;
    if(empty()){
        start = newNode;
        end = newNode;
    }
    else{
        while(iterator != NULL){
            if(start->priority < insertPriority){
                start = newNode;
                start->next = temp;
                iterator = NULL;
            }
            else if(iterator->next->priority < insertPriority){
                temp = iterator->next;
                newNode->next = temp;
                iterator->next = newNode;
                iterator = NULL;
            }
            else if(iterator->next->next == NULL){
                    iterator->next->next = newNode;
                    iterator = NULL;
                    end = newNode;
            }
            else{
                iterator = iterator->next;
            }
        }
    }
}


//Remove first node whose value matches target value.
//Make no other changes to list
template <class T>
void List<T>::remove(T target){
    Node<T> * iterator = start;
    Node<T> * temp = iterator;
    if(!empty()){
        if(start->value == target){
            iterator = start->next;
            temp = start;
            delete temp;
            start = iterator;
        }
        else{
            while(iterator != NULL){
                if(iterator->next->value == target){
                    temp = iterator->next;
                    iterator->next = temp->next;
                    delete temp;
                    iterator = NULL;
                }
                else
                    iterator = iterator->next;
            }
        }
    }
}

//Remove all nodes whose value is equal to target value.
//Do not change order of list (other than removing nodes)
template <class T>
void List<T>::removeAll(T target){
    Node<T> * iterator = start;
    Node<T> * temp = iterator;
    while(iterator != NULL){
        if(iterator->next->next == NULL && iterator->next->value == target){
            temp = iterator->next;
            iterator->next = NULL;
            end = iterator;
            cout<<iterator->value<<endl;
            iterator = iterator->next;
            delete temp;
        }
        else if(iterator->next->value == target){
            cout<<iterator->value<<endl;
            temp = iterator->next;
            iterator->next = temp->next;
            delete temp;
        }
        else{
            iterator = iterator->next;
        }
    }
}


//Return the value of the first node in the Linked List, and remove that node
//If no first node, return false
template <class T>
T List<T>::getFirst(){
    Node<T> * temp = start;
    int value;
    if(start == NULL)
        return false;
    else{
        value = start->value;
        temp = start;
        start = start->next;
        delete temp;
        return value;
    }
}


//Return true if this list contains a node whose value is equal to the key
//Otherwise, return false
template <class T>
bool List<T>::contains(T key){
    Node<T> * iterator = start;
    while(iterator != NULL){
        if(iterator->value == key){
            return true;
        }
        iterator = iterator->next;
    }
    return false;
}
