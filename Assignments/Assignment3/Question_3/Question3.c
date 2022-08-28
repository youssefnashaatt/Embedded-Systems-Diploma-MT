/**************************************************************************************************
 Name        : Question3.c
 Author      : Youssef Nashaat
 Created on	 : Aug 21, 2022
 Description : Assignment 3 - Question 3
 **************************************************************************************************/
#include <stdio.h>

//Function Declaration
void bubble_sorting(int *array, int array_size);


int main(void)
{
	int array[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

	//Display array before sorting
	for(int i = 0 ; i < 9 ; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");

	bubble_sorting(array, 9);

	//Display array after sorting
	for(int i = 0 ; i < 9 ; i++)
	{
		printf("%d ", array[i]);
	}

	return 0;
}


void bubble_sorting(int *array, int array_size)
{
	for(int i = 0 ; i < array_size - 1 ; i++)
	{
		for(int j = 0 ; j < array_size - 1 ; j++)
		{
			if(array[j] > array[j + 1])
			{
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

