/* CPSC 1071 - Lab 10 */

#ifndef ITERATOR_H
#define ITERATOR_H

#include "list.h"
#include "node.h"

class Iterator {
public:
    Iterator();
    Iterator(List*);
    ~Iterator();

    void advance();
    bool hasNext();
    Node* get();

private:
    List* list;
    Node* current;
};

#endif
