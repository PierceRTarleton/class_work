/* CPSC 1071 - Lab 10  */

#ifndef LIST_H
#define LIST_H

#include "node.h"

class List {
public:
    List();
    ~List();

    void addFirst(void*);
    void reset();
    void* getCurItem();
    Node* getHead();

private:
    Node* head;
    Node* current;
};



#endif
