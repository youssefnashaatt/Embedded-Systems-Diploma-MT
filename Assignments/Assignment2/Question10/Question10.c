/**************************************************************************************************
 Name        : Question10.c
 Author      : Youssef Nashaat
 Created on	 : Aug 13, 2022
 Description : Assignment 2 - Question 10
 **************************************************************************************************/
#include <stdio.h>


int counting_holes(int integer);

int main(void)
{
	int integer, holes_count;

	printf("Please enter an integer: ");
	fflush(stdout);
	scanf("%d", &integer);

	holes_count = counting_holes(integer);

	printf("The count of holes is %d", holes_count);

	return 0;
}


int counting_holes(int integer)
{
	int count = 0;
	int remainder;
	int one_hole[] = {0, 4, 6, 9};
	int two_holes = 8;

	while (integer != 0)
	{
		remainder = integer % 10;

		for (int i = 0 ; i < 4 ; i++)
		{
			if (one_hole[i] == remainder)
			{
				count++;
				break;
			}
		}

		if (two_holes == remainder)
			count += 2;

		integer /= 10;

	}

	return count;
}
