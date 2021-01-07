/**
Pierce Tarleton
Lab 1071 Fall 2018
Lab #5

The program dinamacly alocated 100 slots of memory whith p pointing to it. Then the pointer was changed to point to the begining of the string "Constantinople" which removes access to the malloced memory creating a leak, so if you create anchar array of Constantinople than copy that into the malloced space with the strcpy(p, array); than the string will be in the malloced memory which you free up after the print statment.   
    leak.c  -  memory leak example

    This program will reserve a block of memory large enough
    to hold 100 characters.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    char array[]="Constantinople";
    char *p = malloc(sizeof(char) * 100);
    strcpy(p,array);
    //p= "Constantinople";
    printf("%s", p);
    free(p);
    return 0;
}

