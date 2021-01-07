/*Pierce Tarleton
lab 1071 Fall 2018
the program prints the binary of the number entered
and creates a box with a width of the number in the 10's place and a hight of the number in the 1's place whith a charachter that has been specified*/
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	int c=0;
	int a [15]={0};
	int t=1;
	int r=0;
	int tempw;
	int temph;
	char e='*';
		while(argc!=2)//checks if the user entered an argument, and if they did not it ends the program
		{
			printf("To run the program, provide a 2 diget number.\n"); 
			exit(1);
		}
		int x=atoi(argv[1]);//sets x equal to the argument
		while(t==1)//allows the user to input numbers as many times as they wont to befor exeting the program
		{
			while(x>=100 || x<=9)//check if x is a 2 diget number
			{
				printf("Enter a 2 diget number:");
				scanf("%d", &x);//sets x equal to the number entered
			}
			printf("Enter a character to make the box with:");
			scanf(" %c", &e);//sets e equal to the character entered
			tempw=x/10;
			temph=x%10;
			r=x;
			while(x>0)//finds the remander and puts it into the array
			{
				a[c]=x%2;
				c++;
				x=x/2;
			}
			printf("The binary equivalant of %d is ", r);
			for(int i=c;i>0;i--)//prints the remainders that were put in the array in revers to get the binary for the inputed number
			{
				printf("%d", a[i-1]);
			}
			printf("\n");
			for(int y=0;y<temph;y++)//runs through all of the positions in a column
			{
					for(int o=0;o<tempw;o++)//runs through all of the positions in a row
					{
						if(y==0 || y==temph-1)//checks if the position being prited is the first of last position in the columns
						{
							printf("%c", e);//prints the specifed character
						}
						else if(o==0 || o==tempw-1)//checks if the position being prited is the first or last position in the row
						{
								printf("%c", e);//prints the specified character
						}
						else
						{
							printf(" ");
						}	
					}
				printf("\n");
			}	
			printf("Would you like to go again? (1 for yes, 0 for no)");
			scanf("%d", &t);//gets input from the user on whether they would like to continue converting numbers
			c=0;//makes it so that all of the previous numbers in the array are over writen
			while(t!=1 && t!=0)// checks to make sure the user has entered eather 1 for yes or 0 for no, and if not asks them to do so agian
			{
				printf("Would you like to go again? (1 for yes, 0 for no)");
				scanf("%d", &t);
			}
		}
	printf("\n");
	return 0;
}
