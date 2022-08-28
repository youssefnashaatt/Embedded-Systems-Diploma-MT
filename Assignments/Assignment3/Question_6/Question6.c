/**************************************************************************************************
 Name        : Question6.c
 Author      : Youssef Nashaat
 Created on	 : Aug 22, 2022
 Description : Assignment 3 - Question 6
 **************************************************************************************************/
#include <stdio.h>

#define FALSE 0
#define TRUE 1
#define SIZE 10

/*Function Declaration*/
int linear_search_lastindex(int *array, int size, int element);

int main(void)
{
	int array[SIZE] = {1, 3, 2, 4, 8, 10, 10, 13, 13, 13};

	for(int i = 0 ; i < SIZE ; i++)
	{
		printf("%d ", array[i]);
	}

	int last_index13 = linear_search_lastindex(array, SIZE, 13);
	int last_index10 = linear_search_lastindex(array, SIZE, 10);

	printf("\n\nThe first index of 13 is %d\n", last_index13);
	printf("The first index of 10 is %d", last_index10);

	return 0;
}


int linear_search_lastindex(int *array, int size, int element)
{
	int found = FALSE, index;

	for(int i = 0 ; i < size ; i++)
	{
		if(array[i] == element)
		{
			found = TRUE;
			index = i;
		}
	}

	if(found)
		return index;

	else
		return -1;
}


