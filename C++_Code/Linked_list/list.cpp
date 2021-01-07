/*
 * CPSC 1071 - Lab 10
 *
 * Name:Pierce Tarleton
 * Date:10/29/2018
 * File: list.cpp
 * Description
 */
#include "list.h"
#include "node.h"
#include <iostream>
#include <cstring>

/*
 * Default List constructor.
 * Hint: set member variables to NULL.
 */
List::List(){
	head = NULL;
	current = NULL;
}

/*
 * Destructor for the List.
 * This has already been implemented.
 */
List::~List()
{
    if(head != NULL) {
        Node* cur = head;
        while(cur != NULL) {
            std::cout << "removing list item" << std::endl;
            Node* tmp = cur->getNext();
            delete cur;
            cur = tmp;
        }
    }
}

/*
 * Add a new Node to the head of the list.
 * Hint: same concept as the C version.
 */
void List::addFirst(void* obj)
{
	Node* temp = head;
	Node newNode(obj);
	head = &newNode;
	newNode.setNext(temp);

}

/*
 * Resets the current to the head.
 * Hint: same concept as the C version.
 */
void List::reset()
{
	current = head;
}

/*
 * Retruns the current Node's data.
 */
void* List::getCurItem()
{
    return current;
}

/*
 * Returns the head.
 */
Node* List::getHead()
{
    return head;
}
