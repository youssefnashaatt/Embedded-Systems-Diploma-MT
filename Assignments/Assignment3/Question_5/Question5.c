/**************************************************************************************************
 Name        : Question5.c
 Author      : Youssef Nashaat
 Created on	 : Aug 22, 2022
 Description : Assignment 3 - Question 5
 **************************************************************************************************/
#include <stdio.h>

#define SIZE 10

/*Function Declaration*/
int linear_search_firstindex(int *array, int size, int element);

int main(void)
{
	int array[SIZE] = {1, 3, 2, 4, 8, 10, 10, 13, 13, 13};

	for(int i = 0 ; i < SIZE ; i++)
	{
		printf("%d ", array[i]);
	}

	int first_index13 = linear_search_firstindex(array, SIZE, 13);
	int first_index10 = linear_search_firstindex(array, SIZE, 10);

	printf("\n\nThe first index of 13 is %d\n", first_index13);
	printf("The first index of 10 is %d", first_index10);

	return 0;
}



int linear_search_firstindex(int *array, int size, int element)
{
	for(int i = 0 ; i < size ; i++)
	{
		if(array[i] == element)
		{
			return i;
		}
	}

	return -1;
}

