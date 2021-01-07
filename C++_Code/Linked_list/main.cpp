/* CPSC 1071 - Lab 10
 * driver
 */

#include <iostream>
#include <string>


#include "iterator.h"

int main()
{
    char* stars[] = {const_cast<char *>("****"), 
                     const_cast<char *>("***"), 
                     const_cast<char *>("**"), 
                     const_cast<char *>("*")}; 
    int nums[] = {8, 7, 6, 5, 4, 3, 2, 1};

    List list1;

    for(int i = 0; i < 4; i++) {
        list1.addFirst(stars[i]);
    }

    Iterator itr(&list1);

    while(itr.hasNext()) {
        std::cout << ((char*)itr.get()->getItem())
                  << std::endl;
        itr.advance();
    }

    List* list2 = new List();
    for(int i = 0; i < 8; i++) {
        list2->addFirst(&nums[i]);
    }

    Iterator* itr2 = new Iterator(list2);

    while(itr2->hasNext()) {
        std::cout << *((int*)itr2->get()->getItem())
                  << std::endl;
        itr2->advance();
    }

    delete itr2;
    delete list2;

    return 0;
}
