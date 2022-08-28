/**************************************************************************************************
 Name        : Question15.c
 Author      : Youssef Nashaat
 Created on	 : Aug 19, 2022
 Description : Assignment 2 - Question 15
 **************************************************************************************************/
#include <stdio.h>


int counting_ones(int x)
{
	int mask = 0x80000000;
	int count = 0;

	for (int i = 0; i < 32; i++)
	{
		if((x & mask) != 0)
		{
			count++;
		}

		x <<= 1;
	}

	return count;
}


int main(void)
{
	printf("Number of ones in 0x45FEA900 is %d\n", counting_ones(0x45FEA900));
	printf("Number of ones in 0x82 is %d\n", counting_ones(0x82));

	return 0;
}



