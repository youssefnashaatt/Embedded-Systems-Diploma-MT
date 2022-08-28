/**************************************************************************************************
 Name        : Question4.c
 Author      : Youssef Nashaat
 Created on	 : Aug 21, 2022
 Description : Assignment 3 - Question 4
 **************************************************************************************************/
#include <stdio.h>


void selection_sorting(int *array, int array_size);


int main(void)
{
	int array[11] = {9, 8, 7, 2, 4, 5, 7, 10, 3, 2, 1};

	//Display array before sorting
	for(int i = 0 ; i < 11 ; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");

	selection_sorting(array, 11);

	//Display array after sorting
	for(int i = 0 ; i < 11 ; i++)
	{
		printf("%d ", array[i]);
	}

	return 0;
}


void selection_sorting(int *array, int array_size)
{
	for(int i = 0 ; i < array_size ; i++)
	{
		int *minptr = (array + i);

		for(int j = i + 1 ; j < array_size ; j++)
		{
			if(*minptr > array[j])
			{
				minptr = (array + j);
			}
		}

		//Switch between minimum and index i
		int temp = array[i];
		array[i] = *minptr;
		*minptr = temp;
	}
}

