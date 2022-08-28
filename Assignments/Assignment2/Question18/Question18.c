/**************************************************************************************************
 Name        : Question18.c
 Author      : Youssef Nashaat
 Created on	 : Aug 19, 2022
 Description : Assignment 2 - Question 18
 **************************************************************************************************/
#include <stdio.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

int exponents(int integer);

int main(void)
{
	int integer;

	do
	{
		printf("Please enter a positive number:");
		fflush(stdout);
		scanf("%d", &integer);
	}

	while(integer < 0);

	if(exponents(integer) == TRUE);

	else
		printf("%d can't be expressed in the form of exponents", integer);

	return 0;
}



int exponents(int integer)
{
	int index = 1, count = 0;
	for(int i = 0 ; i <= integer ; i++)  /*To get base*/
	{
		for(int j = 0 ; j <= integer ; j++) /*To get power*/
		{
			if(pow(i, j) == integer)
			{
				if(count == 0)
					printf("%d in the exponent form:\n", integer);

				printf("%d) %d ^ %d = %d\n", index, i, j, integer);
				index++;
				count++;
			}
		}
	}

	if(count > 0)
		return TRUE;

	else
		return FALSE;
}
