/**************************************************************************************************
 Name        : Question17.c
 Author      : Youssef Nashaat
 Created on	 : Aug 24, 2022
 Description : Assignment 3 - Question 17
 **************************************************************************************************/
#include <stdio.h>

int * Swap (int a_size,int *a,int b_size,int *b);

int main(void)
{
	int array1[5] = {1, 2, 3, 4, 5};
	int array2[5] = {6, 7, 8, 9, 10};

	printf("Array 1 before swap\n\n");
	for(int i = 0 ; i < 5 ; i++)
	{
		printf("array1[%d] = %d\n", i, array1[i]);
	}

	printf("\n");

	printf("Array 2 before swap\n\n");
	for(int i = 0 ; i < 5 ; i++)
	{
		printf("array1[%d] = %d\n", i, array2[i]);
	}

	printf("\n");

	Swap(5, array1, 5, array2);

	printf("Array 1 after swap\n\n");
	for(int i = 0 ; i < 5 ; i++)
	{
		printf("array1[%d] = %d\n", i, array1[i]);
	}

	printf("\n");


	printf("Array 2 after swap\n\n");
	for(int i = 0 ; i < 5 ; i++)
	{
		printf("array1[%d] = %d\n", i, array2[i]);
	}


	return 0;
}


int * Swap (int a_size,int *a,int b_size,int *b)
{
	int temp;

	for(int i = 0 ; i < b_size ; i++)
	{
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}

	return a;
}
