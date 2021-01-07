/** list.h -- lab 7 **/

#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/** List node  **/
typedef struct node_type
{
   struct node_type *next;           /* Pointer to next node               */   
   void *dataPtr;                     /* Pointer to associated data       */
} node_t;

/** List structure **/
typedef struct list_type
{
   node_t *head;                     /* Pointer to front of list           */
} list_t;

/** Iterator **/
typedef struct list_iterator
{
   list_t *list;                     /* List iterator is associated with  */
   node_t *position;                 /* Current position in list          */
} iterator_t;

/** Function prototypes **/
list_t *newList();                   /* Create and initialize list object */
void   list_add(list_t *list, void *objPtr); /* Insert object into list  */

iterator_t *newIterator(list_t *list);
void   list_reset(iterator_t *iter);    /* Reset current to front of list    */
void   *list_next(iterator_t *iter);    /* Get object from list              */
int    list_hasnext(iterator_t *iter);  /* Test if at end of list            */

#endif

