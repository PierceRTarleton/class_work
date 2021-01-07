/*Pierce Tarleton
CPSC 1070 Fall
Lab 4
The program reads in a file with fscanf and makes it into a 2-D array, and then prints it out.*/
// add header comment

#include <stdio.h>

#define numCols 4// #define for the number of columns

void convertInches(int rows, int array[][numCols]);
void printValues(int rows, int array[][numCols]);

int main(void) {
	int rows;
   	 // declare needed variables:
	scanf("%d", &rows);       // numRows for the number of rows
	int mesurements[rows][numCols];
        // array called measurements
    


   	convertInches(rows, mesurements);  // call convertInches() sending the appropriate arguments


   	printValues(rows, mesurements); // call printValues() sending the appropriate arguments

    
    return 0;
}


// reads next value from file into 1st element of row
// fills in the rest of the elemenst of that row
// after computing yards, feet, and inches
// parameters:  the number of rows, and the 2-D array
// returns:  none
void convertInches(int rows, int array[][numCols]) {
    int totalInches, i, col = 0;
    
    for (i = 0; i < rows; i++) {
	scanf("%d", &totalInches); // use scanf (or fsanf with stdin) to read in next value
       	array[i][col]=totalInches; // from file and put into the 1st element of the row
        

        // assign to totalInches that value that was just read into
        // that 1st element of the row
        


        array[i][col+1] = totalInches / 36;
        totalInches %= 36;
        array[i][col+2] = totalInches / 12;
        array[i][col+3] = totalInches % 12;
    }
    
}


// prints the contents of the 2-D array
// parameters:  the number of rows, and the 2-D array
// returns:     nothing
void printValues(int rows, int array[][numCols]) {
    int i;
    printf("\n%8s%8s%8s%8s\n\n", "total", "yards", "feet", "inches");
    
    for (i = 0; i < rows; i++) {
        printf("%8d  %6d  %6d  %6d \n", 
               array[i][0], array[i][1], array[i][2], array[i][3]);
    }
    printf("\n\n");
}
