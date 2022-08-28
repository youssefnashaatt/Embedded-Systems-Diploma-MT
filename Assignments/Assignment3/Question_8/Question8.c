/**************************************************************************************************
 Name        : Question8.c
 Author      : Youssef Nashaat
 Created on	 : Aug 23, 2022
 Description : Assignment 3 - Question 8
 **************************************************************************************************/
#include <stdio.h>


int geometric_nth_term(int *array, int index);

int main(void)
{
	int array1[] = {1, 3, 9, 27, 81, 243};


	printf("7th element of array1 is %d\n", geometric_nth_term(array1, 7));
	printf("10th element of array1 is %d\n", geometric_nth_term(array1, 10));

	return 0;
}


int geometric_nth_term(int *array, int index)
{
	float key;
	int result = array[0];

	key = array[1] / array[0];


	for(int i = 0 ; i < index - 1; i++)
	{
		result *= key;
	}

	return result;

}

