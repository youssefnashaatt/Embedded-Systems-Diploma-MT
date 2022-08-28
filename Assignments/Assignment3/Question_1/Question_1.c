/**************************************************************************************************
 Name        : Question_1.c
 Author      : Youssef Nashaat
 Created on	 : Aug 20, 2022
 Description : Assignment 3 - Question 1
 **************************************************************************************************/
#include <stdio.h>

/*Function Declaration*/
int summation(int numbers_size, int* numbers);

int main(void)
{
	int numbers[8] = {1, 2, 3, 4, 5, 6, 7, 8};

	printf("The sum of the array = %d\n", summation(8, numbers));

	return 0;
}

int summation(int numbers_size, int* numbers)
{
	int sum = 0;

	for(int i = 0 ; i < numbers_size ; i++)
	{
		sum += *(numbers + i);
	}

	return sum;
}
