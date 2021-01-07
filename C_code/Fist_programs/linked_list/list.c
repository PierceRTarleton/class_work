/* List functions -- lab 7b*/
/* Pierce Tarleton
	CPSC 1071 Fall 2018
	Lab # 7b*/


#include "list.h"


/** newList -- create a new list object **/
list_t *newList() {
    /** STUBBED **/
	 list_t * list = (list_t *)malloc(sizeof(list_t));
	 list->head = NULL;
    return list;
}


/** list_add -- add an object to the linked list **/
void list_add(list_t *list, void *objPtr) {
   if(list->head == NULL){
		list->head = (node_t *)malloc(sizeof(node_t));
		list->head->dataPtr = objPtr;
		list->head->next = NULL;
	}
	node_t * temp = list->head;
	while(temp->next != NULL)
		temp = temp->next;
	/** STUBBED **/
	temp->next = (node_t *)malloc(sizeof(node_t));
	temp->next->dataPtr = objPtr;
	temp->next->next = NULL;
}

/* newIterator -- creates a new iterator */
iterator_t * newIterator(list_t * list){
	iterator_t * newIter = (iterator_t *)malloc(sizeof(iterator_t *));
	newIter->list = list;
	newIter->position = list->head;
	return newIter;
}

/* list_reset -- resetst the position pointer to the beinig of the list */
void list_reset(iterator_t * iterator){
	iterator->position = iterator->list->head->next;
}

/* list_next -- givest the value in the node the position pointer is pointing to */
void *list_next(iterator_t * iterator){
	void * ptr;
		ptr = iterator->position->dataPtr;
		iterator->position = iterator->position->next;
	return ptr;
}

/* l_hasnext -- checks if the if there is a pointer after this one */
int list_hasnext(iterator_t * iterator){
	if(iterator->position == NULL)
		return 0;
	else
		return 1;
}
