/**************************************************************************************************
 Name        : Question16.c
 Author      : Youssef Nashaat
 Created on	 : Aug 24, 2022
 Description : Assignment 3 - Question 16
 **************************************************************************************************/
#include <stdio.h>

int array[10];
int number_of_elements;

void reverse_array(int *arr);

int main(void)
{
	do{
		printf("Array number of elements? Choose a number between 1 - 10: ");
		fflush(stdout);
		scanf("%d", &number_of_elements);
	}

	while(number_of_elements > 10);

	printf("\n");

	for(int i = 0 ; i < number_of_elements ; i++)
	{
		printf("Array[%d]: ", i);
		fflush(stdout);
		scanf("%d", &array[i]);
	}

	printf("\n");

	reverse_array(array);

	for(int i = 0 ; i < number_of_elements ; i++)
	{
		printf("Array[%d] = %d\n", i, array[i]);
	}


	return 0;
}


void reverse_array(int *arr)
{
	int i = 0, temp;

	while(i < number_of_elements / 2)
	{
		temp = arr[i];
		arr[i] = arr[number_of_elements - 1 - i];
		arr[number_of_elements - 1 - i] = temp;

		i++;
	}


}
