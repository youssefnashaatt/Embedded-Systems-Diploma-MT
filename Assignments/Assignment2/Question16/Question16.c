/**************************************************************************************************
 Name        : Question16.c
 Author      : Youssef Nashaat
 Created on	 : Aug 19, 2022
 Description : Assignment 2 - Question 16
 **************************************************************************************************/
#include <stdio.h>


int counting_ones(unsigned char x)
{
	unsigned char mask = 0x80;
	int count = 0;

	for (int i = 0; i < 8; i++)
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
	printf("Number of ones in 0x45 is %d\n", counting_ones(0x45));
	printf("Number of ones in 0x82 is %d\n", counting_ones(0x82));
	printf("Number of ones in 0xFF is %d\n", counting_ones(0xFF));
}




