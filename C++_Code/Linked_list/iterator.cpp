/* 
 * CPSC 1071 - Lab 10
 *
 */

#include "iterator.h"

Iterator::Iterator(){
	list = 0;
	current = 0;
}

Iterator::Iterator(List* lis){
	list = lis;
	current = lis->getHead();
}

Iterator::~Iterator(){
	
}

void Iterator::advance(){
	if(hasNext()){
		current = current->getNext();
	}
}

bool Iterator::hasNext(){
	if(current == 0){
		return false;
	}
		return true;
}

Node* Iterator::get(){
	return current;
}
