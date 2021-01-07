/*Pierce Tarleton
CpSc 107 Lab, Fall 2018*/

/* This program is supposed to read in a collection */
/* of pairs of integers, print each pair and then   */
/* print their average.                             */

/* Note: it is full of syntax errors                */
#include <stdio.h>
int  main(int argc, char *argv[])
{
    int x, y;
    float avg;

    while (scanf("%d %d", &x , &y) == 2)// added double = to test for that it has 2 variables, and added &
    {
       printf("x = %d and y =%d \n", x, y);//added a Quatation 
       avg = ((float)x + (float)y)/2.0;
       printf("average is %f \n", avg);//added f to printf; and changed %d to %f
    }
	return 0;

}
