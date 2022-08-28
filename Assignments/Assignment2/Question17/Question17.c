/**************************************************************************************************
 Name        : Question17.c
 Author      : Youssef Nashaat
 Created on	 : Aug 19, 2022
 Description : Assignment 2 - Question 17
 **************************************************************************************************/
#include <stdio.h>

//Global Variables
int max = 0, max_i, max_j;

//Function Declaration
void max_of_xor(int num1, int num2);


int main(void)
{
	int num1, num2;

	do
	{
		printf("Please enter two positive numbers:\n");
		fflush(stdout);
		scanf("%d %d", &num1, &num2);
	}

	while((num1 < 0) && (num2 < 0));

	max_of_xor(num1, num2);
	printf("\nMaximum of XOR\n");
	printf("%d ^ %d = %d", max_i, max_j, max);

	return 0;
}

void max_of_xor(int num1, int num2)
{
	for(int i = num1 ; i <= num2 ; i++)
	{
		for(int j = i ; j <= num2 ; j++)
		{
			printf("%d XOR %d = %d\n", i, j, i ^ j);

			if((i ^ j) > *(&max))
			{
				*(&max_i) = i;
				*(&max_j) = j;
				*(&max) = i ^ j;
			}

		}
	}
}
