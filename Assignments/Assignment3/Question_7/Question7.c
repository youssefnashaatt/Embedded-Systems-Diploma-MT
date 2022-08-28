/**************************************************************************************************
 Name        : Question7.c
 Author      : Youssef Nashaat
 Created on	 : Aug 22, 2022
 Description : Assignment 3 - Question 7
 **************************************************************************************************/
#include <stdio.h>

#define TRUE 1
#define FALSE 0

int arithmetic_nth_term(int *array, int index);

int main(void)
{
	int array1[] = {1, 3, 5, 7, 9, 11};


	printf("7th element of array1 is %d\n", arithmetic_nth_term(array1, 7));
	printf("100th element of array1 is %d\n", arithmetic_nth_term(array1, 100));

	return 0;
}


int arithmetic_nth_term(int *array, int index)
{
	int key;
	int result = array[0];

	key = array[1] - array[0];


	for(int i = 0 ; i < index - 1; i++)
	{
		result = result + key;
	}

	return result;

}

