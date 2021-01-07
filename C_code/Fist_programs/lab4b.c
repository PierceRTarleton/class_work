/*Pierce Tarleton
CPSC 1070 Fall
Lab 4
The program reads in a file with fscanf and makes it into a 2-D array, and then prints it out.*/
// add header comment

#include <stdio.h>

#define numCols 4// #define for the number of columns

void convertInches(int totalInches, int * yards, int *feet, int * inches);
void printValues(int rows, int array[][numCols]);

int main(void) {
	int rows;
	int tinch;
	int size;
	int f=1;
   	FILE * prtin(input.txt, r); // declare needed variables:
	fscanf(prtin,"%d", &rows);// numRows for the number of rows
	size=rows*4;
	int * mesurments= malloc(size * sizeof(int));
	while (!feof(FILE * prtin))
	{
		fscanf(prtin,"%d", tinch);
		for(int i=0;i<4;i++)
		{
			convertInches(tinch, mesurments+f, mesurments+(f+1), mesurments+(f+2));  // call convertInches() sending the appropriate arguments
		}
		f=f+4
		*(mesurments-5)=tinch;
	}

   	printValues(rows, mesurements); // call printValues() sending the appropriate arguments

    
    return 0;
}


// reads next value from file into 1st element of row
// fills in the rest of the elemenst of that row
// after computing yards, feet, and inches
// parameters:  the number of rows, and the 2-D array
// returns:  none
void convertInches(int totalInches, int * yards, int * feet, int * inches) {
    
 	 // use scanf (or fsanf with stdin) to read in next value
         // from file and put into the 1st element of the row
        

        // assign to totalInches that value that was just read into
        // that 1st element of the row
        


        *yards = totalInches / 36;
        totalInches %= 36;
        *feet = totalInches / 12;
        *inches = totalInches % 12;
}


// prints the contents of the 2-D array
// parameters:  the number of rows, and the 2-D array
// returns:     nothing
void printValues(int rows, int theArray) {
    int i;
    printf("\n%8s%8s%8s%8s\n\n", "total", "yards", "feet", "inches");
    for (i = 1; i < rows*4; i=i+4) {
        printf("%8d  %6d  %6d  %6d \n", 
              theArray, theArray+i, theArray+(i+1), theArray+(i+2));
    }
    printf("\n\n");
}
