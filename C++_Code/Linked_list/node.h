/* CPSC 1071 - Lab 10 */

#ifndef NODE_H
#define NODE_H

class Node {
public:
    Node();
    Node(void*);
    ~Node();

    Node* getNext();
    void* getItem();
    void setNext(Node*);

private:
    void* item;
    Node* next;
};

#endif
